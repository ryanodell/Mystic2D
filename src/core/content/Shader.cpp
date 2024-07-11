#include "Shader.h"

namespace Mystic {

    Shader *Shader::LoadFromFile(const char *fileName) {
        
        FILE *file = fopen(fileName, "rb");
        if (file == NULL) {
            MYSTIC_CORE_ERROR("Could not load shader file");
            //fprintf(stderr, "Could not load shader file: %s\n", fileName);
            return nullptr;
        }

        fseek(file, 0, SEEK_END);
        size_t fileSize = ftell(file);
        fseek(file, 0, SEEK_SET);

        char *content = (char *)malloc(fileSize + 1);
        if (content != NULL) {
            size_t bytesRead = fread(content, 1, fileSize, file);

            if (ferror(file)) {
                MYSTIC_CORE_ERROR("Error Reading Shader file");
                // fprintf(stderr, "Error reading file\n");
                free(content);
                return nullptr;
            }

            content[bytesRead] = '\0';

            if (bytesRead < fileSize) {
                // fprintf(stderr, "There was an error reading contents of the file\n");
                MYSTIC_CORE_ERROR("There was an error reading contents of the file");
                free(content);
                return nullptr;
            } else {
                unsigned int shaderId = Shader::loadShaderFromSource(content);
                free(content);
                if(shaderId > 0) {
                    return new Shader(shaderId);
                }
            }
        }
        return nullptr;
    }
//Test
    unsigned int Shader::getUniformLocationFromCache(const std::string& uniformName) const {        
        auto it = m_uniformCache.find(uniformName);
        if(it != m_uniformCache.end()) {
            return it->second;
        }
        GLCall(unsigned int result = glGetUniformLocation(m_id, uniformName.c_str()));
        m_uniformCache[uniformName] = result;
        return result;
    }

    unsigned int Shader::loadShaderFromSource(const char *shaderSource)
    {
        //size_t sourceCodeLength = strlen(shaderSource);
        char vertexShaderCode[MAX_SHADER_CODE_LENGTH];
        char fragmentShaderCode[MAX_SHADER_CODE_LENGTH];

        const char *vertexStart = strstr(shaderSource, VERTEX_DEFINITION);
        const char *fragmentStart = strstr(shaderSource, FRAGMENT_DEFINITION);
        if(vertexStart == NULL || fragmentStart == NULL) {
            MYSTIC_CORE_ERROR("Vertex and or Fragment shader(s) not properly defined.");
            return -1;
        } 

        size_t vertexShaderLength = fragmentStart - (vertexStart + strlen(VERTEX_DEFINITION));    
        strncpy(vertexShaderCode, vertexStart + strlen(VERTEX_DEFINITION), vertexShaderLength);    
        vertexShaderCode[vertexShaderLength] = '\0';

        size_t fragmentShaderLength = strlen(fragmentStart + strlen(FRAGMENT_DEFINITION));
        strncpy(fragmentShaderCode, fragmentStart + strlen(FRAGMENT_DEFINITION), fragmentShaderLength);
        fragmentShaderCode[fragmentShaderLength] = '\0';

        unsigned int vertexShader = compileShader(vertexShaderCode, GL_VERTEX_SHADER);
        unsigned int fragmentShader = compileShader(fragmentShaderCode, GL_FRAGMENT_SHADER);

        if(vertexShader < 0 || fragmentShader < 0) {
            MYSTIC_CORE_ERROR("Shader(s) failed to compile");
            return -1;
        }
        unsigned int program = linkProgram(vertexShader, fragmentShader);
        if(program < 0) {
            MYSTIC_CORE_ERROR("Shader program failed to link");
            return -1;
        }
        GLCall(glDeleteShader(vertexShader));
        GLCall(glDeleteShader(fragmentShader));
        return program;
    }

    unsigned int Shader::compileShader(const char *buf, int shaderType) {
        GLCall(unsigned int shaderUnit = glCreateShader(shaderType));
        GLCall(glShaderSource(shaderUnit, 1, &buf, NULL));
        GLCall(glCompileShader(shaderUnit));

        int success;
        char infoLog[SHADER_LOG_LENGTH];
        GLCall(glGetShaderiv(shaderUnit, GL_COMPILE_STATUS, &success));
        if(!success) {
            GLCall(glGetShaderInfoLog(shaderUnit, SHADER_LOG_LENGTH, NULL, infoLog));
            //TODO, ARGS DO NOT WORK YET
            MYSTIC_CORE_ERROR("Shader failed to compile");
            //printf("ERROR::SHADER::%s::COMPILATION_FAILED\n", GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT");

            MYSTIC_CORE_ERROR(infoLog);
            //printf("%s\n", infoLog);
            return -1;
        }
        return shaderUnit;
    }

    unsigned int Shader::linkProgram(unsigned int vertexShader, unsigned int fragmentShader) {
        unsigned int shaderProgram = glCreateProgram();
        GLCall(glAttachShader(shaderProgram, vertexShader));
        GLCall(glAttachShader(shaderProgram, fragmentShader));
        GLCall(glLinkProgram(shaderProgram));
        int success;
        char infoLog[SHADER_LOG_LENGTH];
        GLCall(glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success));
        if(!success) {
            GLCall(glGetProgramInfoLog(shaderProgram, SHADER_LOG_LENGTH, NULL, infoLog));
            MYSTIC_CORE_ERROR("Failed to link program");
            MYSTIC_CORE_ERROR(infoLog);
            // printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n");
            // printf("%s\n", infoLog);
            return -1;
        }
        return shaderProgram;
    }
}