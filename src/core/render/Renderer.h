// #include <GLFW/glfw3.h>
// #include <glad.h>
#include "Buffer.h"
#include "../content/Shader.h"
#include "../../pch.h"
#include "../Debug.h"

namespace Mystic {

class Renderer {
   public:
    void Clear() const;
    void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};
}  // namespace Mystic