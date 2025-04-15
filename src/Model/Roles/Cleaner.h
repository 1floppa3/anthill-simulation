#pragma once

#include "Role.h"

namespace Model::Roles {

    class Cleaner final : public Role {
    public:
        void work(View::AntDrawable &drawable_ant, Model::HiveMind& hive_mind) override;
        [[nodiscard]] Cleaner *clone() const override;
        [[nodiscard]] std::string get_name() const override {
            return "Cleaner";
        }
        [[nodiscard]] sf::Color get_ant_color() const override {
            return {135, 206, 235};
        }
    };

}