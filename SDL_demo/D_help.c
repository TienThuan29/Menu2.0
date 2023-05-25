#include "SDLlib.h"

SDL_Surface* helpSurface = NULL, * returnSurface = NULL, * returnAquaSur = NULL;
SDL_Texture* helpTexture = NULL, * returnTexture = NULL, * returnAquaTex = NULL;

SDL_Surface* healthSurface[7] = { NULL };
SDL_Texture* healthTexture[7] = { NULL };

SDL_Surface* goodSurface[8] = { NULL };
SDL_Texture* goodTexture[8] = { NULL };

SDL_Surface* runningSurface[8] = { NULL };
SDL_Texture* runningTexture[8] = { NULL };

SDL_Surface* jumpingSurface[5] = { NULL };
SDL_Texture* jumpingTexture[5] = { NULL };

SDL_Surface * fireSurface = NULL, * groundSurface = NULL, * lightningSurface = NULL, * sawSurface = NULL;
SDL_Texture * fireTexture = NULL, * groundTexture = NULL, * lightningTexture = NULL, * sawTexture = NULL;

SDL_Surface* ceilingSurface = NULL;
SDL_Texture* ceilingTexture = NULL;

SDL_Rect returnRect;
SDL_Rect healthRect, goodRect, runningRect, jumpingRect, ceilingRect, fireRect, groundRect , lightningRect, sawRect;
bool select = false;
void Render(SDL_Renderer* renderer) {

	SDL_RenderClear(renderer);
	// background
	SDL_RenderCopy(renderer, helpTexture, NULL, NULL);
	// return
	if (select == false)
		SDL_RenderCopy(renderer, returnTexture, NULL, &returnRect);
	else 
		SDL_RenderCopy(renderer, returnAquaTex, NULL, &returnRect);
	// object
	SDL_RenderCopy(renderer, lightningTexture, NULL, &lightningRect);
	SDL_RenderCopy(renderer, groundTexture, NULL, &groundRect);
	SDL_RenderCopy(renderer, fireTexture, NULL, &fireRect);
	SDL_RenderCopy(renderer, sawTexture, NULL, &sawRect);

	size_t animation_health = SDL_GetTicks64() / 120;
	int k = animation_health % 7;
	SDL_RenderCopy(renderer, healthTexture[k], NULL, &healthRect);

	size_t animation_good = SDL_GetTicks64() / 120;
	int i = animation_good % 8;
	SDL_RenderCopy(renderer, goodTexture[i], NULL, &goodRect);

	size_t animation_running = SDL_GetTicks64() / 120;
	int j = animation_running % 8;
	SDL_RenderCopy(renderer, runningTexture[j], NULL, &runningRect);

	size_t animation_jumping = SDL_GetTicks64() / 200;
	int h = animation_jumping % 5;
	SDL_RenderCopy(renderer, jumpingTexture[h], NULL, &jumpingRect);

	SDL_RenderCopy(renderer, ceilingTexture, NULL, &ceilingRect);

	SDL_RenderPresent(renderer);
}

