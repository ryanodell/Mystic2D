#include "renderer.h"

namespace Mystic{
void Renderer::Clear() const {
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
}
void Renderer::Draw(const VertexArray& va, const IndexBuffer* ib, const Shader& shader) const {
    shader.Use();
    va.Bind();

    //TODO!!!! I SHOULD BE ABLE TO DO ib.Bind() and ib.GetCount()!! Need to investigate why
    ib->Bind();
    //auto test = ib.GetCount();

    glDrawElements(GL_TRIANGLES, ib->GetCount(), GL_UNSIGNED_INT, nullptr);
    //GLCall(glDrawElements(GL_TRIANGLES, ib->GetCount(), GL_UNSIGNED_INT, nullptr));
    //ib.Bind();
    //GLCall( glDrawElements(GL_TRIANGLES, ib->GetCount(), GL_UNSIGNED_INT, nullptr) );
}
}  // namespace Mystic