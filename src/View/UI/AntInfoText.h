#pragma once

#include <SFML/Graphics.hpp>

namespace Model {
    class Ant;
}

namespace View::UI {

    class AntInfoText final : public sf::Text {
    public:
        AntInfoText();
        void update(const Model::Ant& ant);
    };

}
