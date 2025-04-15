#include <algorithm>
#include <iostream>
#include "Store.h"

namespace Model {
    void Model::Store::increase(int val) {
        if (val < 0)
            std::cout << "val must be positive\n";
        supplies = std::min(supplies + val, capacity);
    }

    void Store::decrease(int val) {
        if (val > 0)
            std::cout << "val must be negative\n";
        supplies = std::max(0, supplies + val);
    }

    void Store::update_capacity(int val) {
        supplies = val;
    }

    int Store::get_supplies() const {
        return supplies;
    }

    bool Store::is_empty() const {
        return supplies == 0;
    }

    Store::Store(int capacity): capacity(capacity) {
    }

}

