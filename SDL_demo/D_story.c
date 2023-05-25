#include "SDLlib.h"

void storyDisplay (SDL_Window* window, SDL_Renderer* renderer) {

	SDL_RenderClear(renderer);
	SDL_Surface* storySurface[2] = {NULL};
	SDL_Texture* storyTexture[2] = { NULL };
	SDL_Surface* redArrowSurface = NULL, *greenArrowSurface = NULL, *returnSurface = NULL , *returnAquaSur = NULL;
	SDL_Texture* redArrowTexture = NULL, *greenArrowTexture = NULL, *returnTexture = NULL , *returnAquaTex = NULL;
	// rect
	SDL_Rect rightRect, leftRect, returnRect;
	SDL_Rect fixScreen;  // 960 668
	rightRect.x = 714;
	rightRect.y = 481;
	rightRect.w = 73;
	rightRect.h = 55;

	leftRect.x = 206;
	leftRect.y = 480;
	leftRect.w = 74;
	leftRect.h = 55;

	returnRect.x = 450;
	returnRect.y = 503;

	fixScreen.x = -70;
	fixScreen.y = 0;
	fixScreen.w = 1110;
	fixScreen.h = 668;
	// others
	int page = 1;
	// load music
	Mix_Music* clickSound = Mix_LoadWAV("Sound/SoundEffects/click.wav");
	// load story image
	storySurface[0] = SDL_LoadBMP("Story/story1.bmp");
	storySurface[1] = SDL_LoadBMP("Story/story2.bmp");
	storyTexture[0] = SDL_CreateTextureFromSurface(renderer, storySurface[0]);
	storyTexture[1] = SDL_CreateTextureFromSurface(renderer, storySurface[1]);
	SDL_RenderCopy(renderer, storyTexture[0], NULL, &fixScreen);
	// load arrow
	redArrowSurface = SDL_LoadBMP("Story/red.bmp");
	redArrowTexture = SDL_CreateTextureFromSurface(renderer, redArrowSurface);
	greenArrowSurface = SDL_LoadBMP("Story/green.bmp");
	greenArrowTexture = SDL_CreateTextureFromSurface(renderer, greenArrowSurface);
	SDL_RenderCopy(renderer, greenArrowTexture, NULL, &rightRect);
	// load return button
	returnSurface = TTF_RenderText_Solid(font_Kanit_L24 , "Return", black);
	returnTexture = SDL_CreateTextureFromSurface(renderer, returnSurface);
	SDL_QueryTexture(returnTexture, NULL, NULL, &returnRect.w, &returnRect.h);
	SDL_RenderCopy(renderer, returnTexture, NULL, &returnRect);
	returnAquaSur = TTF_RenderText_Solid(font_Kanit_L24, "Return", aqua);
	returnAquaTex = SDL_CreateTextureFromSurface(renderer, returnAquaSur);
	// render
	SDL_RenderPresent(renderer);
	// free surface
	SDL_FreeSurface(storySurface[0]);
	storySurface[0] = NULL;
	SDL_FreeSurface(storySurface[1]);
	storySurface[1] = NULL;
	SDL_FreeSurface(redArrowSurface);
	redArrowSurface = NULL;
	SDL_FreeSurface(greenArrowSurface);
	greenArrowSurface = NULL;
	SDL_FreeSurface(returnSurface);
	returnSurface = NULL;
	SDL_FreeSurface(returnAquaSur);
	returnAquaSur = NULL;

	SDL_Event event;
	bool quit = false;
	while (!quit) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_MOUSEMOTION:
				if (event.motion.x >= rightRect.x && event.motion.x <= rightRect.x + rightRect.w &&
					event.motion.y >= rightRect.y && event.motion.y <= rightRect.y + rightRect.h) {
					if (page == 1) {
						SDL_RenderCopyEx(renderer, redArrowTexture, NULL, &rightRect, 0, NULL, 1);
						SDL_RenderPresent(renderer);
					}
				}
				else {
					if (page == 1) {
						SDL_RenderCopy(renderer, greenArrowTexture, NULL, &rightRect);
						SDL_RenderPresent(renderer);
					}
				}
				if (event.motion.x >= leftRect.x && event.motion.x <= leftRect.x + leftRect.w &&
					event.motion.y >= leftRect.y && event.motion.y <= leftRect.y + leftRect.h) {
					if (page == 2) {
						SDL_RenderCopyEx(renderer, redArrowTexture, NULL, &leftRect, 0, NULL, 0);
						SDL_RenderPresent(renderer);
					}
				}
				else {
					if (page == 2) {
						SDL_RenderCopyEx(renderer, greenArrowTexture, NULL, &leftRect, 0, NULL, 1);
						SDL_RenderPresent(renderer);
					}
				}
				// return button
				if (event.motion.x >= returnRect.x && event.motion.x <= returnRect.x + returnRect.w &&
					event.motion.y >= returnRect.y && event.motion.y <= returnRect.y + returnRect.h) {
					SDL_RenderCopy(renderer, returnAquaTex, NULL, &returnRect);
					SDL_RenderPresent(renderer);
				}
				else {
					SDL_RenderCopy(renderer, returnTexture, NULL, &returnRect);
					SDL_RenderPresent(renderer);
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.x >= rightRect.x && event.button.x <= rightRect.x + rightRect.w &&
					event.button.y >= rightRect.y && event.button.y <= rightRect.y + rightRect.h) {
					Mix_PlayChannel(-1, clickSound, 0);
					page = 2;
					// touch arrow 
					SDL_RenderClear(renderer);
					SDL_RenderCopy(renderer, storyTexture[1], NULL, &fixScreen);
					SDL_RenderCopyEx(renderer, greenArrowTexture, NULL, &leftRect, 0, NULL, 1);
					// return button
					SDL_RenderCopy(renderer, returnTexture, NULL, &returnRect);
					SDL_RenderPresent(renderer);
				}
				if (event.button.x >= leftRect.x && event.button.x <= leftRect.x + leftRect.w &&
					event.button.y >= leftRect.y && event.button.y <= leftRect.y + leftRect.h) {
					Mix_PlayChannel(-1, clickSound, 0);
					page = 1;
					// touch arrow 
					SDL_RenderClear(renderer);
					SDL_RenderCopy(renderer, storyTexture[0], NULL, &fixScreen);
					SDL_RenderCopyEx(renderer, greenArrowTexture, NULL, &rightRect, 0, NULL, 0);
					// return button
					SDL_RenderCopy(renderer, returnTexture, NULL, &returnRect);
					SDL_RenderPresent(renderer);
				}
				// click return
				if (event.button.x >= returnRect.x && event.button.x <= returnRect.x + returnRect.w &&
					event.button.y >= returnRect.y && event.button.y <= returnRect.y + returnRect.h) {
					Mix_PlayChannel(-1, clickSound, 0);
					SDL_DestroyTexture(returnTexture);
					returnTexture = NULL;
					SDL_DestroyTexture(returnAquaTex);
					returnAquaTex = NULL;
					SDL_DestroyTexture(redArrowTexture);
					redArrowTexture = NULL;
					SDL_DestroyTexture(greenArrowTexture);
					greenArrowTexture = NULL;
					SDL_DestroyTexture(storyTexture[0]);
					storyTexture[0] = NULL;
					SDL_DestroyTexture(storyTexture[1]);
					storyTexture[1] = NULL;
					SDL_RenderClear(renderer);
					renderer = NULL;
					return;
				}
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					SDL_DestroyTexture(returnTexture);
					returnTexture = NULL;
					SDL_DestroyTexture(returnAquaTex);
					returnAquaTex = NULL;
					SDL_DestroyTexture(redArrowTexture);
					redArrowTexture = NULL;
					SDL_DestroyTexture(greenArrowTexture);
					greenArrowTexture = NULL;
					SDL_DestroyTexture(storyTexture[0]);
					storyTexture[0] = NULL;
					SDL_DestroyTexture(storyTexture[1]);
					storyTexture[1] = NULL;
					SDL_RenderClear(renderer);
					renderer = NULL;
					return;
				}
				break;
			}

		}

	}
	SDL_DestroyTexture(returnTexture);
	returnTexture = NULL;
	SDL_DestroyTexture(returnAquaTex);
	returnAquaTex = NULL;
	SDL_DestroyTexture(redArrowTexture);
	redArrowTexture = NULL;
	SDL_DestroyTexture(greenArrowTexture);
	greenArrowTexture = NULL;
	SDL_DestroyTexture(storyTexture[0]);
	storyTexture[0] = NULL;
	SDL_DestroyTexture(storyTexture[1]);
	storyTexture[1] = NULL;
	SDL_RenderClear(renderer);
	renderer = NULL;
	return;
}