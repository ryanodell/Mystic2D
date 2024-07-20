#include "TextRenderer.h"

namespace Mystic {

void TextRenderer::Init() {
    m_shader = Mystic::Shader::LoadFromFile("shaders/text_1.glsl");
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(900.0f), 0.0f, static_cast<float>(600.0f));
    m_shader->Use();
    glUniformMatrix4fv(glGetUniformLocation(m_shader->GetId(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
    if (FT_Init_FreeType(&ft)) {
        MYSTIC_ERROR("Could not init FreeType Library");
    }
    if (FT_New_Face(ft, "fonts/SDS_8x8.ttf", 0, &face)) {
        MYSTIC_ERROR("Failed to load font");
    }
    FT_Set_Pixel_Sizes(face, 0, 48);
    populateCharacters();
    FT_Done_Face(face);
    FT_Done_FreeType(ft);

    glGenVertexArrays(1, &m_va);
    glGenBuffers(1, &m_vb);
    glBindVertexArray(m_va);
    glBindBuffer(GL_ARRAY_BUFFER, m_vb);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void TextRenderer::Draw(glm::vec2 position, const std::string& text, float scale, Color color) {
    glm::vec4 vColor = Mystic::GetColorVec4(color);
    m_shader->Use();
    glUniform3f(glGetUniformLocation(m_shader->GetId(), "textColor"), vColor.x, vColor.y, vColor.z);
    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(m_va);

    // iterate through all characters
    std::string::const_iterator c;
    for (c = text.begin(); c != text.end(); c++) 
    {
        Character ch = m_characters[*c];

        float xpos = position.x + ch.Bearing.x * scale;
        float ypos = position.y - (ch.Size.y - ch.Bearing.y) * scale;

        float w = ch.Size.x * scale;
        float h = ch.Size.y * scale;
        // update VBO for each character
        float vertices[6][4] = {
            { xpos,     ypos + h,   0.0f, 0.0f },            
            { xpos,     ypos,       0.0f, 1.0f },
            { xpos + w, ypos,       1.0f, 1.0f },

            { xpos,     ypos + h,   0.0f, 0.0f },
            { xpos + w, ypos,       1.0f, 1.0f },
            { xpos + w, ypos + h,   1.0f, 0.0f }           
        };
        // render glyph texture over quad
        glBindTexture(GL_TEXTURE_2D, ch.TextureId);
        // update content of VBO memory
        glBindBuffer(GL_ARRAY_BUFFER, m_vb);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // be sure to use glBufferSubData and not glBufferData

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        // render quad
        glDrawArrays(GL_TRIANGLES, 0, 6);
        // now advance cursors for next glyph (note that advance is number of 1/64 pixels)
        position.x += (ch.Advance >> 6) * scale; // bitshift by 6 to get value in pixels (2^6 = 64 (divide amount of 1/64th pixels by 64 to get amount of pixels))
    }
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void TextRenderer::populateCharacters() {
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
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

}  // namespace Mystic