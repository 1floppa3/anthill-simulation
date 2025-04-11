#include "Logger.h"

#include <iostream>
#include <ranges>

#include "../../Core/Simulation.h"


namespace View::UI {

    std::vector<std::string> Logger::wrap_text(const std::string& message) const {
        std::istringstream iss(message);
        std::string word;
        std::string cur_line;
        std::vector<std::string> lines;
        sf::Text text(Core::g_log_font, "", 24);
        while (iss >> word) {
            std::string test_line = cur_line.empty() ? word : cur_line + std::string(" ").append(word);
            text.setString(test_line);
            if (text.getLocalBounds().size.x > max_width) {
                if (!cur_line.empty()) {
                    lines.push_back(cur_line);
                    cur_line = word;
                } else {
                    lines.push_back(word);
                    cur_line.clear();
                }
            } else {
                cur_line = test_line;
            }
        }
        if (!cur_line.empty()) {
            lines.push_back(cur_line);
        }
        return lines;
    }

    void Logger::add_message(const std::string& message) {
        if (messages.size() >= max_history) {
            messages.pop_front();
        }
        messages.push_back({ message, sf::Time::Zero });
    }

    void Logger::update(const sf::Time &dt) {
        for (auto it = messages.begin(); it != messages.end(); ) {
            it->elapsed += dt;
            if (it->elapsed >= display_duration + fade_duration) {
                it = messages.erase(it);
            } else {
                ++it;
            }
        }
    }
    void Logger::draw(sf::RenderTarget& target, const sf::RenderStates states) const {
        const sf::Vector2f view_size = target.getView().getSize();

        sf::Text text(Core::g_log_font, "", 18);
        sf::Color base_color(144, 238, 144);

        // TODO сделать округленные края
        sf::RectangleShape background;
        background.setFillColor(sf::Color(0, 0, 0, 150));

        float currentY = view_size.y - margin_bottom;
        const float startY = currentY;

        for (auto& [message, elapsed]: std::ranges::reverse_view(messages)) {
            for (const std::string& wrapped_line: std::ranges::reverse_view(wrap_text(message))) {
                text.setString(wrapped_line);
                const sf::FloatRect bounds = text.getLocalBounds();
                currentY -= bounds.size.y + line_spacing;
                if (currentY < 0) {
                    break;
                }
            }
            if (currentY < 0) break;
        }
        if (currentY >= startY) return;

        const float background_height = startY - currentY + background_padding;
        background.setPosition({0.f, currentY - background_padding});
        background.setSize(sf::Vector2f(max_width + 10.f, background_height + 2 * background_padding));
        target.draw(background, states);

        currentY = startY;
        for (auto& [message, elapsed]: std::ranges::reverse_view(messages)) {
            float alpha = 255.f;
            if (elapsed > display_duration) {
                float fade_progress = (elapsed - display_duration).asSeconds() / fade_duration.asSeconds();
                alpha = 255.f * (1.f - std::min(fade_progress, 1.f));
            }
            base_color.a = static_cast<unsigned char>(alpha);
            text.setFillColor(base_color);

            for (const std::string& wrapped_line : std::ranges::reverse_view(wrap_text(message))) {
                text.setString(wrapped_line);
                const sf::FloatRect bounds = text.getLocalBounds();
                text.setPosition({10.f, currentY - bounds.size.y});
                target.draw(text, states);
                currentY -= bounds.size.y + line_spacing;
                if (currentY < 0)
                    return;
            }
        }
    }

}
