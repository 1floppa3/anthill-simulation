#ifndef ANTHILL_SIMULATION_MAP_H
#define ANTHILL_SIMULATION_MAP_H

#include <SFML/Graphics/Drawable.hpp>
#include <map>
#include "../../View/Points/Point.h"
#include "../../View/AntDrawable.h"
#include "../Store.h"

namespace Model{
    class Map : public sf::Drawable {

        std::map<View::Point*, bool> points;
        Model::Store& store;
    public:
        Map(Model::Store& store);
        void add_object(View::Point* point);
        void store_object(View::Point* point);

        View::Point* find_closest_object(const View::AntDrawable& drawable);

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    };
}



#endif //ANTHILL_SIMULATION_MAP_H
