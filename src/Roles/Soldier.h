#pragma once

#include "Role.h"

class Soldier final : public Role {
public:
    void work(AntDrawable& drawable_ant) const override;
    [[nodiscard]] Soldier* clone() const override;
};
