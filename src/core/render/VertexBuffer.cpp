#include "buffer.h"

namespace Mystic {
VertexBuffer::~VertexBuffer() { }

void VertexBuffer::UpdateVertexData(void* data, unsigned int size) {
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_renderId));
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, m_glDrawType));
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