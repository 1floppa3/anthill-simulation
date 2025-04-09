#pragma once

#include <iostream>
#include "Role.h"

class NoRole final : public Role {
public:
    void work(View::AntDrawable& drawable_ant) const override {
        std::cout << drawable_ant.get_position().x;
    }

    [[nodiscard]] NoRole* clone() const override;

    [[nodiscard]] std::string get_name() const override {
        return "No role";
    }
};

