#include <vector>

#include "../Debug.h"

namespace Mystic {

struct BufferElement {
    int VertexAttribPointerType;
    int Count;
    bool Normalized;
};

class BufferLayout {
   public:
   private:
    std::vector<BufferElement> m_elemetns;
};

struct IndexBuffer {
   private:
    unsigned int m_renderId;
    unsigned int m_count;

   public:
    IndexBuffer(const unsigned int* indices, unsigned int count);
    ~IndexBuffer();
    void Bind() const;
    void Unbind() const;
    inline unsigned int GetCount() { return m_count; }
};

struct VertexBuffer {
   private:
    unsigned int m_renderId;

   public:
    VertexBuffer(const void* data, unsigned int size);
    VertexBuffer(const void* data, unsigned int size, int glDrawType);
    ~VertexBuffer();
    void Bind();
    void Unbind();
};

struct VertexArray {
   public:
    void Bind();
    void Unbind();

   private:
    int m_bufferId;
};

}  // namespace Mystic