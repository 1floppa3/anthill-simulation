#include "NoRole.h"

NoRole* NoRole::clone()const {
    return new NoRole(*this);
}