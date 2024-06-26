#include "renderer.h"

namespace Mystic{
void Renderer::Clear() const {
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
}
void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const {
    shader.Use();
    glActiveTexture(GL_TEXTURE0);
    va.Bind();
    GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}
void Renderer::BeginBatch() {
}
void Renderer::BeginBatch(glm::mat4 transform) {
}
// void Renderer::Draw(glm::vec2 position, Texture* texture, Rectangle* srcRect = nullptr, Color color) {
// }
void Renderer::Draw(glm::vec2 position, Texture* texture, Shader* shader, Rectangle* srcRect, Color color) {
}
void Renderer::EndBatch() {
}
void Renderer::SetClearColor(Color color) const {
    glm::vec4 clearColor = GetColorVec4(color);
    GLCall(glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a));
}
void Renderer::flush() {
}
}  // namespace Mystic