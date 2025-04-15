#pragma once

#include <map>
#include "../../View/WoodPoint.h"
#include "../../View/AntDrawable.h"
#include "../Store.h"

namespace Model {

    class WoodMap final : public sf::Drawable {

        std::map<View::WoodPoint*, bool> wood_points;
        Model::Store& store;
    public:
        WoodMap(Model::Store& store);
        void add_wood(View::WoodPoint* wood_point);
        void store_wood(View::WoodPoint* wood_point);

        View::WoodPoint* find_closest_wood(const View::AntDrawable& drawable);

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    };

}
