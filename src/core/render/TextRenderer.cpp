#include "TextRenderer.h"

namespace Mystic {

void TextRenderer::Init() {
    if (FT_Init_FreeType(&ft)) {
        MYSTIC_ERROR("Could not init FreeType Library");
    }
    if (FT_New_Face(ft, "fonts/Antonio-Bold.ttf", 0, &face)) {
        MYSTIC_ERROR("Failed to load font");
    }
    FT_Set_Pixel_Sizes(face, 0, 48);
    populateCharacters();
    FT_Done_Face(face);
    FT_Done_FreeType(ft);
}

void TextRenderer::BeginBatch() {
}

void TextRenderer::Draw(glm::vec2 position, const std::string& text, Color color) {
}

void TextRenderer::EndBatch() {
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
}

}  // namespace Mystic