#ifndef TEXT_RENDERER_H
#define TEXT_RENDERER_H
#include <algorithm>

#include "../../pch.h"
#include "../../vendor/FREETYPE/ft2build.h"
#include "../Debug.h"
#include "../Geometry.h"
#include "../Utils.h"
#include "../content/Shader.h"
#include "../content/Texture.h"
#include "Buffer.h"
#include FT_FREETYPE_H
#include <map>

namespace Mystic {

class TextRenderer {
   public:
    TextRenderer() {}
    ~TextRenderer() {}
    void Init();
    void BeginBatch();
    void Draw(glm::vec2 position, const std::string& text, Color color);
    void EndBatch();

   private:
    VertexArray m_va;
    VertexBuffer m_vb;
    IndexBuffer m_ib;
    FT_Library ft;
    FT_Face face;
    std::map<char, Character> m_characters;

   private:
    void populateCharacters();
};

}  // namespace Mystic

#endif