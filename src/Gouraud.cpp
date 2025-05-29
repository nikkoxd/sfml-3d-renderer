#include "gouraud.h"
#include "util.h"
#include <SFML/Graphics/Color.hpp>
#include <cmath>
#include <iostream>

void drawPolygon(sf::RenderWindow& window, std::array<sf::Vector2f, 3> points, sf::Color starting_color, sf::Color ending_color, sf::Vector2f offset, float scale)
{
  for (int i = 0; i < 3; i++)
  {
    points[i].x *= scale;
    points[i].y *= scale;
    points[i].x += offset.x;
    points[i].y += offset.y;
  }

  float dt = points[2].y - points[0].y;
  float ds = points[1].y - points[0].y;

  float dtx = points[2].x - points[0].x;
  float dsx = points[1].x - points[0].x;

  for (int y = points[0].y; y <= points[2].y; y++)
  {
    float alpha = (y - points[0].y) / dt;
    float beta = (y - points[0].y) / ds;

    int x_alpha = points[0].x + dtx * alpha;
    int x_beta = points[0].x + dsx * beta;

    if (y >= points[1].y)
    {
      ds = points[2].y - points[1].y;
      dsx = points[2].x - points[1].x;

      beta = (y - points[1].y) / ds;
      x_beta = points[1].x + dsx * beta;
    }

    for (int j = std::min(x_alpha, x_beta); j <= std::max(x_alpha, x_beta); j++)
    {
      if (j == 0) {
        break;
      }
      float t = (x_beta - (float)j) / (x_beta - x_alpha);
      if (std::isnan(t))
      {
        t = 0;
      }

      sf::Vector2i pseudo_position = toScreen(window, pseudoToReal({(float)j, (float)y}));

      sf::Color color = starting_color;
      color.r = t * ending_color.r + (1 - t) * starting_color.r;
      color.g = t * ending_color.g + (1 - t) * starting_color.g;
      color.b = t * ending_color.b + (1 - t) * starting_color.b;
      drawPseudoPixel(window, pseudo_position, color);
    }
  }
}
