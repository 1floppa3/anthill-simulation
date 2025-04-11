#include <valarray>
#include "FoodPoint.h"

FoodPoint::FoodPoint(int x, int y, int capacity): x(x), y(y), capacity(capacity) {}

bool FoodPoint::compare_coords(int x, int y) {
    return std::abs(this->x - x) < 40 && std::abs(this->y - y) < 40;
}

bool FoodPoint::is_empty() {
    return capacity <= 0;
}

void FoodPoint::take_food() {
    --capacity;
}