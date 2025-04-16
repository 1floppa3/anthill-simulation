#include "Enemy.h"
namespace Model{

    Enemy::Enemy(const sf::Vector2u &area):Entity(), drawable(new View::AntDrawable(area)) {

    }
}