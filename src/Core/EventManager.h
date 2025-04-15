#ifndef ANTHILL_SIMULATION_EVENTMANAGER_H
#define ANTHILL_SIMULATION_EVENTMANAGER_H
#include "../Model/HiveMind.h"
#include "../View/Points/FoodPoint.h"
#include "../View/Points/WoodPoint.h"
#include "../View/AntDrawable.h"
#include <list>


namespace Core{
    class EventManager {
    private:
        const float area_margin = 50.f;
    public:
        Model::HiveMind* hive_mind;
        std::list<View::FoodPoint*> undetected_food;
        std::list<View::WoodPoint*> undetected_wood;

        void set_hive_mind(Model::HiveMind* hive_mind);

        void generate_food(const sf::Vector2f &area);

        void generate_wood(const sf::Vector2f &area);


        void detect_objects(View::AntDrawable& ant_drawable);
//        Enemy enemies;
//        WoodMap woodMap;
// и тд тут храним все о чем временно не знаю муравьи
    };

}


#endif //ANTHILL_SIMULATION_EVENTMANAGER_H
