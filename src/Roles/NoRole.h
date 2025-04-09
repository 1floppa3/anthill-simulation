#pragma once

#include <iostream>
#include "Role.h"

class NoRole final : public Role {
public:
    void work(AntDrawable& drawable_ant) const override {
        std::cout << drawable_ant.get_position().x;
    }

    [[nodiscard]] NoRole* clone() const override;
};

