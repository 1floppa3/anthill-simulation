#ifndef ANTHILL_SIMULATION_FOODPOINT_H
#define ANTHILL_SIMULATION_FOODPOINT_H


class FoodPoint {
    int capacity;
public:
    FoodPoint(int x, int y, int capacity);
    // изменим потом на sfml объект
    int x, y;
    bool compare_coords(int x, int y);
    bool is_empty();
    void take_food();
};


#endif //ANTHILL_SIMULATION_FOODPOINT_H
