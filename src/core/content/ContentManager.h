#ifndef CONTENTMANAGER_H
#define CONTENTMANAGER_H

// #include "Texture.h"
// #include "Shader.h"
// #include <string>
// #include <unordered_map>
// #include <memory>
// #include <stdexcept>

// namespace Mystic {

// class ContentManager {
// public:
//     template<typename T>
//     static T Load(const char* fileName) {
//         T asset;
//         if (asset.LoadFromFile(fileName)) {
//             return asset;
//         } else {
//             throw std::runtime_error("Failed to load asset");
//         }
//     }

// private:

//     std::unordered_map<const char*, Texture*> m_internalTextureCache;

//     //std::unordered_map<std::string, std::shared_ptr<T>> contentMap;

// };

// }

#endif

/*
#include <iostream>
#include <string>

// Define the Texture class
class Texture {
public:
    bool LoadFromFile(const char* fileName) {
        // Implementation of loading a texture from a file
        std::cout << "Loading Texture from " << fileName << std::endl;
        // For demonstration purposes, we return true to indicate success
        return true;
    }
};

// Define the Shader class
class Shader {
public:
    bool LoadFromFile(const char* fileName) {
        // Implementation of loading a shader from a file
        std::cout << "Loading Shader from " << fileName << std::endl;
        // For demonstration purposes, we return true to indicate success
        return true;
    }
};

// Define the ContentManager class with a templated Load method
class ContentManager {
public:
    template<typename T>
    static T Load(const char* fileName) {
        T asset;
        if (asset.LoadFromFile(fileName)) {
            return asset;
        } else {
            throw std::runtime_error("Failed to load asset");
        }
    }
};

// Main function demonstrating the usage
int main() {
    try {
        // Load Texture assets
        Texture texture1 = ContentManager::Load<Texture>("pathToTexture1.png");
        Texture texture2 = ContentManager::Load<Texture>("pathToTexture2.png");
        
        // Load Shader asset
        Shader shader = ContentManager::Load<Shader>("pathToShader.glsl");
        
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}



//First:
#include <string>
#include <unordered_map>
#include <memory>
#include <stdexcept>

template<typename T>
class ContentManager {
public:
    std::shared_ptr<T> load(const std::string& id, const std::string& filename) {
        auto it = contentMap.find(id);
        if (it != contentMap.end()) {
            return it->second;
        }

        std::shared_ptr<T> content = std::make_shared<T>();
        if (content->loadFromFile(filename)) {
            contentMap[id] = content;
            return content;
        } else {
            throw std::runtime_error("Failed to load content from file: " + filename);
        }
    }

    std::shared_ptr<T> get(const std::string& id) {
        auto it = contentMap.find(id);
        if (it != contentMap.end()) {
            return it->second;
        } else {
            throw std::runtime_error("Content not found with id: " + id);
        }
    }

private:
    std::unordered_map<std::string, std::shared_ptr<T>> contentMap;
};



*/