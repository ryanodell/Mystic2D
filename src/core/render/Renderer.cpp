#include "renderer.h"

namespace Mystic {
void Renderer::Init() {
    m_va = VertexArray::Create();
    m_vb = VertexBuffer::Create(m_vertices, sizeof(m_vertices), GL_STATIC_DRAW);
    for (int i = 0; i < MAX_OBJECTS; i++) {
        incrementIndexBuffer();
    }
    m_ib = IndexBuffer::Create(m_indices, MAX_INDICES);
    // Rese it back to 0. TODO: Clean this up
    m_spritePointer = 0;
    m_va.Bind();
    m_vb.Bind();
    m_ib.Bind();
    m_ib.ApplyData();

    VertexBufferLayout vbLayout;
    vbLayout.AddFloat(2);
    vbLayout.AddFloat(4);
    vbLayout.AddFloat(2);
    m_va.ApplyBufferLayout(vbLayout);

    m_va.Unbind();
    m_vb.Unbind();
    m_ib.Unbind();
}

void Renderer::Clear() const {
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

/// @brief DO NOT USE
/// @param va 
/// @param ib 
/// @param shader 
void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const {
    shader.Use();
    glActiveTexture(GL_TEXTURE0);
    va.Bind();
    // NOTE: can't use ib.GetCount() when batcher is finished..
    GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}
void Renderer::BeginBatch() {
}
void Renderer::BeginBatch(glm::mat4 transform) {
    m_mvp = transform;
}
void Renderer::Draw(glm::vec2 position, Texture* texture, Shader* shader, Rectangle* srcRect, Color color) {
    float texCoord[8];
    float tmpWidth = (srcRect != nullptr) ? srcRect->W : texture->GetWidth();
    float tmpHeight = (srcRect != nullptr) ? srcRect->H : texture->GetHeight();
    glm::vec4 spriteColor = GetColorVec4(color);
    if (srcRect != nullptr) {
        float normalizedTexCoords[]{
            srcRect->X / texture->GetWidth(),                  // [0] Top Left X
            (srcRect->Y + srcRect->H) / texture->GetHeight(),  // [1] Top Left Y
            (srcRect->X + srcRect->W) / texture->GetWidth(),   // [2] Top Right X
            (srcRect->Y + srcRect->H) / texture->GetHeight(),  // [3] Top Right Y
            (srcRect->X + srcRect->W) / texture->GetWidth(),   // [4] Bottom Right X
            srcRect->Y / texture->GetHeight(),                 // [5] Bottom Right Y
            srcRect->X / texture->GetWidth(),                  // [6] Bottom Left X
            srcRect->Y / texture->GetHeight()                  // [7] Bottom Left Y
        };
        // Set the texCoords
        texCoord[0] = normalizedTexCoords[2];
        texCoord[1] = normalizedTexCoords[3];
        texCoord[2] = normalizedTexCoords[4];
        texCoord[3] = normalizedTexCoords[5];
        texCoord[4] = normalizedTexCoords[6];
        texCoord[5] = normalizedTexCoords[7];
        texCoord[6] = normalizedTexCoords[0];
        texCoord[7] = normalizedTexCoords[1];
    } else {
        // Top right
        texCoord[0] = 1.0f;
        texCoord[1] = 1.0f;
        // Bottom right
        texCoord[2] = 1.0f;
        texCoord[3] = 0.0f;
        // Bottom left
        texCoord[4] = 0.0f;
        texCoord[5] = 0.0f;
        // Top left
        texCoord[6] = 0.0f;
        texCoord[7] = 1.0f;
    }
    unsigned int offset = m_spritePointer * (8 * 4); // Assuming each sprite uses 8 floats & 4 enties
    // Top right
    m_vertices[offset + 0] = position.x + tmpWidth;
    m_vertices[offset + 1] = position.y;
    m_vertices[offset + 2] = spriteColor.r;
    m_vertices[offset + 3] = spriteColor.g;
    m_vertices[offset + 4] = spriteColor.b;
    m_vertices[offset + 5] = spriteColor.a;
    m_vertices[offset + 6] = texCoord[0];
    m_vertices[offset + 7] = texCoord[1];

    // Bottom right
    m_vertices[offset + 8] = position.x + tmpWidth;
    m_vertices[offset + 9] = position.y + tmpHeight;
    m_vertices[offset + 10] = spriteColor.r;
    m_vertices[offset + 11] = spriteColor.g;
    m_vertices[offset + 12] = spriteColor.b;
    m_vertices[offset + 13] = spriteColor.a;
    m_vertices[offset + 14] = texCoord[2];
    m_vertices[offset + 15] = texCoord[3];

    // Bottom left
    m_vertices[offset + 16] = position.x;
    m_vertices[offset + 17] = position.y + tmpHeight;
    m_vertices[offset + 18] = spriteColor.r;
    m_vertices[offset + 19] = spriteColor.g;
    m_vertices[offset + 20] = spriteColor.b;
    m_vertices[offset + 21] = spriteColor.a;
    m_vertices[offset + 22] = texCoord[4];
    m_vertices[offset + 23] = texCoord[5];

    // Top left
    m_vertices[offset + 24] = position.x;
    m_vertices[offset + 25] = position.y;
    m_vertices[offset + 26] = spriteColor.r;
    m_vertices[offset + 27] = spriteColor.g;
    m_vertices[offset + 28] = spriteColor.b;
    m_vertices[offset + 29] = spriteColor.a;
    m_vertices[offset + 30] = texCoord[6];
    m_vertices[offset + 31] = texCoord[7];
    m_spritePointer++;
}
void Renderer::EndBatch(Shader* shader) {
    m_vb.UpdateVertexData(m_vertices, sizeof(m_vertices));
    shader->Use();
    shader->setMat4("transform", m_mvp);
    m_va.Bind();
    GLCall(glDrawElements(GL_TRIANGLES, m_spritePointer * IND_SIZE, GL_UNSIGNED_INT, 0));
    m_spritePointer = 0;
}
void Renderer::SetClearColor(Color color) const {
    glm::vec4 clearColor = GetColorVec4(color);
    GLCall(glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a));
}
void Renderer::incrementIndexBuffer() {
    int indexStartIndex = m_spritePointer * 6;
    m_indices[indexStartIndex] = m_spritePointer * 4;
    m_indices[indexStartIndex + 1] = m_spritePointer * 4 + 1;
    m_indices[indexStartIndex + 2] = m_spritePointer * 4 + 3;
    m_indices[indexStartIndex + 3] = m_spritePointer * 4 + 1;
    m_indices[indexStartIndex + 4] = m_spritePointer * 4 + 2;
    m_indices[indexStartIndex + 5] = m_spritePointer * 4 + 3;
    m_spritePointer++;
}
void Renderer::flush() {
}
}  // namespace Mystic