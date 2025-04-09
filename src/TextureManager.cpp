#include "TextureManager.h"

#include <iostream>

TextureManager& TextureManager::instance() {
    static TextureManager instance;
    return instance;
}

sf::Texture& TextureManager::get(const std::string& filename) {
    auto it = textures_.find(filename);
    if (it != textures_.end())
        return it->second;

    sf::Texture texture;
    if (!texture.loadFromFile(filename))
        std::cerr << "Error loading texture: " << filename << std::endl;
    textures_[filename] = texture;
    return textures_[filename];
}
