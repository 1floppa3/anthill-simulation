#include "HUD.h"


namespace View::UI {

HUD::HUD(const sf::RenderWindow& w, const sf::Font& f):
window(&w), anthill_info_text(f), fps_text(f) {
    anthill_info_text.update(*window);
}

void HUD::update(const sf::Time& dt) {
    anthill_info_text.update(*window);
    fps_text.update(dt);
}

void HUD::draw(sf::RenderTarget &target, const sf::RenderStates states) const {
    target.draw(anthill_info_text, states);
    target.draw(fps_text, states);
}

}
