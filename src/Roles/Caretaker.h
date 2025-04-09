#pragma once

#include "Role.h"

class Caretaker final : public Role {
public:
    void work(AntDrawable& drawable_ant) const override;
    [[nodiscard]] Caretaker* clone() const override;
};
