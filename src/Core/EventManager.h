#ifndef ANTHILL_SIMULATION_EVENTMANAGER_H
#define ANTHILL_SIMULATION_EVENTMANAGER_H
#include "../View/FoodMap.h"
#include "../View/FoodPoint.h"
#include "../View/AntDrawable.h"
#include <list>


namespace Core{
    class EventManager {
    private:
        const float area_margin = 50.f;
    public:
        View::FoodMap* food_map;
        std::list<View::FoodPoint*> undetected_food;

        void set_food_map(View::FoodMap* foodMap);
        void generate_food(const sf::Vector2f &area);
        void detect_food(View::AntDrawable& ant_drawable);
//        Enemy enemies;
//        WoodMap woodMap;
// и тд тут храним все о чем временно не знаю муравьи
    };

}


#endif //ANTHILL_SIMULATION_EVENTMANAGER_H
