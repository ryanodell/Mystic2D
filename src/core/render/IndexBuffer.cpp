#include "buffer.h"

namespace Mystic {
IndexBuffer::IndexBuffer(unsigned int *indices, unsigned int count)
    : m_indices(indices), m_count(count) {
    // GLCall(glGenBuffers(1, &m_renderId));
    // GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderId));
    // GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW));
}
IndexBuffer::~IndexBuffer() {
    std::cout << "IB Destructor"<< std::endl;
    // GLCall(glDeleteBuffers(1, &m_renderId));
}
void IndexBuffer::Bind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderId));
}
void IndexBuffer::Unbind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
void IndexBuffer::Create() {
    GLCall(glGenBuffers(1, &m_renderId));    
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderId));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_indices), m_indices, GL_STATIC_DRAW));
}
void IndexBuffer::Destroy() const {
    GLCall(glDeleteBuffers(1, &m_renderId));
}
}  // namespace Mystic
