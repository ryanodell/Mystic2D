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
    unsigned int m_renderId;
    unsigned int m_count;

   public:
    IndexBuffer(const unsigned int* indices, unsigned int count);
    ~IndexBuffer();
    void Bind() const;
    void Unbind() const;
    inline unsigned int GetCount() const { return m_count; }
};

struct VertexBuffer {
   private:
    unsigned int m_renderId;

   public:
    VertexBuffer(const void* data, unsigned int size);
    VertexBuffer(const void* data, unsigned int size, int glDrawType);
    ~VertexBuffer();
    void Bind() const;
    void Unbind() const;
};

struct VertexArray {
   private:
    unsigned int m_renderId;

   public:
    VertexArray();
    ~VertexArray();
    void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
    void Bind() const;
    void Unbind() const;

   
};

}  // namespace Mystic