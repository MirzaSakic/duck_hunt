#pragma once

struct SDL_Texture;

struct Size {
  int width = 0;
  int height = 0;
};

struct Coordinates {
  int x = 0;
  int y = 0;
};

Size getImageSize(SDL_Texture* const);