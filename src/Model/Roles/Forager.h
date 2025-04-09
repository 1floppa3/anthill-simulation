#pragma once

#include "Role.h"

class Forager final : public Role {
public:
    void work(View::AntDrawable& drawable_ant) const override;
    [[nodiscard]] Forager* clone() const override;
    [[nodiscard]] std::string get_name() const override {
        return "Forager";
    }
};
