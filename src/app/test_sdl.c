#include <stdio.h>
#include <SDL/SDL.h>

int main (int argc, char const *argv[])
{
	printf("Testing sdl\n");
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

	return 0;
}