void helpDisplay(SDL_Window* window, SDL_Renderer* renderer) {
	//rect
	returnRect.x = 446;
	returnRect.y = 503;

	healthRect.x = 550;
	healthRect.y = 302;
	healthRect.w = 40;
	healthRect.h = 40;

	goodRect.x = 460;
	goodRect.y = 365;
	goodRect.w = 40;
	goodRect.h = 40;

	runningRect.x = 500;
	runningRect.y = 130;
	runningRect.w = 35;
	runningRect.h = 65;

	jumpingRect.x = 430;
	jumpingRect.y = 214;
	jumpingRect.w = 35;
	jumpingRect.h = 65;

	ceilingRect.x = 610;
	ceilingRect.y = 410;
	ceilingRect.w = 60;
	ceilingRect.h = 50;

	fireRect.x = 670;
	fireRect.y = 370;
	fireRect.w = 55;
	fireRect.h = 90;

	sawRect.x = 720;
	sawRect.y = 410;
	sawRect.w = 50;
	sawRect.h = 50;

	groundRect.x = 750;
	groundRect.y = 410;
	groundRect.w = 70;
	groundRect.h = 50;

	lightningRect.x = 793;
	lightningRect.y = 400;
	lightningRect.w = 70;
	lightningRect.h = 60;
	// load music
	Mix_Music* clickSound = Mix_LoadWAV("Sound/SoundEffects/click.wav");
	// load bachground
	helpSurface = SDL_LoadBMP("LoginImage/help.bmp");
	helpTexture = SDL_CreateTextureFromSurface(renderer, helpSurface);
	SDL_RenderCopy(renderer, helpTexture, NULL, NULL);
	// ceiling , fire , saw , ground , lightning 
	fireSurface = SDL_LoadBMP("traps/fire.bmp");
	fireTexture = SDL_CreateTextureFromSurface(renderer, fireSurface);

	sawSurface = SDL_LoadBMP("traps/saw.bmp");
	sawTexture = SDL_CreateTextureFromSurface(renderer, sawSurface);

	groundSurface = SDL_LoadBMP("traps/ground.bmp");
	groundTexture = SDL_CreateTextureFromSurface(renderer, groundSurface);

	lightningSurface = SDL_LoadBMP("traps/lightning.bmp");
	lightningTexture = SDL_CreateTextureFromSurface(renderer, lightningSurface);

	ceilingSurface = SDL_LoadBMP("traps/ceiling.bmp");
	ceilingTexture = SDL_CreateTextureFromSurface(renderer, ceilingSurface);

	// load return button
	returnSurface = TTF_RenderText_Solid(font_Kanit_L24, "Return", black);
	returnTexture = SDL_CreateTextureFromSurface(renderer, returnSurface);
	SDL_QueryTexture(returnTexture, NULL, NULL, &returnRect.w, &returnRect.h);
	SDL_RenderCopy(renderer, returnTexture, NULL, &returnRect);

	returnAquaSur = TTF_RenderText_Solid(font_Kanit_L24, "Return", aqua);
	returnAquaTex = SDL_CreateTextureFromSurface(renderer, returnAquaSur);

	// get surface
	getHealthSurface(healthSurface);
	getGoodSurface(goodSurface);
	getJumpingSurface(jumpingSurface);
	getRunningSurface(runningSurface);

	// get texture
	getTexture(renderer, healthTexture, healthSurface, 7);
	getTexture(renderer, goodTexture, goodSurface, 8);
	getTexture(renderer, runningTexture, runningSurface, 8);
	getTexture(renderer, jumpingTexture, jumpingSurface, 5);

	//clear surface
	SDL_FreeSurface(helpSurface);
	helpSurface = NULL;
	SDL_FreeSurface(returnSurface);
	returnSurface = NULL;
	SDL_FreeSurface(returnAquaSur);
	returnAquaSur = NULL;
	SDL_FreeSurface(fireSurface);
	fireSurface = NULL;
	SDL_FreeSurface(groundSurface);
	groundSurface = NULL;
	SDL_FreeSurface(lightningSurface);
	lightningSurface = NULL;
	SDL_FreeSurface(sawSurface);
	sawSurface = NULL;
	SDL_FreeSurface(ceilingSurface);
	ceilingSurface = NULL;
	clearSurface(healthSurface,7);
	clearSurface(runningSurface,8);
	clearSurface(goodSurface,8);
	clearSurface(jumpingSurface,5);

	SDL_Event event;
	bool quit = false;
	while (!quit) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_MOUSEMOTION:
				if (event.motion.x >= returnRect.x && event.motion.x <= returnRect.x + returnRect.w &&
					event.motion.y >= returnRect.y && event.motion.y <= returnRect.y + returnRect.h) {
					select = true;
				}
				else {
					select = false;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.x >= returnRect.x && event.button.x <= returnRect.x + returnRect.w &&
					event.button.y >= returnRect.y && event.button.y <= returnRect.y + returnRect.h) {
					Mix_PlayChannel(-1, clickSound, 0);
					SDL_DestroyTexture(helpTexture);
					SDL_DestroyTexture(returnTexture);
					clearTexture(healthTexture, 7);
					clearTexture(goodTexture, 8);
					clearTexture(runningTexture, 8);
					clearTexture(jumpingTexture, 5);
					SDL_DestroyTexture(fireTexture);
					fireTexture = NULL;
					SDL_DestroyTexture(groundTexture);
					groundTexture = NULL;
					SDL_DestroyTexture(lightningTexture);
					lightningTexture = NULL;
					SDL_DestroyTexture(sawTexture);
					sawTexture = NULL;
					SDL_DestroyTexture(ceilingTexture);
					ceilingTexture = NULL;
					SDL_RenderClear(renderer);
					renderer = NULL;
					return;
				}
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					// clear texture
					SDL_DestroyTexture(helpTexture);
					SDL_DestroyTexture(returnTexture);
					clearTexture(healthTexture, 7);
					clearTexture(goodTexture, 8);
					clearTexture(runningTexture, 8);
					clearTexture(jumpingTexture, 5);
					SDL_DestroyTexture(fireTexture);
					fireTexture = NULL;
					SDL_DestroyTexture(groundTexture);
					groundTexture = NULL;
					SDL_DestroyTexture(lightningTexture);
					lightningTexture = NULL;
					SDL_DestroyTexture(sawTexture);
					sawTexture = NULL;
					SDL_DestroyTexture(ceilingTexture);
					ceilingTexture = NULL;
					SDL_RenderClear(renderer);
					renderer = NULL;
					return;
				}
				break;

			}
		}
		Render(renderer);
	}
	
	// clear texture
	SDL_DestroyTexture(helpTexture);
	SDL_DestroyTexture(returnTexture);
	clearTexture(healthTexture, 7);
	clearTexture(goodTexture, 8);
	clearTexture(runningTexture, 8);
	clearTexture(jumpingTexture, 5);
	SDL_DestroyTexture(fireTexture);
	fireTexture = NULL;
	SDL_DestroyTexture(groundTexture);
	groundTexture = NULL;
	SDL_DestroyTexture(lightningTexture);
	lightningTexture = NULL;
	SDL_DestroyTexture(sawTexture);
	sawTexture = NULL;
	SDL_DestroyTexture(ceilingTexture);
	ceilingTexture = NULL;
	SDL_RenderClear(renderer);
	renderer = NULL;
	SDL_Quit();
	TTF_Quit();
	return;
}