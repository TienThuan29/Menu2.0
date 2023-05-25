
#include <stdio.h>
#include "SDLlib.h"

SDL_Color red = { 255 , 0 , 0 ,255 };
SDL_Color black = { 0 , 0 , 0 , 255 };
SDL_Color yellow = { 0 , 200 , 255 , 255 };
SDL_Color aqua = { 0 , 255 , 255 , 255 };
SDL_Color white = { 255 , 255 , 255 , 255 };
SDL_Color orange = { 0  , 255 , 0 , 255 };
SDL_Color blue = { 0 , 0 , 255 , 255 };

TTF_Font* font_Pixel_50 = NULL; 
TTF_Font* font_Pixel_100 = NULL; 
TTF_Font* font_Pixel_80 = NULL;
TTF_Font* font_Kanit_L24 = NULL;
TTF_Font* font_Kanit_M60 = NULL;
TTF_Font* font_Kanit_M40 = NULL;
TTF_Font* font_Kanit_M23 = NULL;
TTF_Font* font_Kanit_MI24 = NULL;
TTF_Font* font_Kanit_MI30 = NULL;
TTF_Font* font_Kanit_L22 = NULL;
TTF_Font* font_Kanit_L20 = NULL;

int main(int argc, char* argv[]) {
    
    SDL_Window* window = NULL;
    SDL_Surface* screen = NULL;
    
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0); 

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    Mix_Music* music = Mix_LoadMUS("Sound/Soundtrack/MainMenu3.mp3");
    Mix_PlayMusic(music, -1);
    // init text font
    font_Pixel_50 = TTF_OpenFont("crazy-pixel.ttf", 50);
    font_Pixel_100 = TTF_OpenFont("crazy-pixel.ttf", 100);
    font_Pixel_80 = TTF_OpenFont("crazy-pixel.ttf", 80);
    font_Kanit_L24 = TTF_OpenFont("Kanit-Light.ttf", 24);
    font_Kanit_M60 = TTF_OpenFont("Kanit-Medium.ttf", 60);
    font_Kanit_M40 = TTF_OpenFont("Kanit-Medium.ttf", 40);
    font_Kanit_M23 = TTF_OpenFont("Kanit-Medium.ttf", 23);
    font_Kanit_MI24 = TTF_OpenFont("Kanit-MediumItalic.ttf", 24);
    font_Kanit_MI30 = TTF_OpenFont("Kanit-MediumItalic.ttf", 30);
    font_Kanit_L22 = TTF_OpenFont("Kanit-Light.ttf", 22);
    font_Kanit_L20 = TTF_OpenFont("Kanit-Light.ttf", 20);

    screen = SDL_GetWindowSurface(window);

    SDL_UpdateWindowSurface(window);

    SDL_Event e;

    bool quit = false;

    int i = 0;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) { quit = true;  }
        }
        
        SDL_DestroyWindow(window); 
        
        loginDisplay();
        
        quit = true;
        
    }
    SDL_Quit();
    return 0;
}

