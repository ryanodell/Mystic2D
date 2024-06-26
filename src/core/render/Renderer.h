#ifndef RENDERER_H
#define RENDERER_H
#include "../../pch.h"
#include "../Debug.h"
#include "../content/Shader.h"
#include "Buffer.h"
#include "../Utils.h"

namespace Mystic {

/// @brief NOTE: NOT IN USE - JUST USING RENDERER AND DOING INNEFICIENT DRAWING FOR NOW
class Renderer {
   public:
    Renderer() {};
    void Clear() const;
    void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
    void SetClearColor(Color color) const;
   private:
    float m_vertices[MAX_VERTICES];
    float m_indices[MAX_INDICES];
};
}  // namespace Mystic
#endif