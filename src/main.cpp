#include "Window.h"

int main()
{
  Window window(sf::VideoMode({800, 600}), "Coursework", "assets/14.obj");
  window.loop();
}
