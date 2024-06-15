#ifndef SHADER_H
#define SHADER_H
#include <glad.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace Mystic {
// static const char* VERTEX_DEFINITION = "#shader vertex";
// static const char* FRAGMENT_DEFINITION = "#shader fragment";
static const unsigned int MAX_SHADER_CODE_LENGTH = 1024;
static const unsigned int SHADER_LOG_LENGTH = 512;
class Shader {
public:
    Shader(unsigned int id) {
        m_id = id;
    }
    ~Shader() {
        glDeleteProgram(m_id);
    }
    inline unsigned int GetId() const {
        return m_id;
    }
    inline void Use() const {
        glUseProgram(m_id);
    }
    static Shader* LoadFromFile(const char* fileName);
private:
    unsigned int m_id;
    static unsigned int loadShaderFromSource(const char* shaderSource);
    static unsigned int compileShader(const char* buf, int shaderType);
    static unsigned int linkProgram(unsigned int vertexShader, unsigned int fragmentShader);
};

}

#endif