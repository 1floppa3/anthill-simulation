#pragma once

#include "Role.h"

class Caretaker final : public Role {
public:
    void work(View::AntDrawable& drawable_ant) const override;
    [[nodiscard]] Caretaker* clone() const override;
    [[nodiscard]] std::string get_name() const override {
        return "Caretaker";
    }
};
