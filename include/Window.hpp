#pragma once

#include <Drawable.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <chrono>
#include <iostream>
#include <map>
#include <stdexcept>
#include <thread>

namespace DuckHunt {
class Window {
  public:
  Window();

  // Runs the Window loop
  void run();

  // Inserts drawable object with id for the next render. Throws if either id
  // already exists or object is nullptr.
  void insertDrawable(const std::string& id, Drawable*);

  private:
  int init_;
  SDL_Window* window_;
  SDL_Surface* surface_;
  SDL_Renderer* renderer_;
  bool running_ = false;
  std::thread renderThread_;

  std::map<std::string, Drawable*> objectsOnWindow_;

  void renderWorker();
};

}