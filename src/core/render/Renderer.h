#ifndef RENDERER_H
#define RENDERER_H
#include "../../pch.h"
#include "../Debug.h"
#include "../content/Shader.h"
#include "Buffer.h"
#include "../Utils.h"
#include "../Geometry.h"
#include "../content/Texture.h"
#include <algorithm>
// #include "../../vendor/FREETYPE/ft2build.h"
// #include FT_FREETYPE_H  
// #include <map>

namespace Mystic {

/// @brief NOTE: NOT IN USE - JUST USING RENDERER AND DOING INNEFICIENT DRAWING FOR NOW
class Renderer {
   public:
    Renderer() {};
    void Init();
    void Clear() const;
    void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
    void BeginBatch();
    void BeginBatch(Shader* shader, glm::mat4 transform);
    //void Draw(glm::vec2 position, Texture* texture, Rectangle* srcRect = nullptr, Color color);
    void Draw(glm::vec2 position, Texture* texture,  Rectangle* srcRect = nullptr, Color color = COLOR_WHITE);
    void EndBatch();
    void SetClearColor(Color color) const;
    inline int GetFlushCount() const {
        return m_flushCount;
    }
   private:
    float m_vertices[MAX_VERTICES] = { 0.0f };
    unsigned int m_indices[MAX_INDICES] = { 0 };
    VertexArray m_va;
    VertexBuffer m_vb;
    IndexBuffer m_ib;
    Shader* m_shader = nullptr;
    int m_spriteIndex;
    int m_spritePointer = 0;
    int m_flushCount = 0;
    glm::mat4 m_mvp;
    void populateIndexBuffer();
    void flush();
};
}  // namespace Mystic
#endif