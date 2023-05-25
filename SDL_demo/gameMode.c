#include "SDLlib.h"

void gameMode(SDL_Window* window, SDL_Renderer* renderer, char selectMode[], int* ptrNumMode) {

	SDL_RenderClear(renderer);
	SDL_Surface* modeSurface = NULL, * returnSurface = NULL, * returnAquaSur = NULL, * bgSurface = NULL, * trickSurface = NULL, * textSurface = NULL;
	SDL_Texture* modeTexture = NULL, * returnTexture = NULL, * returnAquaTex = NULL, * bgTexture = NULL, * trickTexture = NULL, * textTexture = NULL;
	SDL_Surface* arrowSurface[2] = { NULL };
	SDL_Texture* arrowTexture[2] = { NULL };
	SDL_Surface* arrowRedSurface[2] = { NULL };
	SDL_Texture* arrowRedTexture[2] = { NULL };
	SDL_Color modeColor[3] = { {0 , 255 , 0 , 255} , { 255 , 200 , 0 , 255 } , { 255 , 0 , 0 , 255} };
	// rect
	SDL_Rect returnRect;
	SDL_Rect trickRect = { 390, 300 ,  190 , 70 };

	SDL_Rect textRect;
	textRect.x = 350;
	textRect.y = 130;

	SDL_Rect pos[2];
	pos[0].x = 310;   //  <<
	pos[0].y = 290;

	pos[1].x = 595;  // >>
	pos[1].y = 290;

	SDL_Rect modeRect[3];
	modeRect[0].x = 435; // easy
	modeRect[0].y = 265;

	modeRect[1].x = 415; // medium
	modeRect[1].y = 265;

	modeRect[2].x = 435; // hard
	modeRect[2].y = 265;
	// others
	char* arrow[2] = { "<<" , ">>" };
	char* mode[3] = { "Easy" , "Medium" , "Hard" };
	// load music
	Mix_Music* clickSound = Mix_LoadWAV("Sound/SoundEffects/click.wav");
	// load bg
	bgSurface = SDL_LoadBMP("LoginImage/gamemode.bmp");
	bgTexture = SDL_CreateTextureFromSurface(renderer, bgSurface);
	SDL_RenderCopy(renderer, bgTexture, NULL, NULL);
	trickSurface = SDL_LoadBMP("LoginImage/trick3.bmp");
	trickTexture = SDL_CreateTextureFromSurface(renderer, trickSurface);
	SDL_RenderCopy(renderer, trickTexture, NULL, &trickRect);
	// load return button
	returnSurface = TTF_RenderText_Solid(font_Kanit_L24, "Return", black);
	returnTexture = SDL_CreateTextureFromSurface(renderer, returnSurface);
	returnRect.x = 446;
	returnRect.y = 439;
	SDL_QueryTexture(returnTexture, NULL, NULL, &returnRect.w, &returnRect.h);
	SDL_RenderCopy(renderer, returnTexture, NULL, &returnRect);

	returnAquaSur = TTF_RenderText_Solid(font_Kanit_L24, "Return", aqua);
	returnAquaTex = SDL_CreateTextureFromSurface(renderer, returnAquaSur);
	// load arrow button
	for (int i = 0; i < 2; i++) {
		arrowSurface[i] = TTF_RenderText_Solid(font_Kanit_M60, arrow[i], black);
		arrowTexture[i] = SDL_CreateTextureFromSurface(renderer, arrowSurface[i]);
		SDL_QueryTexture(arrowTexture[i], NULL, NULL, &pos[i].w, &pos[i].h);
		SDL_RenderCopy(renderer, arrowTexture[i], NULL, &pos[i]);
	}
	for (int i = 0; i < 2; i++) {
		arrowRedSurface[i] = TTF_RenderText_Solid(font_Kanit_M60, arrow[i], red);
		arrowRedTexture[i] = SDL_CreateTextureFromSurface(renderer, arrowRedSurface[i]);
	}
	// load text "game mode"
	textSurface = TTF_RenderText_Solid(font_Pixel_100, "Game Mode", yellow);
	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_QueryTexture(textTexture, NULL, NULL, &textRect.w, &textRect.h);
	SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

	modeSurface = TTF_RenderText_Solid(font_Pixel_80, selectMode, modeColor[*(ptrNumMode)]);
	modeTexture = SDL_CreateTextureFromSurface(renderer, modeSurface);

	if (strcmp(selectMode, mode[0]) == 0) {
		SDL_QueryTexture(modeTexture, NULL, NULL, &modeRect[0].w, &modeRect[0].h);
		SDL_RenderCopy(renderer, modeTexture, NULL, &modeRect[0]);
		*(ptrNumMode) = 0;
	}
	else if (strcmp(selectMode, mode[1]) == 0) {
		SDL_QueryTexture(modeTexture, NULL, NULL, &modeRect[1].w, &modeRect[1].h);
		SDL_RenderCopy(renderer, modeTexture, NULL, &modeRect[1]);
		*(ptrNumMode) = 1;
	}
	else if (strcmp(selectMode, mode[2]) == 0) {
		SDL_QueryTexture(modeTexture, NULL, NULL, &modeRect[2].w, &modeRect[2].h);
		SDL_RenderCopy(renderer, modeTexture, NULL, &modeRect[2]);
		*(ptrNumMode) = 2;
	}

	SDL_RenderPresent(renderer);
	// free surface
	SDL_FreeSurface(returnSurface);
	returnSurface = NULL;
	SDL_FreeSurface(returnAquaSur);
	returnAquaSur = NULL;
	SDL_FreeSurface(bgSurface);
	bgSurface = NULL;
	SDL_FreeSurface(trickSurface);
	trickSurface = NULL;
	SDL_FreeSurface(textSurface);
	textSurface = NULL;
	for (int i = 0; i < 2; i++) {
		SDL_FreeSurface(arrowSurface[i]);
		arrowRedSurface[i] = NULL;
		SDL_FreeSurface(arrowRedSurface[i]);
		arrowRedSurface[i] = NULL;
	}

	SDL_Event event;
	bool quit = false;
	int x, y;

	while (!quit) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				SDL_DestroyTexture(modeTexture);
				modeTexture = NULL;
				SDL_DestroyTexture(returnTexture);
				returnTexture = NULL;
				SDL_DestroyTexture(returnAquaTex);
				returnAquaTex = NULL;
				SDL_DestroyTexture(bgTexture);
				bgTexture = NULL;
				SDL_DestroyTexture(trickTexture);
				trickTexture = NULL;
				SDL_DestroyTexture(textTexture);
				textTexture = NULL;
				SDL_FreeSurface(modeSurface);
				modeSurface = NULL;
				SDL_DestroyTexture(modeTexture);
				modeTexture = NULL;
				for (int i = 0; i < 2; i++) {
					SDL_DestroyTexture(arrowTexture[i]);
					arrowTexture[i] = NULL;
					SDL_DestroyTexture(arrowRedTexture[i]);
					arrowRedTexture[i] = NULL;
				}
				SDL_RenderClear(renderer);
				renderer = NULL;
				quit = true;
				return;
				break;
			case SDL_MOUSEMOTION:
				x = event.motion.x; y = event.motion.y;
				for (int i = 0; i < 2; i++) {
					if (x >= pos[i].x && x <= pos[i].x + pos[i].w &&
						y >= pos[i].y && y <= pos[i].y + pos[i].h) {
						SDL_RenderCopy(renderer, arrowRedTexture[i], NULL, &pos[i]);
						SDL_RenderPresent(renderer);
					}
					else {
						SDL_RenderCopy(renderer, arrowTexture[i], NULL, &pos[i]);
						SDL_RenderPresent(renderer);
					}
				}
				//
				if (x >= returnRect.x && x <= returnRect.x + returnRect.w &&
					y >= returnRect.y && y <= returnRect.y + returnRect.h) {
					SDL_RenderCopy(renderer, returnAquaTex, NULL, &returnRect);
					SDL_RenderPresent(renderer);
				}
				else {
					SDL_RenderCopy(renderer, returnTexture, NULL, &returnRect);
					SDL_RenderPresent(renderer);
				}

				break;
			case SDL_MOUSEBUTTONDOWN:
				x = event.button.x; y = event.button.y;
				if (x >= returnRect.x && x <= returnRect.x + returnRect.w &&
					y >= returnRect.y && y <= returnRect.y + returnRect.h) {
					Mix_PlayChannel(-1, clickSound, 0);
					SDL_DestroyTexture(modeTexture);
					modeTexture = NULL;
					SDL_DestroyTexture(returnTexture);
					returnTexture = NULL;
					SDL_DestroyTexture(returnAquaTex);
					returnAquaTex = NULL;
					SDL_DestroyTexture(bgTexture);
					bgTexture = NULL;
					SDL_DestroyTexture(trickTexture);
					trickTexture = NULL;
					SDL_DestroyTexture(textTexture);
					textTexture = NULL;
					SDL_FreeSurface(modeSurface);
					modeSurface = NULL;
					SDL_DestroyTexture(modeTexture);
					modeTexture = NULL;
					for (int i = 0; i < 2; i++) {
						SDL_DestroyTexture(arrowTexture[i]);
						arrowTexture[i] = NULL;
						SDL_DestroyTexture(arrowRedTexture[i]);
						arrowRedTexture[i] = NULL;
					}
					SDL_RenderClear(renderer);
					renderer = NULL;
					return;
				}

				if (x >= pos[0].x && x <= pos[0].x + pos[0].w &&  //  left arrow
					y >= pos[0].y && y <= pos[0].y + pos[0].h) {
					*(ptrNumMode) = *(ptrNumMode)-1;
					if (*(ptrNumMode) < 0) {
						*(ptrNumMode) = 2;
					}
					memset(selectMode, '\0', 10);
					strcpy(selectMode, mode[*(ptrNumMode)]);
					SDL_RenderCopy(renderer, trickTexture, NULL, &trickRect);
					SDL_RenderPresent(renderer);
					//free mode surface and texture
					SDL_FreeSurface(modeSurface);
					modeSurface = NULL;
					SDL_DestroyTexture(modeTexture);
					modeTexture = NULL;
					// apply new texture and surface
					modeSurface = TTF_RenderText_Solid(font_Pixel_80, selectMode, modeColor[*(ptrNumMode)]);
					modeTexture = SDL_CreateTextureFromSurface(renderer, modeSurface);
					SDL_QueryTexture(modeTexture, NULL, NULL, &modeRect[*(ptrNumMode)].w, &modeRect[*(ptrNumMode)].h);
					SDL_RenderCopy(renderer, modeTexture, NULL, &modeRect[*(ptrNumMode)]);

					SDL_RenderPresent(renderer);
				}

				if (x >= pos[1].x && x <= pos[1].x + pos[1].w &&  //  right arrow
					y >= pos[1].y && y <= pos[1].y + pos[1].h) {
					*(ptrNumMode) = *(ptrNumMode)+1;
					if (*(ptrNumMode) > 2) {
						*(ptrNumMode) = 0;
					}
					memset(selectMode, '\0', 10);
					strcpy(selectMode, mode[*(ptrNumMode)]);
					SDL_RenderCopy(renderer, trickTexture, NULL, &trickRect);
					SDL_RenderPresent(renderer); 
					// free
					SDL_FreeSurface(modeSurface);
					modeSurface = NULL;
					SDL_DestroyTexture(modeTexture);
					modeTexture = NULL;
					// apply new one
					modeSurface = TTF_RenderText_Solid(font_Pixel_80, selectMode, modeColor[*(ptrNumMode)]);
					modeTexture = SDL_CreateTextureFromSurface(renderer, modeSurface);
					SDL_QueryTexture(modeTexture, NULL, NULL, &modeRect[*(ptrNumMode)].w, &modeRect[*(ptrNumMode)].h);
					SDL_RenderCopy(renderer, modeTexture, NULL, &modeRect[*(ptrNumMode)]);

					SDL_RenderPresent(renderer);
				}
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					SDL_DestroyTexture(modeTexture);
					modeTexture = NULL;
					SDL_DestroyTexture(returnTexture);
					returnTexture = NULL;
					SDL_DestroyTexture(returnAquaTex);
					returnAquaTex = NULL;
					SDL_DestroyTexture(bgTexture);
					bgTexture = NULL;
					SDL_DestroyTexture(trickTexture);
					trickTexture = NULL;
					SDL_DestroyTexture(textTexture);
					textTexture = NULL;
					SDL_FreeSurface(modeSurface);
					modeSurface = NULL;
					SDL_DestroyTexture(modeTexture);
					modeTexture = NULL;
					for (int i = 0; i < 2; i++) {
						SDL_DestroyTexture(arrowTexture[i]);
						arrowTexture[i] = NULL;
						SDL_DestroyTexture(arrowRedTexture[i]);
						arrowRedTexture[i] = NULL;
					}
					SDL_RenderClear(renderer);
					renderer = NULL;
					return;
				}
				break;
			}
		}
	}

	SDL_DestroyTexture(modeTexture);
	modeTexture = NULL;
	SDL_DestroyTexture(returnTexture);
	returnTexture = NULL;
	SDL_DestroyTexture(returnAquaTex);
	returnAquaTex = NULL;
	SDL_DestroyTexture(bgTexture);
	bgTexture = NULL;
	SDL_DestroyTexture(trickTexture);
	trickTexture = NULL;
	SDL_DestroyTexture(textTexture);
	textTexture = NULL;
	SDL_FreeSurface(modeSurface);
	modeSurface = NULL;
	SDL_DestroyTexture(modeTexture);
	modeTexture = NULL;
	for (int i = 0; i < 2; i++) {
		SDL_DestroyTexture(arrowTexture[i]);
		arrowTexture[i] = NULL;
		SDL_DestroyTexture(arrowRedTexture[i]);
		arrowRedTexture[i] = NULL;
	}
	SDL_RenderClear(renderer);
	renderer = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
	return;
}