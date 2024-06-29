#ifndef RENDERER_H
#define RENDERER_H
#include "../../pch.h"
#include "../Debug.h"
#include "../content/Shader.h"
#include "Buffer.h"
#include "../Utils.h"
#include "../Geometry.h"
#include "../content/Texture.h"

namespace Mystic {

/// @brief NOTE: NOT IN USE - JUST USING RENDERER AND DOING INNEFICIENT DRAWING FOR NOW
class Renderer {
   public:
    Renderer() {};
    void Clear() const;
    void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
    void BeginBatch();
    void BeginBatch(glm::mat4 transform);
    //void Draw(glm::vec2 position, Texture* texture, Rectangle* srcRect = nullptr, Color color);
    void Draw(glm::vec2 position, Texture* texture, Shader* shader, Rectangle* srcRect = nullptr, Color color = COLOR_WHITE);
    void EndBatch();
    void SetClearColor(Color color) const;
   private:
    void incrementIndexBuffer();
    float m_vertices[MAX_VERTICES];
    float m_indices[MAX_INDICES];
    int m_spriteIndex;
    int m_spritePointer = 0;
    void flush();
};
}  // namespace Mystic
#endif