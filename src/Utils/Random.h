#pragma once

#include <random>
#include <stdexcept>

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

        template <typename Container>
        static auto random_element(const Container &container) -> decltype(container.front()) {
            auto size = container.size();
            if (size == 0)
                throw std::logic_error("Container is empty");
            std::uniform_int_distribution<size_t> dist(0, size - 1);
            return container[dist(get_engine())];
        }

        template<typename T, std::size_t N>
        static T& random_element(T (&arr)[N]) {
            std::uniform_int_distribution<std::size_t> dist(0, N - 1);
            return arr[dist(get_engine())];
        }
    };

}

