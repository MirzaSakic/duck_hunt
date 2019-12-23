#include <Window.hpp>

namespace DuckHunt {

using namespace std::chrono_literals;

Window::Window()
    : init_{SDL_Init(SDL_INIT_VIDEO)},
      window_{SDL_CreateWindow("Duck Hunt", SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED, 800, 600, 0)},
      surface_{SDL_GetWindowSurface(window_)},
      renderer_{SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED)} {
  if (init_ < 0) {
    throw std::runtime_error("Failed to initialize the SDL2 library");
  }
  if (!window_) {
    throw std::runtime_error("Failed to create window");
  }
  if (!surface_) {
    throw std::runtime_error("Failed to get the surface from the window");
  }
  if (!renderer_) {
    throw std::runtime_error("Failed to create renderer");
  }
}

void Window::run() {
  running_ = true;
  renderThread_ = std::thread(&Window::renderWorker, this);
  while (running_) {
    SDL_Event e;
    while (SDL_PollEvent(&e) > 0) {
      switch (e.type) {
      case SDL_QUIT:
        running_ = false;
      }
    }
    std::this_thread::sleep_for(10ms);
  }
  renderThread_.join();
}

void Window::insertDrawable(const std::string& id, Drawable* object) {
  if (object == nullptr) {
    throw std::invalid_argument("Drawable object cannot be nullptr");
  }
  auto it = objectsOnWindow_.find(id);
  if (it != std::end(objectsOnWindow_)) {
    throw std::invalid_argument("Object with id {" + id + "} already exists!");
  }
  object->init(renderer_);
  objectsOnWindow_.insert({id, object});
}

void Window::renderWorker() {
  while (running_) {
    auto t1 = std::chrono::high_resolution_clock::now();
    SDL_RenderClear(renderer_);
    for (std::pair<std::string, Drawable*> objectsEntry : objectsOnWindow_) {
      auto& objectToDraw = *(objectsEntry.second);
      objectToDraw.draw(renderer_);
    }
    SDL_RenderPresent(renderer_);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto renderTime = t2 - t1;
    // std::this_thread::sleep_for(16ms);

    std::this_thread::sleep_for((renderTime < 32ms) ? (32ms - renderTime)
                                                    : 0ms);
  }
}

}