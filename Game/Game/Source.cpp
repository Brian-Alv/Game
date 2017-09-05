#include <SDL.h>
#include <stdio.h>

using namespace std;

//Window Size
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[]) {

	///////////////////////////////////
	/* Declaring Necessary Variables */

	//The window to render to
	SDL_Window* window = NULL;

	//The surface to be put in the window
	SDL_Surface* windowSurface = NULL;

	

	/////////////////////////////////
	/* Initializing SDL Components */

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL_INIT_VIDEO FAILED! SDL_Error: %s\n", SDL_GetError());
	}
	else {
		//Create the window
		window = SDL_CreateWindow( "Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if (window == NULL) {
			printf("SDL_CreateWindow FAILED! SDL_Error: %s\n", SDL_GetError());
		}
		else {
			//Get window surface
			windowSurface = SDL_GetWindowSurface( window );

			//Fill in with white space
			SDL_FillRect(windowSurface, NULL, SDL_MapRGB(windowSurface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(window);

			//Wait three seconds before closing
			SDL_Delay(3000);
		}
	}

	//////////////////////////////
	/* Exitting the application */
	
	//Destroying the window
	SDL_DestroyWindow(window);

	//Quit all of SDL systems
	SDL_Quit();

	return 0;
}