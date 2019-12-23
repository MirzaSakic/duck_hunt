
#pragma once
struct SDL_Renderer;

namespace DuckHunt {

class Drawable {
  public:
  virtual void init(SDL_Renderer*) = 0;
  virtual void draw(SDL_Renderer*) = 0;
  virtual ~Drawable() = default;
};

}