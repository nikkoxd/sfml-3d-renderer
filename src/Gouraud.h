#ifndef GOURAUD_H
#define GOURAUD_H

#include <SFML/Graphics.hpp>

void drawPolygon(sf::RenderWindow& window, std::array<sf::Vector2f, 3> points, sf::Color starting_color, sf::Color ending_color, sf::Vector2f offset = {0, 0}, float scale = 1.0);

#endif
