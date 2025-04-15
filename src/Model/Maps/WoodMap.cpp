#include <iostream>
#include "WoodMap.h"
#include "../../Utils/Random.h"


namespace Model {
    Model::WoodMap::WoodMap(Model::Store& store): Map(store){};

    void Model::WoodMap::store_wood(View::WoodPoint *wood_point) {
        store_object(wood_point);
    }

    void WoodMap::add_wood(View::WoodPoint* wood_point) {
        add_object(wood_point);
    }

    View::WoodPoint* WoodMap::find_closest_wood(const View::AntDrawable &drawable) {
        return dynamic_cast<View::WoodPoint *>(find_closest_object(drawable));
    }

    void WoodMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
        Map::draw(target, states);
    }
}
