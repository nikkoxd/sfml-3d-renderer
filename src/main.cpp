#include "Window.h"

int main()
{
  Window window(sf::VideoMode({1280, 720}), "Coursework", "assets/14.obj");
  window.loop();
}
