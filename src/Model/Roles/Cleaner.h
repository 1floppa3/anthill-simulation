#pragma once

#include "Role.h"

class Cleaner final : public Role {
public:
    void work(View::AntDrawable& drawable_ant) const override;
    [[nodiscard]] Cleaner* clone() const override;
    [[nodiscard]] std::string get_name() const override {
        return "Cleaner";
    }
};
