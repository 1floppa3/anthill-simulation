#include <iostream>
#include "Map.h"
namespace Model{
    Model::Map::Map(Model::Store& store):store(store){};

    void Model::Map::store_object(View::Point *point) {
        store.increase(1);
        delete point;
        points.erase(point);
    }

    void Map::add_object(View::Point *point){
        if(points.count(point) == 0)
            points[point] = false;
        else
            std::cout << "smth wrong Map event_manager";
    }

    View::Point *Map::find_closest_object(const View::AntDrawable &drawable) {
        View::Point *closest_obj = nullptr;
        float min_distance_squared = std::numeric_limits<float>::max();

        for (auto &obj: points) {
            if (obj.second)
                continue;
            const float distance_squared = (obj.first->getPosition() - drawable.get_position()).lengthSquared();
            if (distance_squared < min_distance_squared) {
                min_distance_squared = distance_squared;
                closest_obj = obj.first;
            }
        }

        if (closest_obj) {
            points[closest_obj] = true;
            return closest_obj;
        }
        return nullptr;
    }

    void Map::draw(sf::RenderTarget &target, const sf::RenderStates states) const {
        for (const auto &[point, reserved]: points) {
            target.draw(*point, states);
        }
    }

    Map::~Map() {
        for (auto &obj: points) {
            delete obj.first;
        }
    }
}
