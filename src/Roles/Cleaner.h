#pragma once

#include "Role.h"

class Cleaner final : public Role {
public:
    void work(AntDrawable& drawable_ant) const override;
    [[nodiscard]] Cleaner* clone() const override;
};
