#pragma once

#include "../../View/AntDrawable.h"
#include "../HiveMind.h"

class Role {
public:
    virtual ~Role() = default;
    virtual void work(View::AntDrawable& drawable_ant, HiveMind& hive_mind) = 0;
    [[nodiscard]] virtual Role* clone() const = 0;
    [[nodiscard]] virtual std::string get_name() const = 0;
};
