#pragma once

#include <deque>
#include <SFML/Graphics.hpp>

namespace View::UI {

    struct TextSegment {
        std::string text;
        sf::Color color;
    };

    class Logger final : public sf::Drawable {
        const int max_history = 14;
        const float margin_bottom = 32.f;
        const float line_spacing = 3.f;
        const float max_width = 400.f;
        const float background_padding = 10.f;
        static constexpr int font_size = 18;
        const sf::Color base_color = sf::Color(144, 238, 144);

        const sf::Time display_duration = sf::seconds(7.5f);
        const sf::Time fade_duration = sf::seconds(4.f);

        struct LogMessage {
            std::string message;
            sf::Time elapsed;
        };

        std::deque<LogMessage> messages;

        [[nodiscard]] std::vector<std::string> wrap_text(const std::string& message) const;
        static std::vector<TextSegment> parse_markup(const std::string &line, const sf::Color &default_color);

    public:
        void add_message(const std::string& message);

        void update(const sf::Time& dt);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    };

}