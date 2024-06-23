#include "buffer.h"

namespace Mystic {
VertexBuffer::~VertexBuffer() {
    std::cout << "VB Destructor" << std::endl;
    // GLCall(glDeleteBuffers(1, &m_renderId));
}
void VertexBuffer::Bind() const {
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_renderId));
    GLCall(glBufferData(GL_ARRAY_BUFFER, m_size, m_data, m_glDrawType));
}
void VertexBuffer::Unbind() const {
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

void VertexBuffer::Create() {
    GLCall(glGenBuffers(1, &m_renderId));
    //Bind();
    //GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_renderId));
    // GLCall(glBufferData(GL_ARRAY_BUFFER, m_size, m_data, m_glDrawType));
}
void VertexBuffer::Destroy() const {
    GLCall(glDeleteBuffers(1, &m_renderId));
}
}  // namespace Mystic