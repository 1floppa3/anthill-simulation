#pragma once

#include <random>

namespace Utils {

    class Random {
        static std::mt19937& get_engine();
    public:
        // Range: [0, max-1] for integral types
        template<typename T>
        static std::enable_if_t<std::is_integral_v<T>, T> random(T max) {
            return random(static_cast<T>(0), max);
        }

        // Range: [0, max) for floating point types
        template<typename T>
        static std::enable_if_t<std::is_floating_point_v<T>, T> random(T max) {
            return random(static_cast<T>(0), max);
        }

        // Range: [min, max-1] for integral types
        template<typename T>
        static std::enable_if_t<std::is_integral_v<T>, T> random(T min, T max) {
            std::uniform_int_distribution<T> dist(min, max - 1);
            return dist(get_engine());
        }

        // Range: [min, max) for floating point types
        template<typename T>
        static std::enable_if_t<std::is_floating_point_v<T>, T> random(T min, T max) {
            std::uniform_real_distribution<T> dist(min, max);
            return dist(get_engine());
        }
    };

}

