#ifndef SHADER_H
#define SHADER_H
#include <glad.h>
#include <stdio.h>
#include <stdlib.h>
#include <glm.hpp>
#include <unordered_map>
#include <cstring>
#include <string>
#include "../Debug.h"

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
    void SetBool(const std::string &name, bool value) const {
        glUniform1i(getUniformLocationFromCache(name), (int)value); 
    }
    void setInt(const std::string &name, int value) const { 
        glUniform1i(getUniformLocationFromCache(name), value); 
    }
    void setFloat(const std::string &name, float value) const { 
        glUniform1f(getUniformLocationFromCache(name), value); 
    }
    void setVec2(const std::string &name, const glm::vec2 &value) const { 
        glUniform2fv(getUniformLocationFromCache(name), 1, &value[0]); 
    }
    void setVec2(const std::string &name, float x, float y) const { 
        glUniform2f(getUniformLocationFromCache(name), x, y); 
    }
    void setVec3(const std::string &name, const glm::vec3 &value) const { 
        glUniform3fv(getUniformLocationFromCache(name), 1, &value[0]); 
    }
    void setVec3(const std::string &name, float x, float y, float z) const { 
        glUniform3f(getUniformLocationFromCache(name), x, y, z); 
    }
    void setVec4(const std::string &name, const glm::vec4 &value) const { 
        glUniform4fv(getUniformLocationFromCache(name), 1, &value[0]); 
    }
    void setVec4(const std::string &name, float x, float y, float z, float w) { 
        glUniform4f(getUniformLocationFromCache(name), x, y, z, w); 
    }
    void setMat2(const std::string &name, const glm::mat2 &mat) const {
        glUniformMatrix2fv(getUniformLocationFromCache(name), 1, GL_FALSE, &mat[0][0]);
    }
    void setMat3(const std::string &name, const glm::mat3 &mat) const {
        glUniformMatrix3fv(getUniformLocationFromCache(name), 1, GL_FALSE, &mat[0][0]);
    }
    void setMat4(const std::string &name, const glm::mat4 &mat) const {
        glUniformMatrix4fv(getUniformLocationFromCache(name), 1, GL_FALSE, &mat[0][0]);
    }
private:
    unsigned int m_id;
    mutable std::unordered_map<std::string, unsigned int> m_uniformCache;
private:
    unsigned int getUniformLocationFromCache(const std::string& uniformName) const;
    static unsigned int loadShaderFromSource(const char* shaderSource);
    static unsigned int compileShader(const char* buf, int shaderType);
    static unsigned int linkProgram(unsigned int vertexShader, unsigned int fragmentShader);
    
};

}

#endif