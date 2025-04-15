#pragma once

#include <string>
#include "../Maps/FoodMap.h"
#include "../../Core/EventManager.h"
#include "../../View/AntDrawable.h"

namespace Model::Roles {

    class Role {
    public:
        virtual ~Role() = default;
        virtual void work(View::AntDrawable& drawable_ant, Model::HiveMind& hive_mind) = 0;
        void detect_objects(View::AntDrawable& drawable_ant, Core::EventManager& event_manager);
        [[nodiscard]] virtual Role* clone() const = 0;
        [[nodiscard]] virtual std::string get_name() const = 0;
        [[nodiscard]] virtual sf::Color get_ant_color() const = 0;
    };

}
