#pragma once

#include "Role.h"

class Builder final : public Role {
public:
    void work(AntDrawable& drawable_ant) const override;
    [[nodiscard]] Builder* clone() const override;
};
