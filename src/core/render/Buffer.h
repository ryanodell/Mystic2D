#include <vector>

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

struct VertexArray {
public:
    void Bind();
    void Unbind();
private:
    int m_bufferId;
};

}