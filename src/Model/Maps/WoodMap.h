#pragma once

#include <map>
#include "../../View/Points/WoodPoint.h"
#include "../../View/AntDrawable.h"
#include "../Store.h"
#include "Map.h"

namespace Model {

    class WoodMap final : public Map {
    public:
        WoodMap(Model::Store& store);
        void add_wood(View::WoodPoint* wood_point);
        void store_wood(View::WoodPoint* wood_point);

        View::WoodPoint* find_closest_wood(const View::AntDrawable& drawable);
    };

}
