#ifndef ANTHILL_SETTINGS
#define ANTHILL_SETTINGS

#include <vector>
namespace AnthillInfo {
    enum AntRole {
        NoRole, Builder, Solider, Forager, Cleaner, Caretaker
    };
}

struct AnthillRank {
    int wood_to_update, wood_to_maintain, ants_capacity, food_capacity, wood_capacity, max_hp;

    struct Error {
        int rank_tear;
        enum {
            WoodToUpdate, WoodToMaintain, AntsCapacity, FoodCapacity, WoodCapacity
        } wrong_field;
    };

    AnthillRank(int wood_to_update, int wood_to_maintain, int ants_capacity, int food_capacity, int wood_capacity) :
        wood_to_update(wood_to_update), wood_to_maintain(wood_to_maintain), ants_capacity(ants_capacity),
        food_capacity(food_capacity), wood_capacity(wood_capacity) {
    }

    // Checks wether it's possible to upgrade the anthill to the next rank and wether the capacity of anthill reduces.
    static bool AreValidRanks(const std::vector<AnthillRank>& ranks, AnthillRank::Error& error);
};

class AnthillSettings {
private:
    std::vector<AnthillRank> anthill_ranks;
    std::vector<AnthillInfo::AntRole> initial_roles;
    int initial_amount_of_wood, initial_amount_of_food;

    AnthillSettings(const std::vector<AnthillRank>& anthill_ranks, const std::vector<AnthillInfo::AntRole>& initial_roles,
        int initial_amount_of_wood, int initial_amount_of_food) :
        anthill_ranks(anthill_ranks), initial_roles(initial_roles), initial_amount_of_wood(initial_amount_of_wood),
        initial_amount_of_food(initial_amount_of_food) {
    }
public:
    //Attempts to create an instance of the class.
    static AnthillSettings Init(int initial_amount_of_wood = 0, int initial_amount_of_food = 0,
        const std::vector<AnthillRank>& anthill_ranks = {}, const std::vector<AnthillInfo::AntRole>& intial_roles = {});

    const std::vector<AnthillRank>& get_ranks() const { return anthill_ranks; }
    const std::vector<AnthillInfo::AntRole>& get_initial_roles() const { return initial_roles; }
    int get_amount_of_food() const { return initial_amount_of_food; }
    int get_amount_of_wood() const { return initial_amount_of_wood; }
};

#endif