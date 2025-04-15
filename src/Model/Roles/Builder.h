#pragma once

#include "Role.h"

namespace Model::Roles {

    class Builder final : public Role {
        View::WoodPoint* wood_point;
        bool is_bringing;
    public:
        Builder();
        void work(View::AntDrawable& drawable_ant,  Model::HiveMind& hive_mind) override;
        [[nodiscard]] Builder* clone() const override;
        [[nodiscard]] std::string get_name() const override {
            return "Builder";
        }
    };

}