#pragma once

#include "../Drawable/AntDrawable.h"

class Role {
public:
    virtual ~Role() = default;
    virtual void work(AntDrawable& drawable_ant) const = 0;
    [[nodiscard]] virtual Role* clone() const = 0;
};
