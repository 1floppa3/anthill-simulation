#include <iostream>
#include "WoodMap.h"
#include "../../Utils/Random.h"


namespace Model {
    Model::WoodMap::WoodMap(Model::Store& store):store(store){};

    void Model::WoodMap::store_wood(View::WoodPoint *wood_point) {
        store.increase(1);
        delete wood_point;
        wood_points.erase(wood_point);
    }

    void WoodMap::add_wood(View::WoodPoint* wood_point) {
        if(wood_points.count(wood_point) == 0)
            wood_points[wood_point] = false;
        else
            std::cout << "smth wrong wood event_manager";
    }

    View::WoodPoint* WoodMap::find_closest_wood(const View::AntDrawable &drawable) {
        View::WoodPoint *closest_wood = nullptr;
        float min_distance_squared = std::numeric_limits<float>::max();

        for (auto &wood: wood_points) {
            if (wood.second)
                continue;
            const float distance_squared = (wood.first->getPosition() - drawable.get_position()).lengthSquared();
            if (distance_squared < min_distance_squared) {
                min_distance_squared = distance_squared;
                closest_wood = wood.first;
            }
        }

        if (closest_wood) {
            wood_points[closest_wood] = true;
            return closest_wood;
        }
        return nullptr;
    }

    void WoodMap::draw(sf::RenderTarget &target, const sf::RenderStates states) const {
        for (const auto &[point, reserved]: wood_points) {
            target.draw(*point, states);
        }
    }

}
