#ifndef BUFFER_H
#define BUFFER_H
#include <vector>
#include <iostream>
#include <cstring>
#include "../../Constants.h"

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
    unsigned int m_indices[MAX_INDICES];
    IndexBuffer(const unsigned int initIndices[MAX_INDICES], unsigned int count);
   public:
    IndexBuffer() { }
    // IndexBuffer(unsigned int* indices, unsigned int count);
    ~IndexBuffer();
    static IndexBuffer Create(const unsigned int initIndices[MAX_INDICES], unsigned int count);
    void Bind() const;
    void Unbind() const;
    void Destroy() const;
    void ApplyData() const;
    inline unsigned int GetCount() const { return m_count; }
    inline unsigned int GetRenderId() const { return m_renderId; }
};

struct VertexBuffer {
   private:
    unsigned int m_renderId;
    void* m_data;
    unsigned int m_size;
    unsigned int m_glDrawType;
    VertexBuffer(void* data, unsigned int size);
    VertexBuffer(void* data, unsigned int size, int glDrawType);
   public:
    VertexBuffer() { }
    ~VertexBuffer();
    void UpdateVertexData(void* data, unsigned int size);
    void Bind() const;
    void Unbind() const;
    static VertexBuffer Create(void* data, unsigned int size);
    static VertexBuffer Create(void* data, unsigned int size, int glDrawType);
    void Destroy() const;
    inline unsigned int GetRenderId() const { return m_renderId; }
};

struct VertexArray {
   private:
    unsigned int m_renderId;
    VertexArray(bool createOnGpu);
   public:
    VertexArray();
    ~VertexArray();
    /// @brief DO NOT USE - 
    /// @param vb 
    /// @param layout 
    void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
    void ApplyBufferLayout(const VertexBufferLayout& layout);
    void Bind() const;
    void Unbind() const;
    static VertexArray Create();
    void Destroy() const;
    inline unsigned int GetRenderId() const { return m_renderId; }
   
};

}  // namespace Mystic

#endif