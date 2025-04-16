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
        sf::Text text(Core::g_log_font, "", font_size);

        auto remove_tags = [](const std::string& input) -> std::string {
            std::string output;
            bool in_tag = false;
            for (const char c: input) {
                if (c == '<') {
                    in_tag = true;
                    continue;
                }
                if (c == '>') {
                    in_tag = false;
                    continue;
                }
                if (!in_tag)
                    output.push_back(c);
            }
            return output;
        };

        while (iss >> word) {
            std::string test_line = cur_line.empty() ? word : cur_line + std::string(" ").append(word);
            std::string stripped_test_line = remove_tags(test_line);
            text.setString(stripped_test_line);
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
    std::vector<TextSegment> Logger::parse_markup(const std::string& line, const sf::Color& default_color) {
        std::vector<TextSegment> segments;
        size_t pos = 0;
        sf::Color current_color = default_color;

        while (pos < line.size()) {
            const size_t tag_start = line.find('<', pos);
            if (tag_start == std::string::npos) {
                segments.push_back({ line.substr(pos), current_color });
                break;
            }
            if (tag_start > pos) {
                segments.push_back({ line.substr(pos, tag_start - pos), current_color });
            }
            if (line.compare(tag_start, 8, "<color=#") == 0) {
                size_t tag_end = line.find('>', tag_start);
                if (tag_end != std::string::npos && tag_end - tag_start >= 14) {
                    std::string hex = line.substr(tag_start + 8, 6);
                    try {
                        const unsigned int r = std::stoul(hex.substr(0, 2), nullptr, 16);
                        const unsigned int g = std::stoul(hex.substr(2, 2), nullptr, 16);
                        const unsigned int b = std::stoul(hex.substr(4, 2), nullptr, 16);
                        current_color = sf::Color(r, g, b, default_color.a);
                    } catch (...) {
                        // оставляем текущий цвет
                    }
                    pos = tag_end + 1;
                } else {
                    pos = tag_start + 1;
                }
            } else if (line.compare(tag_start, 8, "</color>") == 0) {
                current_color = default_color;
                pos = tag_start + 8;
            } else {
                pos = tag_start + 1;
            }
        }
        return segments;
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

        // TODO сделать округленные края
        sf::RectangleShape background;
        background.setFillColor(sf::Color(0, 0, 0, 150));

        float currentY = view_size.y - margin_bottom;
        const float startY = currentY;

        for (auto& [message, elapsed]: std::ranges::reverse_view(messages)) {
            for (const std::string& wrapped_line: std::ranges::reverse_view(wrap_text(message))) {
                sf::Text temp_text(Core::g_log_font, wrapped_line, font_size);
                const sf::FloatRect bounds = temp_text.getLocalBounds();
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
        for (auto& [message, elapsed] : std::ranges::reverse_view(messages)) {
            float alpha = 255.f;
            if (elapsed > display_duration) {
                float fade_progress = (elapsed - display_duration).asSeconds() / fade_duration.asSeconds();
                alpha = 255.f * (1.f - std::min(fade_progress, 1.f));
            }

            sf::Color effective_base_color = base_color;
            effective_base_color.a = static_cast<unsigned char>(alpha);

            for (const std::string& wrapped_line : std::ranges::reverse_view(wrap_text(message))) {
                std::vector<TextSegment> segments = parse_markup(wrapped_line, effective_base_color);

                float x_offset = 10.f;
                sf::Text text(Core::g_log_font, wrapped_line, font_size);
                const sf::FloatRect bounds = text.getLocalBounds();

                for (const auto& [str, color] : segments) {
                    text.setString(str);
                    text.setFillColor(color);

                    text.setPosition({x_offset, currentY - bounds.size.y});
                    target.draw(text, states);
                    x_offset += text.getLocalBounds().size.x;
                }
                sf::Text temp_text(Core::g_log_font, wrapped_line, font_size);
                currentY -= temp_text.getLocalBounds().size.y + line_spacing;
                if (currentY < 0)
                    return;
            }
        }
    }

}
