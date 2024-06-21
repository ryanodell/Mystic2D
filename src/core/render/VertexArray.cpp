#include "Buffer.h"

namespace Mystic {

// VertexArray::VertexArray() {
//     int test =5;
//     GLCall(glGenVertexArrays(1, &m_renderId));
//     //GLCall(glGenVertexArrays(1, &m_renderId));
// }

VertexArray::VertexArray(bool init) {
    // if(init == true) {
    //     GLCall(glGenVertexArrays(1, &m_renderId));
    // }
}

VertexArray::~VertexArray() {
    // std::cout << "VA Destructor" << std::endl;
    // GLCall(glDeleteVertexArrays(1, &m_renderId));
}
void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) {
    Bind();
    vb.Bind();
    const std::vector<VertexBufferElement> elements = layout.GetElements();
    unsigned int offset = 0;
    for (unsigned int i = 0; i < elements.size(); i++) {
        const VertexBufferElement element = elements[i];
        GLCall(glEnableVertexAttribArray(i));
        GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized,
                                     layout.GetStride(), INT2VOIDP(offset)));
        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
    }
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
void VertexArray::Bind() const {
    GLCall(glBindVertexArray(m_renderId));
}
void VertexArray::Unbind() const {
    GLCall(glBindVertexArray(0));
}
void VertexArray::Create() {
    GLCall(glGenVertexArrays(1, &m_renderId));
}
void VertexArray::Destroy() const {
    GLCall(glDeleteVertexArrays(1, &m_renderId));
}
}  // namespace Mystic