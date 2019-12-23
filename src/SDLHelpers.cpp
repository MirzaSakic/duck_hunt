#include <SDL2/SDL_render.h>
#include <SDLHelpers.hpp>

Size getImageSize(SDL_Texture* const texture) {
  SDL_Rect rect;
  SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
  return {rect.w, rect.h};
}