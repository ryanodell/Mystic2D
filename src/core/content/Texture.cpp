#include "Texture.h"

namespace Mystic {
    Texture *Texture::LoadFromFile(const char *fileName) {
        int width, height, nrChanels;
        stbi_set_flip_vertically_on_load(true);
        //4 = STBI_ALPHA Thingy
        unsigned char* data = stbi_load(fileName, &width, &height, &nrChanels, 4);
        if(!data) {
            printf("Failed to load texture: %s\n", fileName);
            return nullptr;
        }
        unsigned int textureId;
        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);

        GLenum format;
        if(nrChanels == 1) {
            format = GL_RED;
        } else if (nrChanels == 3) {
            format = GL_RGB;
        } else if (nrChanels == 4) {
            format = GL_RGBA;
        } else {
            format = GL_RGB;
        }
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        stbi_image_free(data);
        return new Texture(textureId, width, height);    
    }
}