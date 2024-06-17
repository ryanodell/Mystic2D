#ifndef SHADER_H
#define SHADER_H
#include <glad.h>
#include <stdio.h>
#include <stdlib.h>
#include <glm.hpp>
#include <unordered_map>
#include <cstring>

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
    void setBool(const char* name, bool value) const
    {         
        glUniform1i(glGetUniformLocation(m_id, name), (int)value); 
    }
    // ------------------------------------------------------------------------
    void setInt(const char* name, int value) const
    { 
        glUniform1i(glGetUniformLocation(m_id, name), value); 
    }
    // ------------------------------------------------------------------------
    void setFloat(const char* name, float value) const
    { 
        glUniform1f(glGetUniformLocation(m_id, name), value); 
    }
    // ------------------------------------------------------------------------
    void setVec2(const char* name, const glm::vec2 &value) const
    { 
        glUniform2fv(glGetUniformLocation(m_id, name), 1, &value[0]); 
    }
    void setVec2(const char* name, float x, float y) const
    { 
        glUniform2f(glGetUniformLocation(m_id, name), x, y); 
    }
    // ------------------------------------------------------------------------
    void setVec3(const char* name, const glm::vec3 &value) const
    { 
        glUniform3fv(glGetUniformLocation(m_id, name), 1, &value[0]); 
    }
    void setVec3(const char* name, float x, float y, float z) const
    { 
        glUniform3f(glGetUniformLocation(m_id, name), x, y, z); 
    }
    // ------------------------------------------------------------------------
    void setVec4(const char* name, const glm::vec4 &value) const
    { 
        glUniform4fv(glGetUniformLocation(m_id, name), 1, &value[0]); 
    }
    void setVec4(const char* name, float x, float y, float z, float w) 
    { 
        glUniform4f(glGetUniformLocation(m_id, name), x, y, z, w); 
    }
    // ------------------------------------------------------------------------
    void setMat2(const char* name, const glm::mat2 &mat) const
    {
        glUniformMatrix2fv(glGetUniformLocation(m_id, name), 1, GL_FALSE, &mat[0][0]);
    }
    // ------------------------------------------------------------------------
    void setMat3(const char* name, const glm::mat3 &mat) const
    {
        glUniformMatrix3fv(glGetUniformLocation(m_id, name), 1, GL_FALSE, &mat[0][0]);
    }
    // ------------------------------------------------------------------------
    void setMat4(const char* name, const glm::mat4 &mat) const
    {
        glUniformMatrix4fv(glGetUniformLocation(m_id, name), 1, GL_FALSE, &mat[0][0]);
        // auto test = glGetUniformLocation(m_id, "");
    }
private:
    unsigned int m_id;
    std::unordered_map<const char*, unsigned int> m_uniformCache;
private:
    unsigned int getUniformLocationFromCache(const char* uniformName);
    static unsigned int loadShaderFromSource(const char* shaderSource);
    static unsigned int compileShader(const char* buf, int shaderType);
    static unsigned int linkProgram(unsigned int vertexShader, unsigned int fragmentShader);
    
};

}

#endif