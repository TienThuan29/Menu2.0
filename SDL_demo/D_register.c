#include "SDLlib.h"

void registerDisplay() {
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Surface* imageSurface = NULL , *trickSurface = NULL;
	SDL_Texture* imageTexture = NULL , *trickTexture = NULL; 
	SDL_Surface* textSurface = NULL;
	SDL_Texture* textTexture  = NULL; 
	SDL_Surface* returnSurface = NULL , *returnAquaSur = NULL , * registerSurface = NULL , *registerRedSur = NULL;
	SDL_Texture* returnTexture = NULL , *returnAquaTex = NULL , * registerTexture = NULL , *registerRedTex = NULL; 
	SDL_Surface* temp = NULL, *temp2 = NULL, *temp3 = NULL, *bar = NULL;
	SDL_Texture* barTexture = NULL, *userTexture = NULL, *passTexture = NULL, *repeatTexture = NULL; 
	SDL_Surface* informSurface = NULL;
	SDL_Texture* informTexture = NULL;
	SDL_Surface* arrowSurface = NULL;
	SDL_Texture* arrowTexture = NULL;
	SDL_Surface* delete3Surface = NULL, * delete4Surface = NULL, * delete5Surface = NULL;
	SDL_Texture* delete3Texture = NULL, * delete4Texture = NULL, * delete5Texture = NULL;  
	//rect
	SDL_Rect delete3Rect, delete4Rect, delete5Rect;
	SDL_Rect returnRect, registerRect;
	SDL_Rect userRect; 
	userRect.x = 313;
	userRect.y = 231;

	SDL_Rect passRect; 
	passRect.x = 313;
	passRect.y = 305;

	SDL_Rect repeatRect;
	repeatRect.x = 313;
	repeatRect.y = 379;

	SDL_Rect arrowRect1;
	arrowRect1.x = 670;
	arrowRect1.y = 238;
	arrowRect1.w = 24;
	arrowRect1.h = 24;

	SDL_Rect arrowRect2;
	arrowRect2.x = 670;
	arrowRect2.y = 313;
	arrowRect2.w = 24;
	arrowRect2.h = 24;

	SDL_Rect arrowRect3;
	arrowRect3.x = 670;
	arrowRect3.y = 388;
	arrowRect3.w = 24;
	arrowRect3.h = 24;

	delete3Rect.x = 665;
	delete3Rect.y = 238;
	delete3Rect.w = 45;
	delete3Rect.h = 24;

	delete4Rect.x = 665;
	delete4Rect.y = 313;
	delete4Rect.w = 43;
	delete4Rect.h = 30;

	delete5Rect.x = 670;
	delete5Rect.y = 388;
	delete5Rect.w = 24;
	delete5Rect.h = 24;

	SDL_Rect accessUser = { 309 , 236 , 345 , 28 };
	SDL_Rect accessPass = { 309 , 310 , 345 , 28 };
	SDL_Rect accessRepeat = { 309 , 384 , 345 , 28 };

	SDL_Rect trick2Rect;
	trick2Rect.x = 195;
	trick2Rect.y = 520;
	trick2Rect.w = 580;
	trick2Rect.h = 50; // 46
	// others
	char username[21] = { NULL };
	char password[25] = { NULL };
	char repeatPass[25] = { NULL };
	int x = 0, y = 0;
	int lengthUser = 0, lengthPass = 0, lengthRepeat = 0;;
	//init
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	window = SDL_CreateWindow("Register Display", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 960, 668, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	// load music
	Mix_Music* clickSound = Mix_LoadWAV("Sound/SoundEffects/click.wav"); 
	//load background
	imageSurface = SDL_LoadBMP("LoginImage/RegisterBG.bmp");
	imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
	SDL_RenderCopy(renderer, imageTexture, NULL, NULL);
	SDL_RenderPresent(renderer);
	// fix background
	imageSurface = SDL_LoadBMP("LoginImage/trick2.bmp");
	imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
	SDL_RenderCopy(renderer, imageTexture, NULL, &trick2Rect);
	// load static text
	char text[20] = "Enter Username";
	x = 305;
	y = 202;
	getText(renderer, textSurface, textTexture, font_Kanit_MI24, text, x, y, black);

	char text2[20] = "Enter Password";
	x = 305;
	y = 276;
	getText(renderer, textSurface, textTexture, font_Kanit_MI24, text2, x, y, black);

	char text3[20] = "Repeat Password";
	x = 305;
	y = 350;
	getText(renderer , textSurface , textTexture , font_Kanit_MI24 , text3 , x , y, black);
	// load return button
	returnSurface = TTF_RenderText_Solid(font_Kanit_L24, "Return", black);
	returnTexture = SDL_CreateTextureFromSurface(renderer, returnSurface);
	SDL_QueryTexture(returnTexture, NULL, NULL, &returnRect.w, &returnRect.h);
	returnRect.x = 358;
	returnRect.y = 439;
	SDL_RenderCopy(renderer, returnTexture, NULL, &returnRect);

	returnAquaSur = TTF_RenderText_Solid(font_Kanit_L24, "Return", aqua);
	returnAquaTex = SDL_CreateTextureFromSurface(renderer, returnAquaSur);
	// load register button
	registerSurface = TTF_RenderText_Solid(font_Kanit_L24, "Register", black);
	registerTexture = SDL_CreateTextureFromSurface(renderer, registerSurface);
	SDL_QueryTexture(registerTexture, NULL, NULL, &registerRect.w, &registerRect.h);
	registerRect.x = 523;
	registerRect.y = 439;
	SDL_RenderCopy(renderer, registerTexture, NULL, &registerRect);

	registerRedSur = TTF_RenderText_Solid(font_Kanit_L24, "Register", red);
	registerRedTex = SDL_CreateTextureFromSurface(renderer, registerRedSur);
	// load arrow
	arrowSurface = SDL_LoadBMP("LoginImage/arrow.bmp");
	arrowTexture = SDL_CreateTextureFromSurface(renderer, arrowSurface);
	// load delete fon
	delete3Surface = SDL_LoadBMP("LoginImage/delete3.bmp");
	delete3Texture = SDL_CreateTextureFromSurface(renderer, delete3Surface);
	SDL_RenderCopy(renderer, delete3Texture, NULL, &delete3Rect);

	delete4Surface = SDL_LoadBMP("LoginImage/delete4.bmp");
	delete4Texture = SDL_CreateTextureFromSurface(renderer, delete4Surface);
	SDL_RenderCopy(renderer, delete4Texture, NULL, &delete4Rect);

	delete5Surface = SDL_LoadBMP("LoginImage/delete5.bmp");
	delete5Texture = SDL_CreateTextureFromSurface(renderer, delete5Surface);
	SDL_RenderCopy(renderer, delete5Texture, NULL, &delete5Rect);

	trickSurface = SDL_LoadBMP("LoginImage/trick2.bmp");
	trickTexture = SDL_CreateTextureFromSurface(renderer, trickSurface);

	bar = SDL_LoadBMP("LoginImage/bar.bmp");
	barTexture = SDL_CreateTextureFromSurface(renderer, bar);
	
	SDL_RenderPresent(renderer);
	// free surface
	SDL_FreeSurface(imageSurface);
	imageSurface = NULL;
	SDL_FreeSurface(trickSurface);
	trickSurface = NULL;
	SDL_FreeSurface(textSurface);
	textSurface = NULL;
	SDL_FreeSurface(returnSurface);
	returnSurface = NULL;
	SDL_FreeSurface(returnAquaSur);
	returnAquaSur = NULL;
	SDL_FreeSurface(registerSurface);
	registerSurface = NULL;
	SDL_FreeSurface(registerRedSur);
	registerRedSur = NULL;
	SDL_FreeSurface(bar);
	bar = NULL;
	SDL_FreeSurface(arrowSurface);
	arrowSurface = NULL;
	SDL_FreeSurface(delete3Surface);
	delete3Surface = NULL;
	SDL_FreeSurface(delete4Surface);
	delete4Surface = NULL;
	SDL_FreeSurface(delete5Surface);
	delete5Surface = NULL;
	// running
	SDL_StartTextInput();
	SDL_Event event;
	bool quit = false;
	while (!quit) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) { 
				quit = true; 
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN) {
				// access Username
				if (event.button.x >= accessUser.x && event.button.x <= accessUser.x + 345 &&
					event.button.y >= accessUser.y && event.button.y <= accessUser.y + 28) {
					SDL_RenderCopy(renderer, trickTexture, NULL, &trick2Rect);
					// delete arrow at pass
					SDL_RenderCopy(renderer, delete4Texture, NULL, &delete4Rect);
					// delete arrow at repeat pass
					SDL_RenderCopy(renderer, delete5Texture, NULL, &delete5Rect);
					// render arrow 
					SDL_RenderCopy(renderer, arrowTexture, NULL, &arrowRect1);
					SDL_RenderPresent(renderer);
					bool outUser = false;
					SDL_Event event2;
					while (!outUser) {
						while (SDL_PollEvent(&event2)) {
							if (event2.type == SDL_QUIT) {
								outUser = true;
								quit = 1;
							}
							if (event2.type == SDL_MOUSEBUTTONDOWN) {
								if (event2.button.x >= returnRect.x && event2.button.x <= returnRect.x + returnRect.w &&
									event2.button.y >= returnRect.y && event2.button.y <= returnRect.y + returnRect.h) {
									Mix_PlayChannel(-1, clickSound, 0);
									SDL_StopTextInput();
									SDL_DestroyTexture(imageTexture);
									imageTexture = NULL;
									SDL_DestroyTexture(trickTexture);
									trickTexture = NULL;
									SDL_DestroyTexture(textTexture);
									textTexture = NULL;
									SDL_DestroyTexture(returnTexture);
									returnTexture = NULL;
									SDL_DestroyTexture(returnAquaTex);
									returnAquaTex = NULL;
									SDL_DestroyTexture(registerTexture);
									registerTexture = NULL;
									SDL_DestroyTexture(registerRedTex);
									registerRedTex = NULL;
									SDL_DestroyTexture(barTexture);
									barTexture = NULL;
									SDL_DestroyTexture(userTexture);
									userTexture = NULL;
									SDL_DestroyTexture(passTexture);
									passTexture = NULL;
									SDL_DestroyTexture(repeatTexture);
									repeatTexture = NULL;
									SDL_DestroyTexture(informTexture);
									informTexture = NULL;
									SDL_DestroyTexture(arrowTexture);
									arrowTexture = NULL;
									SDL_DestroyTexture(delete3Texture);
									delete3Texture = NULL;
									SDL_DestroyTexture(delete4Texture);
									delete4Texture = NULL;
									SDL_DestroyTexture(delete5Texture);
									delete5Texture = NULL;
									SDL_DestroyRenderer(renderer);
									renderer = NULL;
									SDL_DestroyWindow(window);
									window = NULL;
									loginDisplay();
									return;
								}
								if (event2.button.x >= registerRect.x && event2.button.x <= registerRect.x + registerRect.w &&
									event2.button.y >= registerRect.y && event2.button.y <= registerRect.y + registerRect.h) {
									Mix_PlayChannel(-1, clickSound, 0);
									int check1 = checkUsername(username);
									int check2 = checkRepeatedUsername(username);
									int check3 = checkRepeatPassword(password, repeatPass);
									SDL_RenderCopy(renderer, trickTexture, NULL, &trick2Rect);
									SDL_RenderPresent(renderer);
									if (check1 == false) {
										char inform[100] = "Username is not valid!";
										x = 370;
										y = 510;
										getText(renderer, informSurface, informTexture, font_Kanit_M23, inform, x, y, red);
									}
									else
										if (check2 == 0) {
											char inform[100] = "Username has been existed!";
											x = 340;
											y = 510;
											getText(renderer, informSurface, informTexture, font_Kanit_M23, inform, x, y, red);
										}
										else if (strlen(password) == 0) {
											char inform[100] = "Password Mustn't Be Empty!";
											x = 340;
											y = 510;
											getText(renderer, informSurface, informTexture, font_Kanit_M23, inform, x, y, red);
										}
										else if (check3 == false) {
											char inform[100] = "Incorrect Repeat Password!";
											x = 340;
											y = 510;
											getText(renderer, informSurface, informTexture, font_Kanit_M23, inform, x, y, red);
										}
										else {
											writeIntoText(username, password);
											char inform[100] = "Successfully Register";
											x = 360;
											y = 510;
											getText(renderer, informSurface, informTexture, font_Kanit_M23, inform, x, y, red);
										}
								}
							}
							if (event2.type == SDL_MOUSEBUTTONDOWN)
								if (event2.button.button == SDL_BUTTON_LEFT)
									if (!(event2.button.x >= accessUser.x && event2.button.x <= accessUser.x + 345 &&
										event2.button.y >= accessUser.y && event2.button.y <= accessUser.y + 28)) {
										printf("OK\n");
										outUser = true;
										break;
									}
							if (event2.type == SDL_TEXTINPUT || event2.type == SDL_KEYDOWN) {
								if (event2.type == SDL_KEYDOWN && event2.key.keysym.sym == SDLK_KP_ENTER) {
									printf("OK\n");
									outUser = true;
									break;
								}
								if (event2.type == SDL_KEYDOWN && event2.key.keysym.sym == SDLK_BACKSPACE && strlen(username) > 0) {
									printf("You just press BackSpace\n");
									// press backspace
									lengthUser -= 1;
									username[lengthUser] = '\0';
									printf("%s\n", username);
									SDL_RenderCopy(renderer, barTexture, NULL, &accessUser);
									// render
									SDL_RenderPresent(renderer);
									// render username
									temp = TTF_RenderText_Solid(font_Kanit_L24, username, white); 
									userTexture = SDL_CreateTextureFromSurface(renderer, temp);
									SDL_QueryTexture(userTexture, NULL, NULL, &userRect.w, &userRect.h);
									SDL_RenderCopy(renderer, userTexture, NULL, &userRect);
									SDL_RenderPresent(renderer);
									// free 
									SDL_DestroyTexture(userTexture);
									userTexture = NULL;
									SDL_FreeSurface(temp);
									temp = NULL;
								}
								else {
									if (event2.type == SDL_TEXTINPUT && lengthUser < 20) {
										strcat_s(username, sizeof(username), event2.text.text);
										lengthUser+= strlen(event2.text.text);
										// render username
										temp = TTF_RenderText_Solid(font_Kanit_L24, username, white); // font
										userTexture = SDL_CreateTextureFromSurface(renderer, temp);
										SDL_QueryTexture(userTexture, NULL, NULL, &userRect.w, &userRect.h);
										SDL_RenderCopy(renderer, userTexture, NULL, &userRect);
										SDL_RenderPresent(renderer);
										// free
										SDL_DestroyTexture(userTexture);
										userTexture = NULL;
										SDL_FreeSurface(temp);
										temp = NULL;
									}
								}
							}
							// mouse motion
							if (event2.type == SDL_MOUSEMOTION) {
								if (event2.motion.x >= returnRect.x && event2.motion.x <= returnRect.x + returnRect.w &&
									event2.motion.y >= returnRect.y && event2.motion.y <= returnRect.y + returnRect.h) {
									SDL_RenderCopy(renderer, returnAquaTex, NULL, &returnRect);
									SDL_RenderPresent(renderer);
								}
								else {
									SDL_RenderCopy(renderer, returnTexture, NULL, &returnRect);
									SDL_RenderPresent(renderer);
								}
								if (event2.motion.x >= registerRect.x && event2.motion.x <= registerRect.x + registerRect.w &&
									event2.motion.y >= registerRect.y && event2.motion.y <= registerRect.y + registerRect.h) {
									SDL_RenderCopy(renderer, registerRedTex, NULL, &registerRect);
									SDL_RenderPresent(renderer);
								}
								else {
									SDL_RenderCopy(renderer, registerTexture, NULL, &registerRect);
									SDL_RenderPresent(renderer);
								}
							}
						}
					}
				}
				// access Password
				if (event.button.x >= accessPass.x && event.button.x <= accessPass.x + 345 &&
					event.button.y >= accessPass.y && event.button.y <= accessPass.y + 28) {
					SDL_RenderCopy(renderer, delete3Texture, NULL, &delete3Rect);
					SDL_RenderCopy(renderer, delete5Texture, NULL, &delete5Rect);
					SDL_RenderCopy(renderer, arrowTexture, NULL, &arrowRect2);
					SDL_RenderCopy(renderer, trickTexture, NULL, &trick2Rect);
					SDL_RenderPresent(renderer);
					bool outPass = false;
					SDL_Event event3;
					while (!outPass) {
						while (SDL_PollEvent(&event3)) {
							if (event3.type == SDL_QUIT) {
								outPass = true;
								quit = 1;
							}
							if (event3.type == SDL_MOUSEBUTTONDOWN) {
								if (event3.button.x >= returnRect.x && event3.button.x <= returnRect.x + returnRect.w &&
									event3.button.y >= returnRect.y && event3.button.y <= returnRect.y + returnRect.h) {
									Mix_PlayChannel(-1, clickSound, 0);
									SDL_StopTextInput();
									SDL_DestroyTexture(imageTexture);
									imageTexture = NULL;
									SDL_DestroyTexture(trickTexture);
									trickTexture = NULL;
									SDL_DestroyTexture(textTexture);
									textTexture = NULL;
									SDL_DestroyTexture(returnTexture);
									returnTexture = NULL;
									SDL_DestroyTexture(returnAquaTex);
									returnAquaTex = NULL;
									SDL_DestroyTexture(registerTexture);
									registerTexture = NULL;
									SDL_DestroyTexture(registerRedTex);
									registerRedTex = NULL;
									SDL_DestroyTexture(barTexture);
									barTexture = NULL;
									SDL_DestroyTexture(userTexture);
									userTexture = NULL;
									SDL_DestroyTexture(passTexture);
									passTexture = NULL;
									SDL_DestroyTexture(repeatTexture);
									repeatTexture = NULL;
									SDL_DestroyTexture(informTexture);
									informTexture = NULL;
									SDL_DestroyTexture(arrowTexture);
									arrowTexture = NULL;
									SDL_DestroyTexture(delete3Texture);
									delete3Texture = NULL;
									SDL_DestroyTexture(delete4Texture);
									delete4Texture = NULL;
									SDL_DestroyTexture(delete5Texture);
									delete5Texture = NULL;
									SDL_DestroyRenderer(renderer);
									renderer = NULL;
									SDL_DestroyWindow(window);
									window = NULL;
									loginDisplay();
									return;
								}
								if (event3.button.x >= registerRect.x && event3.button.x <= registerRect.x + registerRect.w &&
									event3.button.y >= registerRect.y && event3.button.y <= registerRect.y + registerRect.h) {
									Mix_PlayChannel(-1, clickSound, 0);
									int check1 = checkUsername(username);
									int check2 = checkRepeatedUsername(username);
									int check3 = checkRepeatPassword(password, repeatPass);
									SDL_RenderCopy(renderer, trickTexture, NULL, &trick2Rect);
									SDL_RenderPresent(renderer);
									if (check1 == false) {
										char inform[100] = "Username is not valid!";
										x = 370;
										y = 510;
										getText(renderer, informSurface, informTexture, font_Kanit_M23, inform, x, y, red);
									}
									else
										if (check2 == 0) {
											char inform[100] = "Username has been existed!";
											x = 340;
											y = 510;
											getText(renderer, informSurface, informTexture, font_Kanit_M23, inform, x, y, red);
										}
										else if (strlen(password) == 0) {
											char inform[100] = "Password Mustn't Be Empty!";
											x = 340;
											y = 510;
											getText(renderer, informSurface, informTexture, font_Kanit_M23, inform, x, y, red);
										}
										else if (check3 == false) {
											char inform[100] = "Incorrect Repeat Password!";
											x = 340;
											y = 510;
											getText(renderer, informSurface, informTexture, font_Kanit_M23, inform, x, y, red);
										}
										else {
											writeIntoText(username, password);
											char inform[100] = "Successfully Register";
											x = 360;
											y = 510;
											getText(renderer, informSurface, informTexture, font_Kanit_M23, inform, x, y, red);
										}
								}
							}
							//
							if (event3.type == SDL_MOUSEBUTTONDOWN)
								if (event3.button.button == SDL_BUTTON_LEFT)
									if (!(event3.button.x >= accessPass.x && event3.button.x <= accessPass.x + 345 &&
										event3.button.y >= accessPass.y && event3.button.y <= accessPass.y + 28)) {
										printf("OK\n");
										outPass = true;
										break;
									}
							if (event3.type == SDL_TEXTINPUT || event3.type == SDL_KEYDOWN) {
								if (event3.type == SDL_KEYDOWN && event3.key.keysym.sym == SDLK_KP_ENTER) {
									printf("OK\n");
									outPass = true;
									break;
								}
								if (event3.type == SDL_KEYDOWN && event3.key.keysym.sym == SDLK_BACKSPACE && strlen(password) > 0) {
									printf("You just press BackSpace\n");
									// press backspace
									lengthPass -= 1;
									password[lengthPass] = '\0';
									printf("%s\n", password);							
									SDL_RenderCopy(renderer, barTexture, NULL, &accessPass);
									// render password
									temp2 = TTF_RenderText_Solid(font_Kanit_L24, password, white);
									passTexture = SDL_CreateTextureFromSurface(renderer, temp2);
									SDL_QueryTexture(passTexture, NULL, NULL, &passRect.w, &passRect.h);
									SDL_RenderCopy(renderer, passTexture, NULL, &passRect);
									SDL_RenderPresent(renderer);
									//free
									SDL_DestroyTexture(passTexture);
									passTexture = NULL;
									SDL_FreeSurface(temp2);
									temp2 = NULL;
								}
								else {
									if (event3.type == SDL_TEXTINPUT && lengthPass < 20) {
										strcat_s(password, sizeof(password), event3.text.text);
										lengthPass += strlen(event3.text.text);
										// render password
										temp2 = TTF_RenderText_Solid(font_Kanit_L24, password, white);
										passTexture = SDL_CreateTextureFromSurface(renderer, temp2);
										SDL_QueryTexture(passTexture, NULL, NULL, &passRect.w, &passRect.h);
										SDL_RenderCopy(renderer, passTexture, NULL, &passRect);
										SDL_RenderPresent(renderer);
										//free
										SDL_DestroyTexture(passTexture);
										passTexture = NULL;
										SDL_FreeSurface(temp2);
										temp2 = NULL;
									}
								}
							}
							//
							if (event3.type == SDL_MOUSEMOTION) {
								if (event3.motion.x >= returnRect.x && event3.motion.x <= returnRect.x + returnRect.w &&
									event3.motion.y >= returnRect.y && event3.motion.y <= returnRect.y + returnRect.h) {
									SDL_RenderCopy(renderer, returnAquaTex, NULL, &returnRect);
									SDL_RenderPresent(renderer);
								}
								else {
									SDL_RenderCopy(renderer, returnTexture, NULL, &returnRect);
									SDL_RenderPresent(renderer);
								}
								if (event3.motion.x >= registerRect.x && event3.motion.x <= registerRect.x + registerRect.w &&
									event3.motion.y >= registerRect.y && event3.motion.y <= registerRect.y + registerRect.h) {
									SDL_RenderCopy(renderer, registerRedTex, NULL, &registerRect);
									SDL_RenderPresent(renderer);
								}
								else {
									SDL_RenderCopy(renderer, registerTexture, NULL, &registerRect);
									SDL_RenderPresent(renderer);
								}
							}
						}
					}
				}
				// access Repeat
				if (event.button.x >= accessRepeat.x && event.button.x <= accessRepeat.x + 345 &&
					event.button.y >= accessRepeat.y && event.button.y <= accessRepeat.y + 28) {
					SDL_RenderCopy(renderer, delete3Texture, NULL, &delete3Rect);
					SDL_RenderCopy(renderer, delete4Texture, NULL, &delete4Rect);
					SDL_RenderCopy(renderer, arrowTexture, NULL, &arrowRect3);
					SDL_RenderCopy(renderer, trickTexture, NULL, &trick2Rect);
					SDL_RenderPresent(renderer);
					bool outRepeat = false;
					SDL_Event event4;
					while (!outRepeat) {
						while (SDL_PollEvent(&event4)) {
							if (event4.type == SDL_QUIT) {
								outRepeat = true;
								quit = 1;
							}
							if (event4.type == SDL_MOUSEBUTTONDOWN) {
								if (event4.button.x >= returnRect.x && event4.button.x <= returnRect.x + returnRect.w &&
									event4.button.y >= returnRect.y && event4.button.y <= returnRect.y + returnRect.h) {
									Mix_PlayChannel(-1, clickSound, 0);
									SDL_StopTextInput();
									SDL_DestroyTexture(imageTexture);
									imageTexture = NULL;
									SDL_DestroyTexture(trickTexture);
									trickTexture = NULL;
									SDL_DestroyTexture(textTexture);
									textTexture = NULL;
									SDL_DestroyTexture(returnTexture);
									returnTexture = NULL;
									SDL_DestroyTexture(returnAquaTex);
									returnAquaTex = NULL;
									SDL_DestroyTexture(registerTexture);
									registerTexture = NULL;
									SDL_DestroyTexture(registerRedTex);
									registerRedTex = NULL;
									SDL_DestroyTexture(barTexture);
									barTexture = NULL;
									SDL_DestroyTexture(userTexture);
									userTexture = NULL;
									SDL_DestroyTexture(passTexture);
									passTexture = NULL;
									SDL_DestroyTexture(repeatTexture);
									repeatTexture = NULL;
									SDL_DestroyTexture(informTexture);
									informTexture = NULL;
									SDL_DestroyTexture(arrowTexture);
									arrowTexture = NULL;
									SDL_DestroyTexture(delete3Texture);
									delete3Texture = NULL;
									SDL_DestroyTexture(delete4Texture);
									delete4Texture = NULL;
									SDL_DestroyTexture(delete5Texture);
									delete5Texture = NULL;
									SDL_DestroyRenderer(renderer);
									renderer = NULL;
									SDL_DestroyWindow(window);
									window = NULL;
									loginDisplay();
									return;
								}
								if (event4.button.x >= registerRect.x && event4.button.x <= registerRect.x + registerRect.w &&
									event4.button.y >= registerRect.y && event4.button.y <= registerRect.y + registerRect.h) {
									Mix_PlayChannel(-1, clickSound, 0);
									int check1 = checkUsername(username);
									int check2 = checkRepeatedUsername(username);
									int check3 = checkRepeatPassword(password, repeatPass);
									SDL_RenderCopy(renderer, trickTexture, NULL, &trick2Rect);
									SDL_RenderPresent(renderer);
									if (check1 == false) {
										char inform[100] = "Username is not valid!";
										x = 370;
										y = 510;
										getText(renderer, informSurface, informTexture, font_Kanit_M23, inform, x, y, red);
									}
									else
										if (check2 == 0) {
											char inform[100] = "Username has been existed!";
											x = 340;
											y = 510;
											getText(renderer, informSurface, informTexture, font_Kanit_M23, inform, x, y, red);
										}
										else if (strlen(password) == 0) {
											char inform[100] = "Password Mustn't Be Empty!";
											x = 340;
											y = 510;
											getText(renderer, informSurface, informTexture, font_Kanit_M23, inform, x, y, red);
										}
										else if (check3 == false) {
											char inform[100] = "Incorrect Repeat Password!";
											x = 340;
											y = 510;
											getText(renderer, informSurface, informTexture, font_Kanit_M23, inform, x, y, red);
										}
										else {
											writeIntoText(username, password);
											char inform[100] = "Successfully Register";
											x = 360;
											y = 510;
											getText(renderer, informSurface, informTexture, font_Kanit_M23, inform, x, y, red);
										}
								}
							}
							if (event4.type == SDL_MOUSEBUTTONDOWN)
								if (event4.button.button == SDL_BUTTON_LEFT)
									if (!(event4.button.x >= accessRepeat.x && event4.button.x <= accessRepeat.x + 345 &&
										event4.button.y >= accessRepeat.y && event4.button.y <= accessRepeat.y + 28)) {
										printf("OK\n");
										outRepeat = true;
										break;
									}
							if (event4.type == SDL_TEXTINPUT || event4.type == SDL_KEYDOWN) {
								if (event4.type == SDL_KEYDOWN && event4.key.keysym.sym == SDLK_KP_ENTER) {
									printf("OK\n");
									outRepeat = true;
									break;
								}
								if (event4.type == SDL_KEYDOWN && event4.key.keysym.sym == SDLK_BACKSPACE && strlen(repeatPass) > 0) {
									printf("You just press BackSpace\n");
									// press backspace
									lengthRepeat -= 1;
									repeatPass[lengthRepeat] = '\0';
									printf("%s\n", repeatPass);
									SDL_RenderCopy(renderer, barTexture, NULL, &accessRepeat);
									// render repeat pass
									temp3 = TTF_RenderText_Solid(font_Kanit_L24, repeatPass, white);
									repeatTexture = SDL_CreateTextureFromSurface(renderer, temp3);
									SDL_QueryTexture(repeatTexture, NULL, NULL, &repeatRect.w, &repeatRect.h);
									SDL_RenderCopy(renderer, repeatTexture, NULL, &repeatRect);
									SDL_RenderPresent(renderer);
									//free
									SDL_DestroyTexture(repeatTexture);
									repeatTexture = NULL;
									SDL_FreeSurface(temp3);
									temp3 = NULL;
								}
								else {
									if (event4.type == SDL_TEXTINPUT && lengthRepeat < 20) {
										strcat_s(repeatPass, sizeof(repeatPass), event4.text.text);
										lengthRepeat += strlen(event4.text.text);
										// render repeat pass
										temp3 = TTF_RenderText_Solid(font_Kanit_L24, repeatPass, (SDL_Color) { 255, 255, 255, 255 });
										repeatTexture = SDL_CreateTextureFromSurface(renderer, temp3);
										SDL_QueryTexture(repeatTexture, NULL, NULL, &repeatRect.w, &repeatRect.h);
										SDL_RenderCopy(renderer, repeatTexture, NULL, &repeatRect);
										SDL_RenderPresent(renderer);
										//free
										SDL_DestroyTexture(repeatTexture);
										repeatTexture = NULL;
										SDL_FreeSurface(temp3);
										temp3 = NULL;
									}
								}
							}
							if (event4.type == SDL_MOUSEMOTION) {
								if (event4.motion.x >= returnRect.x && event4.motion.x <= returnRect.x + returnRect.w &&
									event4.motion.y >= returnRect.y && event4.motion.y <= returnRect.y + returnRect.h) {
									SDL_RenderCopy(renderer, returnAquaTex, NULL, &returnRect);
									SDL_RenderPresent(renderer);
								}
								else {
									SDL_RenderCopy(renderer, returnTexture, NULL, &returnRect);
									SDL_RenderPresent(renderer);
								}
								if (event4.motion.x >= registerRect.x && event4.motion.x <= registerRect.x + registerRect.w &&
									event4.motion.y >= registerRect.y && event4.motion.y <= registerRect.y + registerRect.h) {
									SDL_RenderCopy(renderer, registerRedTex, NULL, &registerRect);
									SDL_RenderPresent(renderer);
								}
								else {
									SDL_RenderCopy(renderer, registerTexture, NULL, &registerRect);
									SDL_RenderPresent(renderer);
								}
							}
						}
					}
				}
				// click return 
				if (event.button.x >= returnRect.x && event.button.x <= returnRect.x + returnRect.w &&
					event.button.y >= returnRect.y && event.button.y <= returnRect.y + returnRect.h) {
					Mix_PlayChannel(-1, clickSound, 0);
					//free texture 
					SDL_StopTextInput();
					SDL_DestroyTexture(imageTexture);
					imageTexture = NULL;
					SDL_DestroyTexture(trickTexture);
					trickTexture = NULL;
					SDL_DestroyTexture(textTexture);
					textTexture = NULL;
					SDL_DestroyTexture(returnTexture);
					returnTexture = NULL;
					SDL_DestroyTexture(returnAquaTex);
					returnAquaTex = NULL;
					SDL_DestroyTexture(registerTexture);
					registerTexture = NULL;
					SDL_DestroyTexture(registerRedTex);
					registerRedTex = NULL;
					SDL_DestroyTexture(barTexture);
					barTexture = NULL;
					SDL_DestroyTexture(userTexture);
					userTexture = NULL;
					SDL_DestroyTexture(passTexture);
					passTexture = NULL;
					SDL_DestroyTexture(repeatTexture);
					repeatTexture = NULL;
					SDL_DestroyTexture(informTexture);
					informTexture = NULL;
					SDL_DestroyTexture(arrowTexture);
					arrowTexture = NULL;
					SDL_DestroyTexture(delete3Texture);
					delete3Texture = NULL;
					SDL_DestroyTexture(delete4Texture);
					delete4Texture = NULL;
					SDL_DestroyTexture(delete5Texture);
					delete5Texture = NULL;
					SDL_DestroyRenderer(renderer);
					renderer = NULL;
					SDL_DestroyWindow(window);
					window = NULL;
					loginDisplay();
					return;
				}
				// click register -> write into txt
				if (event.button.x >= registerRect.x && event.button.x <= registerRect.x + registerRect.w &&
					event.button.y >= registerRect.y && event.button.y <= registerRect.y + registerRect.h) {
					Mix_PlayChannel(-1, clickSound, 0);
					int check1 = checkUsername(username);
					int check2 = checkRepeatedUsername(username);
					int check3 = checkRepeatPassword(password, repeatPass);
					SDL_RenderCopy(renderer, trickTexture, NULL, &trick2Rect);
					SDL_RenderPresent(renderer);
					if (check1 == false) {
						char inform[100] = "Username is not valid!";
						x = 370; 
						y = 510;
						getText(renderer, informSurface, informTexture, font_Kanit_M23, inform, x, y, red);
					}
					else 
						if (check2 == 0) {
							char inform[100] = "Username has been existed!";
							x = 340;
							y = 510;
							getText(renderer, informSurface, informTexture, font_Kanit_M23, inform, x, y, red);
						}
						else if (strlen(password) == 0) {
							char inform[100] = "Password Mustn't Be Empty!";
							x = 340;
							y = 510;
							getText(renderer, informSurface, informTexture, font_Kanit_M23, inform, x, y, red);
						}
						else if (check3 == false) {
								char inform[100] = "Incorrect Repeat Password!";
								x = 340;
								y = 510;
								getText(renderer, informSurface, informTexture, font_Kanit_M23, inform, x, y, red);
						}
						else {
								writeIntoText(username, password);
								char inform[100] = "Successfully Register";
								x = 360;
								y = 510;
								getText(renderer, informSurface, informTexture, font_Kanit_M23, inform, x, y, red);
						}
				}

			} else if (event.type == SDL_MOUSEMOTION){
				if (event.motion.x >= returnRect.x && event.motion.x <= returnRect.x + returnRect.w &&
					event.motion.y >= returnRect.y && event.motion.y <= returnRect.y + returnRect.h) {
					SDL_RenderCopy(renderer, returnAquaTex, NULL, &returnRect);
					SDL_RenderPresent(renderer);
				}
				else {
					SDL_RenderCopy(renderer, returnTexture, NULL, &returnRect);
					SDL_RenderPresent(renderer);
				}
				if (event.motion.x >= registerRect.x && event.motion.x <= registerRect.x + registerRect.w &&
					event.motion.y >= registerRect.y && event.motion.y <= registerRect.y + registerRect.h) {
					SDL_RenderCopy(renderer, registerRedTex, NULL, &registerRect);
					SDL_RenderPresent(renderer);
				}
				else {
					SDL_RenderCopy(renderer, registerTexture, NULL, &registerRect);
					SDL_RenderPresent(renderer);
				}
			}
			else if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					//free texture 
					SDL_StopTextInput();
					SDL_DestroyTexture(imageTexture);
					imageTexture = NULL;
					SDL_DestroyTexture(trickTexture);
					trickTexture = NULL;
					SDL_DestroyTexture(textTexture);
					textTexture = NULL;
					SDL_DestroyTexture(returnTexture);
					returnTexture = NULL;
					SDL_DestroyTexture(returnAquaTex);
					returnAquaTex = NULL;
					SDL_DestroyTexture(registerTexture);
					registerTexture = NULL;
					SDL_DestroyTexture(registerRedTex);
					registerRedTex = NULL;
					SDL_DestroyTexture(barTexture);
					barTexture = NULL;
					SDL_DestroyTexture(userTexture);
					userTexture = NULL;
					SDL_DestroyTexture(passTexture);
					passTexture = NULL;
					SDL_DestroyTexture(repeatTexture);
					repeatTexture = NULL;
					SDL_DestroyTexture(informTexture);
					informTexture = NULL;
					SDL_DestroyTexture(arrowTexture);
					arrowTexture = NULL;
					SDL_DestroyTexture(delete3Texture);
					delete3Texture = NULL;
					SDL_DestroyTexture(delete4Texture);
					delete4Texture = NULL;
					SDL_DestroyTexture(delete5Texture);
					delete5Texture = NULL;
					SDL_DestroyRenderer(renderer);
					renderer = NULL;
					SDL_DestroyWindow(window);
					window = NULL;
					loginDisplay();
					return;
				}
			}
		}
	}

	SDL_StopTextInput();
	SDL_DestroyTexture(imageTexture);
	imageTexture = NULL;
	SDL_DestroyTexture(trickTexture);
	trickTexture = NULL;
	SDL_DestroyTexture(textTexture);
	textTexture = NULL;
	SDL_DestroyTexture(returnTexture);
	returnTexture = NULL;
	SDL_DestroyTexture(returnAquaTex);
	returnAquaTex = NULL;
	SDL_DestroyTexture(registerTexture);
	registerTexture = NULL;
	SDL_DestroyTexture(registerRedTex);
	registerRedTex = NULL;
	SDL_DestroyTexture(barTexture);
	barTexture = NULL;
	SDL_DestroyTexture(userTexture);
	userTexture = NULL;
	SDL_DestroyTexture(passTexture);
	passTexture = NULL;
	SDL_DestroyTexture(repeatTexture);
	repeatTexture = NULL;
	SDL_DestroyTexture(informTexture);
	informTexture = NULL;
	SDL_DestroyTexture(arrowTexture);
	arrowTexture = NULL;
	SDL_DestroyTexture(delete3Texture);
	delete3Texture = NULL;
	SDL_DestroyTexture(delete4Texture);
	delete4Texture = NULL;
	SDL_DestroyTexture(delete5Texture);
	delete5Texture = NULL;
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
	TTF_Quit();
	SDL_Quit();
	return;
}