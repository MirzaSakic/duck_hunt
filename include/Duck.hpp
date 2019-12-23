#pragma once

#include <Drawable.hpp>
#include <SDL2/SDL_rect.h>
#include <vector>

struct SDL_Texture;

namespace DuckHunt {

class Duck : public Drawable {
  public:
  Duck();

  void init(SDL_Renderer*) override;

  void draw(SDL_Renderer*) override;
  ~Duck();

  private:
  const int duckSpritesRows = 3;
  const int duckSpritesCols = 4;
  const int duckSpritesCount = 11;
  SDL_Texture* ducksTexture_;
  double spriteWidth_;
  double spriteHeight_;
  std::vector<SDL_Rect> duckRightSprites_ = std::vector<SDL_Rect>(3);
  std::vector<SDL_Rect> duckUpperRightSprites_ = std::vector<SDL_Rect>(3);
  std::vector<SDL_Rect> duckUpperSprites_ = std::vector<SDL_Rect>(3);
  std::vector<SDL_Rect> duckLeftSprites_ = std::vector<SDL_Rect>(3);
  std::vector<SDL_Rect> duckUpperLeftSprites_ = std::vector<SDL_Rect>(3);
  SDL_Rect duckShotSprite_;
  SDL_Rect duckFallSprite_;
};

}