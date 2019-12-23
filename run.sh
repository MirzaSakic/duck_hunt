if test -f "game" 
then
  if [ -d libSDL2/lib ] 
  then
    LD_LIBRARY_PATH=$(pwd)/libSDL2/lib/:$(pwd)/libcaf/release_dynamic_cpp_runtime/lib/ ./game
  else
    echo "Couldn't find directory sdl2/lib. Are you sure you're running script from the project root folder?"
  fi
else
  echo "Couldn't find executable \"game\". Did you run \"make\" command before running the game?" 
fi
