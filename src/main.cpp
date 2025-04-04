#include <SFML/Graphics.hpp>
#include <iostream>
#include "Roles/Role.h"
#include "Roles/Caretaker.h"
#include "Roles/Soldier.h"
#include "Anthill.h"

int main() {

    Anthill anthill;
    for (int i = 0; i < 10000; ++i) {
        anthill.simulateDay();
    }

//    auto window = sf::RenderWindow(sf::VideoMode({ 1920u, 1080u }), "Anthill simulation");
//    window.setFramerateLimit(144);
//
//    while (window.isOpen())
//    {
//        while (const std::optional event = window.pollEvent())
//        {
//            if (event->is<sf::Event::Closed>())
//            {
//                window.close();
//            }
//        }
//
//        window.clear();
//        window.display();
//    }
}