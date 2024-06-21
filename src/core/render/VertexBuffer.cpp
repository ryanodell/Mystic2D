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
    std::cout << "VB Destructor" << std::endl;
    GLCall(glDeleteBuffers(1, &m_renderId));
}
void VertexBuffer::Bind() const {
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_renderId));
}
void VertexBuffer::Unbind() const {
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

}