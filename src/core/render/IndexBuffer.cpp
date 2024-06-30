#include "buffer.h"

namespace Mystic {
IndexBuffer::IndexBuffer(const unsigned int initIndices[MAX_INDICES], unsigned int count) : m_count(count) {
    std::memcpy(m_indices, initIndices, MAX_INDICES * sizeof(unsigned int));
    GLCall(glGenBuffers(1, &m_renderId));
}
IndexBuffer::~IndexBuffer() { }

IndexBuffer IndexBuffer::Create(const unsigned int initIndices[MAX_INDICES], unsigned int count) {
    return IndexBuffer(initIndices, count);
}
void IndexBuffer::Bind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderId));
}
void IndexBuffer::Unbind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
void IndexBuffer::ApplyData() const {
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_indices), m_indices, GL_DYNAMIC_DRAW));
}
void IndexBuffer::Destroy() const {
    GLCall(glDeleteBuffers(1, &m_renderId));
}
}  // namespace Mystic
