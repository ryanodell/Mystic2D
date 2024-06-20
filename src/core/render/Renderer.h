#ifndef RENDERER_H
#define RENDERER_H
// #include <GLFW/glfw3.h>
// #include <glad.h>
#include "Buffer.h"
#include "../content/Shader.h"
#include "../../pch.h"
#include "../Debug.h"

namespace Mystic {

/// @brief NOTE: NOT IN USE - JUST USING RENDERER AND DOING INNEFICIENT DRAWING FOR NOW
class Renderer {
   public:
    Renderer() { };
    void Clear() const;
    void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};
}  // namespace Mystic
#endif