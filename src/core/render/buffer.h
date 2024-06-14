#include <vector>

namespace Mystic {

struct BufferElement {
    int vertexAttribPointerType;
    int count;
    bool normalized;
};

class BufferLayout {
public:

private:
    std::vector<BufferElement> m_elemetns;
};

struct VertexArray {
public:
    void bind();
    void unbind();
private:
    int m_bufferId;
};

}