#ifndef SDL_LIBS
#define SDL_LIBS

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "color.h"
#include "text_font.h"

void accountDisplay();
void loginDisplay();
void registerDisplay();
int checkRepeatedUsername(char username[]);
int checkPassword(char username[], char pass[]);
void getText(SDL_Renderer* renderer,
    SDL_Surface* textSurface,
    SDL_Texture* textTexture,
    TTF_Font* font,
    char text[],
    int x, int y);
bool checkUsername(char username[]);
void writeIntoText(char username[], char password[]);
bool checkRepeatPassword(char pass[], char repeatPass[]);
void PreGameplay();
void helpDisplay(SDL_Window* window, SDL_Renderer* renderer);
void QRcode(SDL_Window* window, SDL_Renderer* renderer);
void storyDisplay(SDL_Window* window, SDL_Renderer* renderer);
void gameMode(SDL_Window* window, SDL_Renderer* renderer, char selectMode[], int* ptrNumMode);
void getHealthSurface(SDL_Surface* images[]);
void getGoodSurface(SDL_Surface* images[]);
void getRunningSurface(SDL_Surface* images[]);
void getJumpingSurface(SDL_Surface* images[]);
void clearSurface(SDL_Surface* surface[], int num);
void clearTexture(SDL_Texture* texture[], int num);
void getTexture(SDL_Renderer* renderer, SDL_Texture* imageTexture[], SDL_Surface* imageSurface[], int num);


#endif 