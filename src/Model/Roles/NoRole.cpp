#include "NoRole.h"

namespace Model::Roles {

    NoRole* NoRole::clone() const {
        return new NoRole(*this);
    }

}