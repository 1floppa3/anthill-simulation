#include "AnthillSettings.h"

bool AnthillRank::AreValidRanks(const std::vector<AnthillRank>& ranks, AnthillRank::Error& error) {
	for (size_t i = 0; i < ranks.size() - 1; ++i) {
		if (ranks[i].wood_capacity < ranks[i + 1].wood_to_update) {
			error.rank_tear = i;
			error.wrong_field = Error::WoodToUpdate;
			return false;
		}
		if (ranks[i].wood_capacity < ranks[i].wood_to_maintain) {
			error.rank_tear = i;
			error.wrong_field = Error::WoodToMaintain;
			return false;
		}
		if (ranks[i].wood_capacity > ranks[i + 1].wood_capacity) {
			error.rank_tear = i;
			error.wrong_field = Error::WoodCapacity;
			return false;
		}
		if (ranks[i].food_capacity > ranks[i + 1].food_capacity) {
			error.rank_tear = i;
			error.wrong_field = Error::FoodCapacity;
			return false;
		}
		if (ranks[i].ants_capacity > ranks[i + 1].ants_capacity) {
			error.rank_tear = i;
			error.wrong_field = Error::AntsCapacity;
			return false;
		}
	}
	return true;
}

AnthillSettings AnthillSettings::Init(int initial_amount_of_wood, int initial_amount_of_food,
	const std::vector<AnthillRank>& anthill_ranks, const std::vector<AnthillInfo::AntRole>& initial_roles) {
	std::vector<AnthillRank> ranks;
	if (anthill_ranks.size() == 0) {
		ranks = { AnthillRank(0, 1, 10, 20, 20, 100), AnthillRank(10, 2, 15, 30, 30, 150),
			AnthillRank(15, 3, 20, 40, 40, 175),	AnthillRank(20, 3, 30, 50, 50, 200), AnthillRank(25, 3, 40, 60, 60, 250) };
	}
	else {
		AnthillRank::Error err;
		if (AnthillRank::AreValidRanks(anthill_ranks, err))
			ranks = anthill_ranks;
		else
			throw err;

		if (initial_amount_of_wood > anthill_ranks[0].wood_capacity)
			initial_amount_of_wood = anthill_ranks[0].wood_capacity;
		if (initial_amount_of_food > anthill_ranks[0].food_capacity)
			initial_amount_of_food = anthill_ranks[0].food_capacity;
	}
	std::vector<AnthillInfo::AntRole> roles;
	if (initial_roles.size() == 0) {
		roles = { AnthillInfo::Forager, AnthillInfo::Forager, AnthillInfo::Builder, AnthillInfo::Caretaker };
	}
	else {
		// TODO: Validate
		roles = initial_roles;
	}
	return AnthillSettings(ranks, roles, initial_amount_of_wood, initial_amount_of_food);
}