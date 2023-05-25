#include <SDL.h>
#include <SDL_image.h>
#include <string.h>
#include <stdio.h> 

// health object
void getHealthSurface(SDL_Surface* images[]) {
	for (int i = 0; i < 7; i++) {
		char filename[30] = "";
		sprintf_s(filename, sizeof(filename), "item/health%d.bmp", i + 1);
		//printf("%s\n", filename);
		images[i] = SDL_LoadBMP(filename);
		SDL_SetColorKey(images[i], SDL_TRUE, SDL_MapRGB(images[i]->format, 0, 0, 0));
	}
}

// good ending object
void getGoodSurface(SDL_Surface* images[]) { 
	for (int i = 0; i < 8; i++) {
		char filename[30] = "";
		sprintf_s(filename, sizeof(filename), "item/good%d.bmp", i + 1);
		//printf("%s\n", filename);
		images[i] = SDL_LoadBMP(filename);
		SDL_SetColorKey(images[i], SDL_TRUE, SDL_MapRGB(images[i]->format, 0, 0, 0));
	}
}


void getRunningSurface(SDL_Surface* images[]) { 
	for (int i = 0; i < 8; i++) {
		char filename[30] = "";
		sprintf_s(filename, sizeof(filename), "running/run%d.bmp", i + 1);
		//printf("%s\n", filename);
		images[i] = SDL_LoadBMP(filename);
	}
}

void getJumpingSurface(SDL_Surface* images[]) {
	for (int i = 0; i < 5; i++) {
		char filename[30] = "";
		sprintf_s(filename, sizeof(filename), "jump/jump%d.bmp", i + 1);
		//printf("%s\n", filename);
		images[i] = SDL_LoadBMP(filename);
	}
}

void getTexture(SDL_Renderer* renderer, SDL_Texture* imageTexture[], SDL_Surface* imageSurface[], int num) {
	for (int i = 0; i < num; i++) {
		imageTexture[i] = SDL_CreateTextureFromSurface(renderer, imageSurface[i]);
	}
}

void clearSurface(SDL_Surface* surface[], int num) {
	for (int i = 0; i < num; i++) {
		SDL_FreeSurface(surface[i]);
		surface[i] = NULL;
	}
}

void clearTexture(SDL_Texture* texture[], int num) {
	for (int i = 0; i < num; i++) {
		SDL_DestroyTexture(texture[i]);
		texture[i] = NULL;
	}
}