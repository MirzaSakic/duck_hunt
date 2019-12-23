#pragma once

#include <Drawable.hpp>
#include <string>

struct SDL_Texture;

namespace DuckHunt {

class EntireBackground : public Drawable {
  public:
  EntireBackground(const std::string& path);

  void init(SDL_Renderer*) override;

  void draw(SDL_Renderer*) override;

  ~EntireBackground();

  private:
  std::string backgroundPath_;
  SDL_Texture* backgroundTexture_;
};

}