#ifndef SHADER_H
#define SHADER_H
#include <glad.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glm.hpp>

namespace Mystic {
static const char* VERTEX_DEFINITION = "#shader vertex";
static const char* FRAGMENT_DEFINITION = "#shader fragment";
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
    void setBool(const std::string &name, bool value) const
    {         
        glUniform1i(glGetUniformLocation(m_id, name.c_str()), (int)value); 
    }
    // ------------------------------------------------------------------------
    void setInt(const std::string &name, int value) const
    { 
        glUniform1i(glGetUniformLocation(m_id, name.c_str()), value); 
    }
    // ------------------------------------------------------------------------
    void setFloat(const std::string &name, float value) const
    { 
        glUniform1f(glGetUniformLocation(m_id, name.c_str()), value); 
    }
    // ------------------------------------------------------------------------
    void setVec2(const std::string &name, const glm::vec2 &value) const
    { 
        glUniform2fv(glGetUniformLocation(m_id, name.c_str()), 1, &value[0]); 
    }
    void setVec2(const std::string &name, float x, float y) const
    { 
        glUniform2f(glGetUniformLocation(m_id, name.c_str()), x, y); 
    }
    // ------------------------------------------------------------------------
    void setVec3(const std::string &name, const glm::vec3 &value) const
    { 
        glUniform3fv(glGetUniformLocation(m_id, name.c_str()), 1, &value[0]); 
    }
    void setVec3(const std::string &name, float x, float y, float z) const
    { 
        glUniform3f(glGetUniformLocation(m_id, name.c_str()), x, y, z); 
    }
    // ------------------------------------------------------------------------
    void setVec4(const std::string &name, const glm::vec4 &value) const
    { 
        glUniform4fv(glGetUniformLocation(m_id, name.c_str()), 1, &value[0]); 
    }
    void setVec4(const std::string &name, float x, float y, float z, float w) 
    { 
        glUniform4f(glGetUniformLocation(m_id, name.c_str()), x, y, z, w); 
    }
    // ------------------------------------------------------------------------
    void setMat2(const std::string &name, const glm::mat2 &mat) const
    {
        glUniformMatrix2fv(glGetUniformLocation(m_id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
    // ------------------------------------------------------------------------
    void setMat3(const std::string &name, const glm::mat3 &mat) const
    {
        glUniformMatrix3fv(glGetUniformLocation(m_id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
    // ------------------------------------------------------------------------
    void setMat4(const std::string &name, const glm::mat4 &mat) const
    {
        glUniformMatrix4fv(glGetUniformLocation(m_id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
private:
    unsigned int m_id;
    static unsigned int loadShaderFromSource(const char* shaderSource);
    static unsigned int compileShader(const char* buf, int shaderType);
    static unsigned int linkProgram(unsigned int vertexShader, unsigned int fragmentShader);
};

}

#endif