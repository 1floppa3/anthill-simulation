#include "Random.h"

namespace Utils {

    std::mt19937& Random::get_engine() {
        static std::random_device rd;
        static std::mt19937 engine(rd());
        return engine;
    }

}