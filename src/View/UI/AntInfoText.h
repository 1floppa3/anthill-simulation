#pragma once

#include <SFML/Graphics.hpp>

namespace Model {
    class Ant;
}

namespace View::UI {

    class AntInfoText final : public sf::Text {
        static constexpr int font_size = 16;
    public:
        AntInfoText();
        void update(const Model::Ant& ant);
    };

}
