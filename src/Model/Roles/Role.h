#pragma once

#include <string>
#include "../../View/FoodMap.h"
#include "../../Core/EventManager.h"
#include "../../View/AntDrawable.h"

namespace Model::Roles {

    class Role {
    public:
        virtual ~Role() = default;
        virtual void work(View::AntDrawable& drawable_ant, View::FoodMap& food_map) = 0;
        void detect_objects(View::AntDrawable& drawable_ant, Core::EventManager& event_manager);
        [[nodiscard]] virtual Role* clone() const = 0;
        [[nodiscard]] virtual std::string get_name() const = 0;
    };

}
