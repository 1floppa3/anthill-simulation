#pragma once

#include "../../View/FoodMap.h"
#include <string>

#include "../../View/AntDrawable.h"

namespace Model::Roles {

    class Role {
    public:
        virtual ~Role() = default;
        virtual void work(View::AntDrawable& drawable_ant, View::FoodMap& hive_mind) = 0;
        [[nodiscard]] virtual Role* clone() const = 0;
        [[nodiscard]] virtual std::string get_name() const = 0;
    };

}
