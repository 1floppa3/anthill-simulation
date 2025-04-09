#include "AnthillInfoText.h"

#include "AnthillDrawable.h"

AnthillInfoText::AnthillInfoText(const sf::Font &font): Text(font, "", 36) {
    this->setFillColor(sf::Color::White);
}

void AnthillInfoText::update(const sf::RenderWindow &window) {
    this->setString("Days expired: " + std::to_string(AnthillDrawable::instance().day_counter));
    this->setPosition({static_cast<float>(window.getSize().x) - this->getLocalBounds().size.x - margin, margin});
}
