#pragma once

#include "../../View/AntDrawable.h"

class Role {
public:
    virtual ~Role() = default;
    virtual void work(View::AntDrawable& drawable_ant) const = 0;
    [[nodiscard]] virtual Role* clone() const = 0;
    [[nodiscard]] virtual std::string get_name() const = 0;
};
