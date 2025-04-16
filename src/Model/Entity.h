#ifndef ANTHILL_SIMULATION_ENTITY_H
#define ANTHILL_SIMULATION_ENTITY_H
namespace Model{
    class Entity{
    protected:
        int damage;
    public:
        int health;
        bool is_fighting;
        Entity();
        Entity(int damage, int health);
        Entity(const Entity& entity);
        bool is_alive()const;
        void deal_damage(Entity& entity) const;
        void take_damage(int damage);
    };
}

#endif //ANTHILL_SIMULATION_ENTITY_H