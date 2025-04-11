#pragma once

#include "Role.h"

class Builder final : public Role {
public:
    void work(View::AntDrawable& drawable_ant,  HiveMind& hive_mind) override;
    [[nodiscard]] Builder* clone() const override;
    [[nodiscard]] std::string get_name() const override {
        return "Builder";
    }
};
