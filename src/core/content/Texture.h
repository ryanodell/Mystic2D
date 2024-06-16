#ifndef TEXTURE_H
#define TEXTURE_H
#include <glad.h>

namespace Mystic {

class Texture {
    public:
        Texture(unsigned int id) {
            m_id = id;
        }
        Texture(unsigned int id, int width, int height) {
            m_id = id;
            m_width = width;
            m_height = height;
        }
        ~Texture() {
            glDeleteTextures(1, &m_id);
        }
        inline unsigned int GetId() const {
            return m_id;
        }
        inline void Use() const {
            glBindTexture(GL_TEXTURE_2D, m_id);
        }
        static Texture* LoadFromFile(const char* fileName);
        // void SetWidth(int width) {
        //     m_width = width;
        // }
        // void SetHeight(int height) {
        //     m_height = height;
        // }
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