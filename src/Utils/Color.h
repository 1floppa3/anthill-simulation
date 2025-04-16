#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iomanip>
#include <string>

namespace Utils {

    inline std::string color_to_hex(const sf::Color& color) {
        std::stringstream ss;
        ss << '#'
           << std::uppercase << std::setfill('0')
           << std::setw(2) << std::hex << static_cast<int>(color.r)
           << std::setw(2) << std::hex << static_cast<int>(color.g)
           << std::setw(2) << std::hex << static_cast<int>(color.b);
        return ss.str();
    }

    inline sf::Color hex_to_color(const std::string& hex) {
        std::string value = hex;
        if (!value.empty() && value[0] == '#')
            value = value.substr(1);
        if (value.length() != 6 && value.length() != 8) {
            throw std::invalid_argument("Invalid hex color format. Use '#RRGGBB' or '#RRGGBBAA'.");
        }

        const unsigned long hex_value = std::stoul(value, nullptr, 16);

        unsigned char r, g, b, a;
        if (value.length() == 6) {
            r = hex_value >> 16 & 0xFF;
            g = hex_value >> 8 & 0xFF;
            b = hex_value & 0xFF;
            a = 255;
        } else { // value.length() == 8
            r = hex_value >> 24 & 0xFF;
            g = hex_value >> 16 & 0xFF;
            b = hex_value >> 8 & 0xFF;
            a = hex_value & 0xFF;
        }
        return {r, g, b, a};
    }

}