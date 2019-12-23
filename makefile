CXX ?= clang++
PROJ = game
INC =  -I./include/ -I./libcaf/include/ -I./libSDL2/include/
CXXFLAGS = -std=c++17 -Wall -Wextra
LIB_PATH=-L./libcaf/release_dynamic_cpp_runtime/lib -L./libSDL2/lib/.
RPATH=-Wl,-rpath=./libSDL2/lib/:./libcaf/release_dynamic_cpp_runtime/lib/
LINK_FLAGS = -lcaf_core -lSDL2 -lSDL2_image -lSDL2_ttf -lpthread -ldl

all: alternate

clean:
	rm -f $(PROJ)

run:
	./run.sh

cpp_files = main.cpp src/Window.cpp src/EntireBackground.cpp src/Duck.cpp src/SDLHelpers.cpp

alternate: $(cpp_files)
	$(CXX) $(CXXFLAGS) $(INC) $(LIB_PATH) $(RPATH) -o $(PROJ) $(cpp_files) $(LINK_FLAGS)
