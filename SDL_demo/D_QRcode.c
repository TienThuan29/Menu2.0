#include "SDLlib.h"

void QRcode(SDL_Window* window ,SDL_Renderer* renderer) {

	SDL_RenderClear(renderer);
	SDL_Surface* qrSurface = NULL, *bgSurface = NULL, *returnSurface = NULL, *returnAquaSur = NULL, *thankSurface = NULL, *logoSurface = NULL;
	SDL_Texture* qrTexture = NULL, *bgTexture = NULL, *returnTexture = NULL ,* returnAquaTex = NULL, *thankTextTure = NULL, *logoTexture = NULL;
	SDL_Rect textRect, thankRect;
	SDL_Rect qrRect = { 398 , 255 , 170 , 170 };
	SDL_Rect logoRect = { 328 , 300 , 60 , 60 };
	char thanks[50] = "";
	sprintf_s (thanks, sizeof(thanks), "^^Thank You For Your Donation^^");
	// load music
	Mix_Music* clickSound = Mix_LoadWAV("Sound/SoundEffects/click.wav");
	// load background
	bgSurface = SDL_LoadBMP("LoginImage/donate.bmp");
	bgTexture = SDL_CreateTextureFromSurface(renderer, bgSurface);
	SDL_RenderCopy(renderer, bgTexture , NULL, NULL);
	// load QR
	qrSurface = SDL_LoadBMP("LoginImage/QR.bmp");
	qrTexture = SDL_CreateTextureFromSurface(renderer, qrSurface);
	SDL_RenderCopy(renderer, qrTexture, NULL, &qrRect);
	// load logo 
	logoSurface = SDL_LoadBMP("LoginImage/momologo.bmp");
	logoTexture = SDL_CreateTextureFromSurface(renderer, logoSurface);
	SDL_RenderCopy(renderer, logoTexture, NULL, &logoRect);
	// return button
	returnSurface = TTF_RenderText_Solid(font_Kanit_L24 , "Return" , black);
	returnTexture = SDL_CreateTextureFromSurface(renderer, returnSurface);
	textRect.x = 447;
	textRect.y = 440;
	SDL_QueryTexture(returnTexture, NULL, NULL, &textRect.w, &textRect.h);
	SDL_RenderCopy(renderer, returnTexture, NULL, &textRect);
	returnAquaSur = TTF_RenderText_Solid(font_Kanit_L24, "Return", aqua);
	returnAquaTex = SDL_CreateTextureFromSurface(renderer, returnAquaSur);
	// load text
	thankSurface = TTF_RenderText_Solid(font_Kanit_MI30, thanks, orange);
	thankTextTure = SDL_CreateTextureFromSurface(renderer, thankSurface);
	thankRect.x = 247;
	thankRect.y = 200;
	SDL_QueryTexture(thankTextTure, NULL, NULL, &thankRect.w, &thankRect.h);
	SDL_RenderCopy(renderer, thankTextTure, NULL, &thankRect);
	// free surface
	SDL_FreeSurface(qrSurface);
	qrSurface = NULL;
	SDL_FreeSurface(bgSurface);
	bgSurface = NULL;
	SDL_FreeSurface(returnAquaSur);
	returnAquaSur = NULL;
	SDL_FreeSurface(returnSurface);
	returnSurface = NULL;
	SDL_FreeSurface(thankSurface);
	thankSurface = NULL;
	SDL_FreeSurface(logoSurface);
	logoSurface = NULL;
	//render
	SDL_RenderPresent(renderer);
	SDL_Event event;
	bool quit = false;
	while (!quit) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_MOUSEMOTION:
				if (event.motion.x >= textRect.x && event.motion.x <= textRect.x + textRect.w &&
					event.motion.y >= textRect.y && event.motion.y <= textRect.y + textRect.h) {
					SDL_RenderCopy(renderer, returnAquaTex, NULL, &textRect);
					SDL_RenderPresent(renderer);
				}
				else {
					SDL_RenderCopy(renderer, returnTexture, NULL, &textRect);
					SDL_RenderPresent(renderer);
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.x >= textRect.x && event.button.x <= textRect.x + textRect.w &&
					event.button.y >= textRect.y && event.button.y <= textRect.y + textRect.h) {
					Mix_PlayChannel(-1, clickSound, 0);
					SDL_DestroyTexture(bgTexture);
					bgTexture = NULL;
					SDL_DestroyTexture(thankTextTure);
					thankTextTure = NULL;
					SDL_DestroyTexture(returnTexture);
					returnTexture = NULL;
					SDL_DestroyTexture(returnAquaTex);
					returnAquaTex = NULL;
					SDL_DestroyTexture(qrTexture);
					qrTexture = NULL;
					SDL_DestroyTexture(logoTexture);
					logoTexture = NULL;
					SDL_RenderClear(renderer);
					renderer = NULL;
					return;
				}
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					SDL_DestroyTexture(bgTexture);
					bgTexture = NULL;
					SDL_DestroyTexture(thankTextTure);
					thankTextTure = NULL;
					SDL_DestroyTexture(returnTexture);
					returnTexture = NULL;
					SDL_DestroyTexture(returnAquaTex);
					returnAquaTex = NULL;
					SDL_DestroyTexture(qrTexture);
					qrTexture = NULL;
					SDL_DestroyTexture(logoTexture);
					logoTexture = NULL;
					SDL_RenderClear(renderer);
					renderer = NULL;
					return;
				}
				break;
			}
		}
	}
	SDL_DestroyTexture(bgTexture);
	bgTexture = NULL;
	SDL_DestroyTexture(thankTextTure);
	thankTextTure = NULL;
	SDL_DestroyTexture(returnTexture);
	returnTexture = NULL;
	SDL_DestroyTexture(returnAquaTex);
	returnAquaTex = NULL;
	SDL_DestroyTexture(qrTexture);
	qrTexture = NULL;
	SDL_DestroyTexture(logoTexture);
	logoTexture = NULL;
	SDL_RenderClear(renderer);
	renderer = NULL;
	return;
}