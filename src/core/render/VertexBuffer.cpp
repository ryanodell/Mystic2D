#include "buffer.h"

namespace Mystic {
VertexBuffer::~VertexBuffer() { }

VertexBuffer::VertexBuffer(void* data, unsigned int size)  
    : m_data(data), m_size(size), m_glDrawType(GL_STATIC_DRAW) {
    GLCall(glGenBuffers(1, &m_renderId));
}

VertexBuffer::VertexBuffer(void* data, unsigned int size, int glDrawType)
    : m_data(data), m_size(size), m_glDrawType(glDrawType)  {
    GLCall(glGenBuffers(1, &m_renderId));
}

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

VertexBuffer VertexBuffer::Create(void* data, unsigned int size) {
    return VertexBuffer(data, size);
}

VertexBuffer VertexBuffer::Create(void* data, unsigned int size, int glDrawType) {
    return VertexBuffer(data, size, glDrawType);
}

void VertexBuffer::Destroy() const {
    GLCall(glDeleteBuffers(1, &m_renderId));
}
}  // namespace Mystic