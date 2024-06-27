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
/*
        // Position     //R   //G   //B   //A       //TexCoords
         50.f, 50.0f,    1.0f, 1.0f, 1.0f, 1.0f,    1.0f, 1.0f,   // top right
         50.0f, -50.f,   1.0f, 1.0f, 1.0f, 1.0f,    1.0f, 0.0f,   // bottom right
        -50.0f, -50.0f,  1.0f, 1.0f, 1.0f, 1.0f,    0.0f, 0.0f,   // bottom left
        -50.0f, 50.0f,   1.0f, 1.0f, 1.0f, 1.0f,    0.0f, 1.0f    // top left
*/
void Renderer::Draw(glm::vec2 position, Texture* texture, Shader* shader, Rectangle* srcRect, Color color) {
    int indexStartIndex = m_spritePointer * 6;
    m_indices[indexStartIndex] = m_spritePointer * 4;
    m_indices[indexStartIndex + 1] = m_spritePointer * 4 + 1;
    m_indices[indexStartIndex + 2] = m_spritePointer * 4 + 3;
    m_indices[indexStartIndex + 3] = m_spritePointer * 4 + 1;
    m_indices[indexStartIndex + 4] = m_spritePointer * 4 + 2;
    m_indices[indexStartIndex + 5] = m_spritePointer * 4 + 3;

    m_spritePointer++;
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