#include "renderer.h"

namespace Mystic {
void Renderer::Init() {
    m_va = VertexArray::Create();
    m_vb = VertexBuffer::Create(m_vertices, sizeof(m_vertices), GL_DYNAMIC_DRAW);
    populateIndexBuffer();
    m_ib = IndexBuffer::Create(m_indices, MAX_INDICES);
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
    if (FT_Init_FreeType(&ft)) {
        MYSTIC_ERROR("Could not init FreeType Library");
    }
    if (FT_New_Face(ft, "fonts/Antonio-Bold.ttf", 0, &face)) {
        MYSTIC_ERROR("Failed to load font");
    }
    FT_Set_Pixel_Sizes(face, 0, 48);
    populateCharacters();
    // Temporary, test loading a character:
    //  if(FT_Load_Char(face, 'X', FT_LOAD_RENDER)) {
    //      MYSTIC_ERROR("Failed to load character 'X' from font face");
    //  }
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
void Renderer::BeginBatch(Shader* shader, glm::mat4 transform) {
    m_shader = shader;
    m_mvp = transform;
    m_flushCount = 0;
}
void Renderer::Draw(glm::vec2 position, Texture* texture, Rectangle* srcRect, Color color) {
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
    // unsigned int offset = m_spritePointer * (8 * 4);  // Assuming each sprite uses 8 floats & 4 enties
    unsigned int offset = m_spritePointer * VERT_QUAD_SIZE;  // Assuming each sprite uses 8 floats & 4 enties
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
    if (m_spritePointer > MAX_OBJECTS) {
        flush();
    }
}
void Renderer::EndBatch() {
    flush();
    // m_spritePointer--;
    //  m_vb.UpdateVertexData(m_vertices, sizeof(m_vertices));
    //  shader->Use();
    //  shader->setMat4("transform", m_mvp);
    //  m_va.Bind();
    //  // GLCall(glDrawElements(GL_TRIANGLES, m_spritePointer * IND_QUAD_SIZE, GL_UNSIGNED_INT, 0));
    //  GLCall(glDrawElements(GL_TRIANGLES, MAX_INDICES, GL_UNSIGNED_INT, 0));
    //  m_spritePointer = 0;
}
void Renderer::SetClearColor(Color color) const {
    glm::vec4 clearColor = GetColorVec4(color);
    GLCall(glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a));
}

void Renderer::populateIndexBuffer() {
    for (int i = 0; i < MAX_OBJECTS; i++) {
        int indexStartIndex = i * 6;
        m_indices[indexStartIndex] = i * 4;
        m_indices[indexStartIndex + 1] = i * 4 + 1;
        m_indices[indexStartIndex + 2] = i * 4 + 3;
        m_indices[indexStartIndex + 3] = i * 4 + 1;
        m_indices[indexStartIndex + 4] = i * 4 + 2;
        m_indices[indexStartIndex + 5] = i * 4 + 3;
    }
}
void Renderer::flush() {
    // m_spritePointer--;
    m_vb.UpdateVertexData(m_vertices, sizeof(m_vertices));
    m_shader->Use();
    m_shader->setMat4("transform", m_mvp);
    m_va.Bind();
    // GLCall(glDrawElements(GL_TRIANGLES, m_spritePointer * IND_QUAD_SIZE, GL_UNSIGNED_INT, 0));
    GLCall(glDrawElements(GL_TRIANGLES, MAX_INDICES, GL_UNSIGNED_INT, 0));

    std::fill(std::begin(m_vertices), std::end(m_vertices), 0.0f);

    m_spritePointer = 0;
    m_flushCount++;
}
void Renderer::populateCharacters() {
    // disable byte alignment restriction
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    // c++, heh..
    for (unsigned char c = 0; c < 128; c++) {
        if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
            MYSTIC_WARN("Failed to load " + std::string(1, static_cast<char>(c)) + " char");
        }

        unsigned int texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RED,
            face->glyph->bitmap.width,
            face->glyph->bitmap.rows,
            0,
            GL_RED,
            GL_UNSIGNED_BYTE,
            face->glyph->bitmap.buffer);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        Character character = {
            texture,
            glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
            glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
            face->glyph->advance.x};
        m_characters.insert(std::pair<char, Character>(c, character));
    }
}
}  // namespace Mystic