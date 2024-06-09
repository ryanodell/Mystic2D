#include "../../pch.h"

namespace mystic {

struct buffer_element {
    int vertexAttribPointerType;
    int count;
    bool normalized;
};

class buffer_layout {
public:

private:
    std::vector<buffer_element> m_elemetns;
};

struct vertex_array {
public:
    void bind();
    void unbind();
private:
    int m_bufferId;
};

}