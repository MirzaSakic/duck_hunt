#include <EntireBackground.hpp>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <iostream>

namespace DuckHunt {

EntireBackground::EntireBackground(const std::string& path)
    : backgroundPath_{path} {}

void EntireBackground::init(SDL_Renderer* renderer) {
  using namespace std::string_literals;
  SDL_Surface* surface = IMG_Load("./img/bg.bmp");
  if (!surface) {
    throw std::runtime_error("EntireBackground could not create surface: "s +
                             SDL_GetError());
  }
  backgroundTexture_ = SDL_CreateTextureFromSurface(renderer, surface);
  if (!backgroundTexture_) {
    throw std::runtime_error("EntireBackground could not create texture: "s +
                             SDL_GetError());
  }
  SDL_FreeSurface(surface);
}

void EntireBackground::draw(SDL_Renderer* renderer) {
  SDL_RenderCopy(renderer, backgroundTexture_, nullptr, nullptr);
}

EntireBackground::~EntireBackground() {
  SDL_DestroyTexture(backgroundTexture_);
}

}