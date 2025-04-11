#include "HUD.h"

#include "../../Core/Simulation.h"


namespace View::UI {

    HUD::HUD(const sf::Vector2u& size): window_size(size) {
        anthill_info_text.update(window_size);
    }
    void HUD::update(const sf::Time& dt) {
        anthill_info_text.update(window_size);
        fps_text.update(dt);
        Core::g_logger.update(dt);
    }
    void HUD::draw(sf::RenderTarget &target, const sf::RenderStates states) const {
        target.draw(anthill_info_text, states);
        target.draw(fps_text, states);
        Core::g_logger.draw(target, states);
    }

}
