#ifndef BUFFER_H
#define BUFFER_H
#include <vector>

#include "../Debug.h"

namespace Mystic {
struct VertexBufferElement
{
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int GetSizeOfType(unsigned int type)
    {
        switch (type)
        {
            case GL_FLOAT         : return sizeof(GLfloat);
            case GL_UNSIGNED_INT  : return sizeof(GLuint);
            case GL_UNSIGNED_BYTE : return sizeof(GLbyte);
        }
        ASSERT(false);
        return 0;
    }
};

class VertexBufferLayout
{
    private:
        unsigned int m_Stride;
        std::vector<VertexBufferElement> m_Elements;

    public:
        VertexBufferLayout() :
            m_Stride(0) { }

        void AddFloat(unsigned int count)        { push(GL_FLOAT, count, GL_FALSE);        }
        void AddUnsignedInt(unsigned int count)  { push(GL_UNSIGNED_INT, count, GL_FALSE); }
        void AddUnsignedByte(unsigned int count) { push(GL_UNSIGNED_BYTE, count, GL_TRUE); }

        inline const std::vector<VertexBufferElement> GetElements() const { return m_Elements; };
        inline unsigned int GetStride() const { return m_Stride; };

    private:
        void push(unsigned int type, unsigned int count, unsigned char normalized)
        {
            struct VertexBufferElement vbe = {type, count, normalized};
            m_Elements.push_back(vbe);
            m_Stride += count * VertexBufferElement::GetSizeOfType(type);
        };
};

struct IndexBuffer {
   private:
    unsigned int m_renderId = 0;
    unsigned int m_count;
    unsigned int *m_indices;
   public:
    IndexBuffer() { }
    IndexBuffer(unsigned int* indices, unsigned int count);
    ~IndexBuffer();
    void Bind() const;
    void Unbind() const;
    void Create();
    void Destroy() const;
    inline unsigned int GetCount() const { return m_count; }
    inline unsigned int GetRenderId() const { return m_renderId; }
};

struct VertexBuffer {
   private:
    unsigned int m_renderId;

   public:
    VertexBuffer() { }
    VertexBuffer(const void* data, unsigned int size);
    VertexBuffer(const void* data, unsigned int size, int glDrawType);
    ~VertexBuffer();
    void Bind() const;
    void Unbind() const;
    void Create() const;
    void Destroy() const;
    inline unsigned int GetRenderId() const { return m_renderId; }
};

struct VertexArray {
   private:
    unsigned int m_renderId;

   public:
    //VertexArray() { };
    VertexArray(bool init);
    ~VertexArray();
    void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
    void Bind() const;
    void Unbind() const;
    void Create() const;
    void Destroy() const;
    inline unsigned int GetRenderId() const { return m_renderId; }
   
};

class BufferManager {
    static void DestoryVertexArray(VertexArray& va);
    static void DestoryIndexBuffer(IndexBuffer& ib);
    static void DestoryVertexBuffer(VertexBuffer& vb);
};

}  // namespace Mystic

#endif