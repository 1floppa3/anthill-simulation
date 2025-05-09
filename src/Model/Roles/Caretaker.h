#pragma once

#include "Role.h"

namespace Model::Roles {

    class Caretaker final : public Role {
    public:
        void work(View::AntDrawable &drawable_ant, Model::HiveMind& hive_mind) override;
        [[nodiscard]] Caretaker *clone() const override;
        [[nodiscard]] std::string get_name() const override {
            return "Caretaker";
        }
        [[nodiscard]] sf::Color get_ant_color() const override {
            return {102, 205, 170};
        }
    };

}