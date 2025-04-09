#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

class TextureManager {
    std::unordered_map<std::string, sf::Texture> textures_;
    TextureManager() = default;
public:
    static TextureManager& instance();
    TextureManager(const TextureManager&) = delete;
    TextureManager& operator=(const TextureManager&) = delete;
    sf::Texture& get(const std::string& filename);
};
