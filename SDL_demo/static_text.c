#include "SDLlib.h"

void getText(	SDL_Renderer* renderer,
				SDL_Surface *textSurface, 
				SDL_Texture* textTexture,   
				TTF_Font* font,
				char text[], 
				 int x , int y , SDL_Color color ) {

	SDL_Rect textRect;
	textRect.x = x;
	textRect.y = y;
	textSurface = TTF_RenderText_Solid(font , text , color); 
	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_QueryTexture(textTexture, NULL, NULL, &textRect.w, &textRect.h);
	SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
	SDL_RenderPresent(renderer);
	// free surface and texture
	SDL_FreeSurface(textSurface);
	textSurface = NULL;
	SDL_DestroyTexture(textTexture);
	textTexture = NULL;
}