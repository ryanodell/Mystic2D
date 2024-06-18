#include "buffer.h"

namespace Mystic {
VertexBuffer::VertexBuffer(const void* data, unsigned int size) {
    GLCall(glGenBuffers(1, &m_renderId));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_renderId));
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}
VertexBuffer::VertexBuffer(const void* data, unsigned int size, int glDrawType) {
    GLCall(glGenBuffers(1, &m_renderId));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_renderId));
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, glDrawType));
}
VertexBuffer::~VertexBuffer() {
    GLCall(glDeleteBuffers(1, &m_renderId));
}
void VertexBuffer::Bind() {
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_renderId));
}
void VertexBuffer::Unbind() {
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

}