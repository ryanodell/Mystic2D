#include "renderer.h"

namespace Mystic {
void Renderer::Init() {
    m_va = VertexArray::Create();
    m_vb = VertexBuffer::Create(m_vertices, sizeof(m_vertices), GL_STATIC_DRAW);
    // We can just set the values of these so they're ready
    for (int i = 0; i < MAX_OBJECTS; i++) {
        incrementIndexBuffer();
    }
    m_ib = IndexBuffer::Create(m_indices, 6);
    // Rese it back to 0 because of the above:
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
// void Renderer::Draw(glm::vec2 position, Texture* texture, Rectangle* srcRect = nullptr, Color color) {
// }
/*
        // Position     //R   //G   //B   //A       //TexCoords
         50.f, 50.0f,    1.0f, 1.0f, 1.0f, 1.0f,    1.0f, 1.0f,   // top right
         50.0f, -50.f,   1.0f, 1.0f, 1.0f, 1.0f,    1.0f, 0.0f,   // bottom right
        -50.0f, -50.0f,  1.0f, 1.0f, 1.0f, 1.0f,    0.0f, 0.0f,   // bottom left
        -50.0f, 50.0f,   1.0f, 1.0f, 1.0f, 1.0f,    0.0f, 1.0f    // top left
*/
void Renderer::Draw(glm::vec2 position, Texture* texture, Shader* shader, Rectangle* srcRect, Color color) {
    Rectangle defaultRect = Rectangle(0.0f, 0.0f, 1.0f, 1.0f);
    float tmpWidth = 50;
    float tmpHeight = 50;
    glm::vec4 spriteColor = GetColorVec4(color);
    if(srcRect == nullptr) {
        srcRect = &defaultRect;
    }
    //Disgusting rework
    //Top right:
    {
        m_vertices[0] = position.x + tmpWidth;
        m_vertices[1] = position.y;
        m_vertices[2] = spriteColor.r;
        m_vertices[3] = spriteColor.g;
        m_vertices[4] = spriteColor.b;
        m_vertices[5] = spriteColor.a;
        m_vertices[6] = 1.0f;
        m_vertices[7] = 1.0f;
    }
    //Bottom right:
    {
        m_vertices[8] = position.x + tmpWidth;
        m_vertices[9] = position.y + tmpHeight;
        m_vertices[10] = spriteColor.r;
        m_vertices[11] = spriteColor.g;
        m_vertices[12] = spriteColor.b;
        m_vertices[13] = spriteColor.a;
        m_vertices[14] = 1.0f;
        m_vertices[15] = 0.0f;
    }
    //Bottom left:
    {
        m_vertices[16] = position.x;
        m_vertices[17] = position.y + tmpHeight;
        m_vertices[18] = spriteColor.r;
        m_vertices[19] = spriteColor.g;
        m_vertices[20] = spriteColor.b;
        m_vertices[21] = spriteColor.a;
        m_vertices[22] = 1.0f;
        m_vertices[23] = 0.0f;
    }
    //Top left:
    {
        m_vertices[24] = position.x;
        m_vertices[25] = position.y;
        m_vertices[26] = spriteColor.r;
        m_vertices[27] = spriteColor.g;
        m_vertices[28] = spriteColor.b;
        m_vertices[29] = spriteColor.a;
        m_vertices[30] = 0.0f;
        m_vertices[31] = 1.0f;
    }

    m_vb.UpdateVertexData(m_vertices, sizeof(m_vertices));

    //Original:
    // X & Y
    // m_vertices[0] = position.x;
    // m_vertices[1] = position.y;
    // // Color
    // m_vertices[2] = spriteColor.r;
    // m_vertices[3] = spriteColor.g;
    // m_vertices[4] = spriteColor.b;
    // m_vertices[5] = spriteColor.a;

    // if (srcRect == nullptr) {
    //     // Tex coords
    //     // Top right
    //     m_vertices[6] = 1.0f;
    //     m_vertices[7] = 1.0f;
    //     // Bottom right
    //     m_vertices[8] = 1.0f;
    //     m_vertices[9] = 0.0f;
    //     // Bottom left
    //     m_vertices[10] = 0.0f;
    //     m_vertices[11] = 0.0f;
    //     // Top left
    //     m_vertices[12] = 0.0f;
    //     m_vertices[13] = 1.0f;
    // } else {
    //     float normalizedTexCoords[] {
    //         /* TOP LEFT  */
    //         srcRect->X / texture->GetWidth(),   // [0]
    //         srcRect->Y / texture->GetHeight(),  // [1]

    //         /* TOP RIGHT */
    //         (srcRect->X + srcRect->W) / texture->GetWidth(),  // [2]
    //         srcRect->Y / texture->GetWidth(),                 // [3]

    //         /* BOTTOM RIGHT */
    //         (srcRect->X + srcRect->W) / texture->GetWidth(),   // [4]
    //         (srcRect->Y + srcRect->H) / texture->GetHeight(),  // [5]

    //         /* BOTTOM LEFT */
    //         srcRect->X / texture->GetWidth(),                 // [6]
    //         (srcRect->Y + srcRect->H) / texture->GetHeight()  // [7]
    //     };
    //     // Tex coords
    //     // Top right
    //     m_vertices[6] = normalizedTexCoords[2];
    //     m_vertices[7] = normalizedTexCoords[3];
    //     // Bottom right
    //     m_vertices[8] = normalizedTexCoords[4];
    //     m_vertices[9] = normalizedTexCoords[5];
    //     // Bottom left
    //     m_vertices[10] = normalizedTexCoords[6];
    //     m_vertices[11] = normalizedTexCoords[7];
    //     // Top left
    //     m_vertices[12] = normalizedTexCoords[0];
    //     m_vertices[13] = normalizedTexCoords[1];
    // }
    // m_vb.UpdateVertexData(m_vertices, sizeof(m_vertices));
    //m_spritePointer++;
}
void Renderer::EndBatch(Shader* shader) {
    shader->Use();
    shader->setMat4("transform", m_mvp);
    m_spritePointer = 0;
    m_va.Bind();
    GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
    // GLCall(glDrawElements(GL_TRIANGLES, m_ib.GetCount(), GL_UNSIGNED_INT, 0));
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