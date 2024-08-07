#ifndef TEXTURE_H
#define TEXTURE_H
#include "stb_image.h"
#include <glad.h>
#include <cstdio>
#include "../Debug.h"

namespace Mystic {

class Texture {
    public:
        Texture() { }
        Texture(unsigned int id) {
            m_id = id;
        }
        Texture(unsigned int id, int width, int height) {
            m_id = id;
            m_width = width;
            m_height = height;
        }
        ~Texture() {
            GLCall(glDeleteTextures(1, &m_id));
        }
        inline unsigned int GetId() const {
            return m_id;
        }
        inline void Use() const {
            GLCall(glBindTexture(GL_TEXTURE_2D, m_id));
        }
        static Texture* LoadFromFile(const char* fileName);
        int GetWidth() const {
            return m_width;
        }
        int GetHeight() const {
            return m_height;
        }
    private:
        unsigned int m_id;
        int m_width, m_height, nrChannels;
    };
}



#endif