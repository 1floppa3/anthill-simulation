#pragma once

#include "Role.h"

class Forager final : public Role {
public:
    void work(AntDrawable& drawable_ant) const override;
    [[nodiscard]] Forager* clone() const override;
};
