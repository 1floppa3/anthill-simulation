#include <algorithm>
#include <iostream>
#include "Store.h"

namespace Model {
    void Store::increase(size_t val) {
        supplies = (supplies + val > capacity) ? capacity : supplies + val;
    }

    void Store::decrease(size_t val) {
        supplies = (supplies > val) ? supplies - val : 0;
    }

    void Store::update_capacity(size_t new_capacity) {
        capacity = new_capacity;
        if (supplies > capacity)
            supplies = capacity;
    }

    size_t Store::get_supplies() const {
        return supplies;
    }

    size_t Store::get_capacity() const
    {
        return capacity;
    }

    bool Store::is_empty() const {
        return supplies == 0;
    }

    Store::Store(int capacity, int supplies): capacity(capacity), supplies(supplies) {}

}

