#include "buffer.h"

namespace Mystic {
VertexBuffer::VertexBuffer(void* data, unsigned int size) : m_data(data), m_size(size), m_glDrawType(GL_STATIC_DRAW) {
    // GLCall(glGenBuffers(1, &m_renderId));
    // GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_renderId));
    // GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}
VertexBuffer::VertexBuffer(void* data, unsigned int size, int glDrawType)  : m_data(data), m_size(size), m_glDrawType(glDrawType){
    // GLCall(glGenBuffers(1, &m_renderId));
    // GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_renderId));
    // GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, glDrawType));
}
VertexBuffer::~VertexBuffer() {
    std::cout << "VB Destructor" << std::endl;
    // GLCall(glDeleteBuffers(1, &m_renderId));
}
void VertexBuffer::Bind() const {
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_renderId));
}
void VertexBuffer::Unbind() const {
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

void VertexBuffer::Create() {
    GLCall(glGenBuffers(1, &m_renderId));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_renderId));
    GLCall(glBufferData(GL_ARRAY_BUFFER, m_size, m_data, m_glDrawType));
}
void VertexBuffer::Destroy() const {
    GLCall(glDeleteBuffers(1, &m_renderId));
}
}  // namespace Mystic