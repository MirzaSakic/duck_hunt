#include <Duck.hpp>
#include <EntireBackground.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> // IMG_Load
#include <Window.hpp>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

int main(int, char**) {
  using namespace DuckHunt;
  try {
    Window w;
    auto entireBackground = new EntireBackground("./img/bg.bmp");
    auto duck = new Duck();
    w.insertDrawable("EntireBackground", entireBackground);
    w.insertDrawable("ZDuck", duck);
    w.run();
  } catch (std::exception& err) {
    std::cout << "Exception caught: " << err.what() << std::endl;
  }

  return 0;
}
