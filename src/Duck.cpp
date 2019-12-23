#include <Duck.hpp>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDLHelpers.hpp>
#include <iostream>

namespace DuckHunt {

Duck::Duck() {}

void Duck::init(SDL_Renderer* renderer) {
  std::cout << "Initialized!" << std::endl;
  SDL_Surface* surface = IMG_Load("./img/duck_right.bmp");
  if (!surface) {
    std::cout << SDL_GetError() << std::endl;
  }
  ducksTexture_ = SDL_CreateTextureFromSurface(renderer, surface);
  if (!ducksTexture_) {
    std::cout << SDL_GetError() << std::endl;
  }
  auto duckImageSize = getImageSize(ducksTexture_);
  spriteWidth_ = (double)duckImageSize.width / 9;
  spriteHeight_ = (double)duckImageSize.height / 4;
  for (auto i = 0; i < 3; ++i) {
    duckRightSprites_[i].x = (i % 3) * spriteWidth_;
    duckRightSprites_[i].y = 0;
    duckRightSprites_[i].w = spriteWidth_;
    duckRightSprites_[i].h = spriteHeight_;
  }
  for (auto i = 0; i < 3; ++i) {
    duckUpperRightSprites_[i].x = (i % 3) * spriteWidth_;
    duckUpperRightSprites_[i].y = spriteHeight_;
    duckUpperRightSprites_[i].w = spriteWidth_;
    duckUpperRightSprites_[i].h = spriteHeight_;
  }
  for (auto i = 0; i < 3; ++i) {
    duckUpperSprites_[i].x = (i % 3) * spriteWidth_;
    duckUpperSprites_[i].y = 2 * spriteHeight_;
    duckUpperSprites_[i].w = spriteWidth_;
    duckUpperSprites_[i].h = spriteHeight_;
  }
  SDL_FreeSurface(surface);
}

void Duck::draw(SDL_Renderer* renderer) {
  static int n = 0;
  static int i = 0;
  ++i;
  SDL_Rect destRect;
  destRect.w = spriteWidth_;
  destRect.h = spriteHeight_;
  destRect.x = 400 + i * 3;
  destRect.y = 300;
  if (i % 3 == 0) ++n;
  // std::cout << "Current Sprite coordinates:" << std::endl;
  // std::cout << "***************************" << std::endl;
  // std::cout << "X: " << duckRightSprites_[n % 3].x << std::endl;
  // std::cout << "Y: " << duckRightSprites_[n % 3].y << std::endl;
  // std::cout << "W: " << duckRightSprites_[n % 3].w << std::endl;
  // std::cout << "H: " << duckRightSprites_[n % 3].h << std::endl;
  SDL_RenderCopy(renderer, ducksTexture_, &duckRightSprites_[n % 3], &destRect);
}

Duck::~Duck() { SDL_DestroyTexture(ducksTexture_); }

}