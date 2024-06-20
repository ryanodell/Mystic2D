#include "Buffer.h"

namespace Mystic {

VertexArray::VertexArray() {
    //GLCall(glGenVertexArrays(1, &m_renderId));
}

VertexArray::VertexArray(bool init) {
    if(init == true) {
        GLCall(glGenVertexArrays(1, &m_renderId));
    }
}

VertexArray::~VertexArray() {
    GLCall(glDeleteVertexArrays(1, &m_renderId));
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
}
void VertexArray::Bind() const {
    GLCall(glBindVertexArray(m_renderId));
}
void VertexArray::Unbind() const {
    GLCall(glBindVertexArray(0));
}
}  // namespace Mystic