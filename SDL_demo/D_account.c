#include "SDLlib.h"

char selectMode[10] = "Easy";   // global variable 
int numMode = 0;
int* ptrNumMode = &numMode;

void accountDisplay() {

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;		
	SDL_Surface* menuSurface[6] = { NULL };
	SDL_Texture* menuTexture[6] = { NULL };
	SDL_Surface* menuRedSurface[6] = { NULL };
	SDL_Texture* menuRedTexture[6] = { NULL };
	SDL_Surface* bgSurface = NULL;
	SDL_Texture* bgTexture = NULL;

	const char* labels[6] = { "Single Player" , "Story" , "Game Mode" , "Help" , "Donate" , "Exit" };
	bool selected[6] = { 0 };
	SDL_Rect pos[6];

	pos[0].x = 400; // single player
	pos[0].y = 170;

	pos[1].x = 440;  // story
	pos[1].y = 225;

	pos[2].x = 410;  // game mode
	pos[2].y = 280;

	pos[3].x = 450;  // help
	pos[3].y = 335;

	pos[4].x = 430;   //donate
	pos[4].y = 390;

	pos[5].x = 450;  // exit
	pos[5].y = 445;

	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	window = SDL_CreateWindow("Menu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 960, 668, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	// load music
	Mix_Music* clickSound = Mix_LoadWAV("Sound/SoundEffects/click.wav");
	// begin load
	BEGIN:
	// load background
	bgSurface = SDL_LoadBMP("LoginImage/ChooseBG.bmp");
	bgTexture = SDL_CreateTextureFromSurface(renderer, bgSurface);
	SDL_RenderCopy(renderer, bgTexture, NULL, NULL);
	// load options in menu
	for (int i = 0; i < 6; i++) {
		menuSurface[i] = TTF_RenderText_Solid(font_Pixel_50, labels[i], black);
		menuRedSurface[i] = TTF_RenderText_Solid(font_Pixel_50, labels[i], red);
	}
	for (int i = 0; i < 6; i++) {
		menuTexture[i] = SDL_CreateTextureFromSurface(renderer, menuSurface[i]);
		menuRedTexture[i] = SDL_CreateTextureFromSurface(renderer, menuRedSurface[i]);
		SDL_QueryTexture(menuTexture[i], NULL, NULL, &pos[i].w, &pos[i].h);
		SDL_QueryTexture(menuRedTexture[i], NULL, NULL, &pos[i].w, &pos[i].h);
		SDL_RenderCopy(renderer, menuTexture[i], NULL, &pos[i]);
	}
	SDL_RenderPresent(renderer);
	// free surface
	SDL_FreeSurface(bgSurface);
	bgSurface = NULL;
	for (int i = 0; i < 6; i++) {
		SDL_FreeSurface(menuSurface[i]);
		menuSurface[i] = NULL;
		SDL_FreeSurface(menuRedSurface[i]);
		menuRedSurface[i] = NULL;
	}

	int x, y;
	SDL_Event event;
	bool quit = false;
	while (!quit) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				SDL_DestroyTexture(bgTexture);
				bgTexture = NULL;
				for (int i = 0; i < 6; i++) {
					SDL_DestroyTexture(menuTexture[i]);
					menuTexture[i] = NULL;
					SDL_DestroyTexture(menuRedTexture[i]);
					menuRedTexture[i] = NULL;
				}
				quit = true;
				break;
			case SDL_MOUSEMOTION:
				x = event.motion.x; y = event.motion.y;
				for (int i = 0; i < 6; i++) {
					if (x >= pos[i].x && x <= pos[i].x + pos[i].w &&
						y >= pos[i].y && y <= pos[i].y + pos[i].h) {
						selected[i] = true;
						SDL_RenderCopy(renderer, menuRedTexture[i], NULL, &pos[i]);
						SDL_RenderPresent(renderer);
					}
					else {
						selected[i] = false;
						SDL_RenderCopy(renderer, menuTexture[i], NULL, &pos[i]);
						SDL_RenderPresent(renderer);
					}
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				x = event.button.x; y = event.button.y;
				if (x >= pos[5].x && x <= pos[5].x + pos[5].w &&
					y >= pos[5].y && y <= pos[5].y + pos[5].h) {
					Mix_PlayChannel(-1 , clickSound , 0);
					SDL_DestroyTexture(bgTexture);
					bgTexture = NULL;
					for (int i = 0; i < 6; i++) {
						SDL_DestroyTexture(menuTexture[i]);
						menuTexture[i] = NULL;
						SDL_DestroyTexture(menuRedTexture[i]);
						menuRedTexture[i] = NULL;
					}
					SDL_DestroyRenderer(renderer);
					renderer = NULL;
					SDL_DestroyWindow(window);
					window = NULL;
					loginDisplay();
					return;
				}
				if (x >= pos[4].x && x <= pos[4].x + pos[4].w &&
					y >= pos[4].y && y <= pos[4].y + pos[4].h) {
					Mix_PlayChannel(-1, clickSound, 0);
					SDL_DestroyTexture(bgTexture);
					bgTexture = NULL;
					for (int i = 0; i < 6; i++) {
						SDL_DestroyTexture(menuTexture[i]);
						menuTexture[i] = NULL;
						SDL_DestroyTexture(menuRedTexture[i]);
						menuRedTexture[i] = NULL;
					}
					SDL_RenderClear(renderer);
					QRcode(window , renderer);
					goto BEGIN;
				}
				if (x >= pos[2].x && x <= pos[2].x + pos[2].w &&
					y >= pos[2].y && y <= pos[2].y + pos[2].h) {
					Mix_PlayChannel(-1, clickSound, 0);
					SDL_DestroyTexture(bgTexture);
					bgTexture = NULL;
					for (int i = 0; i < 6; i++) {
						SDL_DestroyTexture(menuTexture[i]);
						menuTexture[i] = NULL;
						SDL_DestroyTexture(menuRedTexture[i]);
						menuRedTexture[i] = NULL;
					}
					SDL_RenderClear(renderer);
					gameMode(window, renderer, selectMode, ptrNumMode);
					goto BEGIN;
				}
				if (x >= pos[1].x && x <= pos[1].x + pos[1].w &&
					y >= pos[1].y && y <= pos[1].y + pos[1].h) {
					Mix_PlayChannel(-1, clickSound, 0);
					SDL_DestroyTexture(bgTexture);
					bgTexture = NULL;
					for (int i = 0; i < 6; i++) {
						SDL_DestroyTexture(menuTexture[i]);
						menuTexture[i] = NULL;
						SDL_DestroyTexture(menuRedTexture[i]);
						menuRedTexture[i] = NULL;
					}
					SDL_RenderClear(renderer);
					storyDisplay(window, renderer);
					goto BEGIN;
				}
				if (x >= pos[3].x && x <= pos[3].x + pos[3].w &&
					y >= pos[3].y && y <= pos[3].y + pos[3].h) {
					Mix_PlayChannel(-1, clickSound, 0);
					SDL_DestroyTexture(bgTexture);
					bgTexture = NULL;
					for (int i = 0; i < 6; i++) {
						SDL_DestroyTexture(menuTexture[i]);
						menuTexture[i] = NULL;
						SDL_DestroyTexture(menuRedTexture[i]);
						menuRedTexture[i] = NULL;
					}
					SDL_RenderClear(renderer);
					helpDisplay(window, renderer);
					goto BEGIN;
				}
				if (x >= pos[0].x && x <= pos[0].x + pos[0].w &&
					y >= pos[0].y && y <= pos[0].y + pos[0].h) {
					Mix_PlayChannel(-1, clickSound, 0);
					SDL_DestroyTexture(bgTexture);
					bgTexture = NULL;
					for (int i = 0; i < 6; i++) {
						SDL_DestroyTexture(menuTexture[i]);
						menuTexture[i] = NULL;
						SDL_DestroyTexture(menuRedTexture[i]);
						menuRedTexture[i] = NULL;
					}
					Mix_HaltMusic();
					SDL_RenderClear(renderer);
					SDL_DestroyWindow(window);
					PreGameplay();
					// preGamePlay -> in game
				}
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					SDL_DestroyTexture(bgTexture);
					bgTexture = NULL;
					for (int i = 0; i < 6; i++) {
						SDL_DestroyTexture(menuTexture[i]);
						menuTexture[i] = NULL;
						SDL_DestroyTexture(menuRedTexture[i]);
						menuRedTexture[i] = NULL;
					}
					SDL_DestroyRenderer(renderer);
					renderer = NULL;
					SDL_DestroyWindow(window);
					window = NULL;
					loginDisplay();
					return;
				}
				break;
			}

		}

	}

	SDL_DestroyTexture(bgTexture);
	bgTexture = NULL;
	for (int i = 0; i < 6; i++) {
		SDL_DestroyTexture(menuTexture[i]);
		menuTexture[i] = NULL;
		SDL_DestroyTexture(menuRedTexture[i]);
		menuRedTexture[i] = NULL;
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	TTF_Quit();
	return;
}

