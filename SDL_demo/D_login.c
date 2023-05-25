#include "SDLlib.h"

void loginDisplay() {

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Surface* imageSurface = NULL;
    SDL_Texture* imageTexture = NULL;  
    SDL_Surface* textSurface = NULL, * textSurface2 = NULL, * temp = NULL, * temp2 = NULL;  
    SDL_Texture* textTexture = NULL, * textTexture2 = NULL, * userTexture = NULL, * passTexture = NULL;  
    SDL_Surface* trickSurface = NULL;  
    SDL_Texture* trickTexture = NULL; 
    SDL_Surface* optionSurface[2] = {NULL};
    SDL_Texture* optionTexture[2] = {NULL};
    SDL_Surface* logAquaSur = NULL, *regisRedSur = NULL; 
    SDL_Texture* logAquaTex = NULL, *regisRedTex = NULL;  
    SDL_Surface* arrowSurface = NULL;
    SDL_Texture* arrowTexture = NULL; 
    SDL_Surface* deleteSurface[2] = { NULL };
    SDL_Texture* deleteTexture[2] = { NULL };
    SDL_Surface* informSurface1 = NULL, * informSurface2 = NULL;  
    SDL_Texture* informTexture1 = NULL, * informTexture2 = NULL;
    // rect
    SDL_Rect textRect1;
    SDL_Rect textRect2;
    SDL_Rect loginRect, registerRect;
    SDL_Rect accessLogin = { 309 , 273 , 345 , 28 };   /// note
    SDL_Rect accessPass = { 309 , 348 , 345 , 28 };  /// note
    SDL_Rect deleteRect[2];
    deleteRect[0].x = 670;
    deleteRect[0].y = 275;
    deleteRect[0].w = 48;
    deleteRect[0].h = 25;

    deleteRect[1].x = 670;
    deleteRect[1].y = 350;
    deleteRect[1].w = 42;
    deleteRect[1].h = 25;

    SDL_Rect arrowRect;
    arrowRect.x = 670;
    arrowRect.y = 275;
    arrowRect.w = 25;
    arrowRect.h = 25;

    SDL_Rect arrowRect2;
    arrowRect2.x = 670;
    arrowRect2.y = 350;
    arrowRect2.w = 25;
    arrowRect2.h = 25;

    SDL_Rect trickRect;
    trickRect.x = 262;
    trickRect.y = 388;
    trickRect.w = 442;
    trickRect.h = 51;

    SDL_Rect informRect;
    informRect.x = 350;
    informRect.y = 390;

    SDL_Rect informRect2;
    informRect2.x = 378;
    informRect2.y = 390;

    SDL_Surface* bar = NULL;
    SDL_Texture* barTexture = NULL;

    SDL_Rect userRect; 
    userRect.x = 313;
    userRect.y = 268;

    SDL_Rect passRect;
    passRect.x = 313;
    passRect.y = 343;

    // other
    char* options[2] = { "Login" , "Register" };
    char password[25] = { 0 };
    char username[21] = { 0 };
    int textLength = 0;
    int passLength = 0;
    int x = 0, y = 0;

    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    window = SDL_CreateWindow("Login Display", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 960, 668, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    // load sound
    Mix_Music* clickSound = Mix_LoadWAV("Sound/SoundEffects/click.wav");
    // load background
    SDL_Rect imageRect;
    imageSurface = SDL_LoadBMP("LoginImage/LoginBG.bmp");
    imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_RenderCopy(renderer, imageTexture, NULL, NULL);
    // fix back ground
    trickSurface = SDL_LoadBMP("LoginImage/trick.bmp");
    trickTexture = SDL_CreateTextureFromSurface(renderer, trickSurface);
    SDL_RenderCopy(renderer, trickTexture, NULL, &trickRect);
    //fix back arrow
    deleteSurface[0] = SDL_LoadBMP("LoginImage/delete2.bmp");
    deleteSurface[1] = SDL_LoadBMP("LoginImage/delete1.bmp");
    for (int i = 0; i < 2; i++) {
        deleteTexture[i] = SDL_CreateTextureFromSurface(renderer, deleteSurface[i]);
        SDL_RenderCopy(renderer, deleteTexture[i], NULL, &deleteRect[i]);
    }
    // load text
    textSurface = NULL;
    textTexture = NULL;
    char textUsername [20] = "Username";
    x = 305;
    y = 238;
    getText(renderer, textSurface, textTexture, font_Kanit_MI24, textUsername , 305 , 238 , black);
    char  textPassword[20] = "Password";
    x = 305;
    y = 313;
    getText(renderer, textSurface, textTexture, font_Kanit_MI24, textPassword, x, y, black);
    // load option : login , register
    for (int i = 0; i < 2; i++) {
        optionSurface[i] = TTF_RenderText_Solid(font_Kanit_L24, options[i], black);
        optionTexture[i] = SDL_CreateTextureFromSurface(renderer, optionSurface[i]);
    }
    SDL_QueryTexture(optionTexture[0], NULL, NULL, &loginRect.w, &loginRect.h);
    loginRect.x = 362;
    loginRect.y = 439;
    SDL_RenderCopy(renderer, optionTexture[0], NULL, &loginRect);

    SDL_QueryTexture(optionTexture[1], NULL, NULL, &registerRect.w, &registerRect.h);
    registerRect.x = 523;
    registerRect.y = 439;
    SDL_RenderCopy(renderer, optionTexture[1], NULL, &registerRect);
    // color login register
    logAquaSur = TTF_RenderText_Solid(font_Kanit_L24, options[0], aqua);
    logAquaTex = SDL_CreateTextureFromSurface(renderer, logAquaSur);

    regisRedSur = TTF_RenderText_Solid(font_Kanit_L24, options[1], red);
    regisRedTex = SDL_CreateTextureFromSurface(renderer, regisRedSur);
    // load arrow
    arrowSurface = SDL_LoadBMP("LoginImage/arrow.bmp");
    arrowTexture = SDL_CreateTextureFromSurface(renderer, arrowSurface);
    // render
    SDL_RenderPresent(renderer);
    // load inform 
    informSurface1 = TTF_RenderText_Solid(font_Kanit_MI24, "Username does not exist!", red);
    informTexture1 = SDL_CreateTextureFromSurface(renderer, informSurface1);
    SDL_QueryTexture(informTexture1, NULL, NULL, &informRect.w, &informRect.h);
    informSurface2 = TTF_RenderText_Solid(font_Kanit_MI24, "Incorrect Password!", red);
    informTexture2 = SDL_CreateTextureFromSurface(renderer, informSurface2);
    SDL_QueryTexture(informTexture2, NULL, NULL, &informRect2.w, &informRect2.h);
    // load delete bar
    bar = SDL_LoadBMP("LoginImage/bar.bmp");
    barTexture = SDL_CreateTextureFromSurface(renderer, bar);
    // free surface
    SDL_FreeSurface(imageSurface);
    imageSurface = NULL;
    SDL_FreeSurface(textSurface);
    textSurface = NULL;
    SDL_FreeSurface(textSurface2);
    textSurface2 = NULL;
    SDL_FreeSurface(trickSurface);
    trickSurface = NULL;
    SDL_FreeSurface(logAquaSur);
    logAquaSur = NULL;
    SDL_FreeSurface(arrowSurface);
    arrowSurface = NULL;
    SDL_FreeSurface(informSurface1);
    informSurface1 = NULL;
    SDL_FreeSurface(informSurface2);
    informSurface2 = NULL;
    for (int i = 0; i < 2; i++) {
        SDL_FreeSurface(optionSurface[i]);
        optionSurface[i] = NULL;
        SDL_FreeSurface(deleteSurface[i]);
        deleteSurface[i] = NULL;
    }

    SDL_Event event;
    int done = 0;
    SDL_StartTextInput();
    
    while (!done) {
        while (SDL_PollEvent(&event)) {
            
            if (event.type == SDL_QUIT) {
                SDL_DestroyTexture(imageTexture);
                imageTexture = NULL;
                SDL_DestroyTexture(textTexture);
                textTexture = NULL;
                SDL_DestroyTexture(textTexture2);
                textTexture2 = NULL;
                SDL_DestroyTexture(trickTexture);
                trickTexture = NULL;
                SDL_DestroyTexture(logAquaTex);
                logAquaTex = NULL;
                SDL_DestroyTexture(regisRedTex);
                regisRedTex = NULL;
                SDL_DestroyTexture(informTexture1);
                informTexture1 = NULL;
                SDL_DestroyTexture(informTexture2);
                informTexture2 = NULL;
                SDL_FreeSurface(temp);
                temp = NULL;
                SDL_FreeSurface(temp2);
                temp2 = NULL;
                SDL_DestroyTexture(userTexture);
                userTexture = NULL;
                SDL_DestroyTexture(passTexture);
                passTexture = NULL;
                for (int i = 0; i < 2; i++) {
                    SDL_DestroyTexture(optionTexture[i]);
                    optionTexture[i] = NULL;
                    SDL_DestroyTexture(deleteTexture[i]);
                    deleteTexture[i] = NULL;
                }
                done = 1;
            }
            else
                if (event.type == SDL_MOUSEBUTTONDOWN) {
                    if (event.button.x >= accessLogin.x && event.button.x <= accessLogin.x + 345 &&
                        event.button.y >= accessLogin.y && event.button.y <= accessLogin.y + 28) {
                        // delete arrow pass
                        SDL_RenderCopy(renderer, deleteTexture[1], NULL, &deleteRect[1]);
                        // appear arrow login 
                        SDL_RenderCopy(renderer, arrowTexture, NULL, &arrowRect);
                        // delete inform
                        SDL_RenderCopy(renderer, trickTexture, NULL, &trickRect);
                        SDL_RenderPresent(renderer);

                        bool outLogin = false;
                        SDL_Event event2;
                        while (!outLogin) {
                            while (SDL_PollEvent(&event2)) {
                               if (event2.type == SDL_QUIT) { outLogin = 1; done = 1; }
                               //
                               if (event2.type == SDL_MOUSEBUTTONDOWN) {
                                   // press register button
                                   if (event2.button.x >= registerRect.x && event2.button.x <= registerRect.x + registerRect.w &&
                                       event2.button.y >= registerRect.y && event2.button.y <= registerRect.y + registerRect.h) {
                                       Mix_PlayChannel(-1, clickSound, 0);
                                       //   free textture
                                       SDL_DestroyTexture(imageTexture);
                                       imageTexture = NULL;
                                       SDL_DestroyTexture(textTexture);
                                       textTexture = NULL;
                                       SDL_DestroyTexture(textTexture2);
                                       textTexture2 = NULL;
                                       SDL_DestroyTexture(trickTexture);
                                       trickTexture = NULL;
                                       SDL_DestroyTexture(logAquaTex);
                                       logAquaTex = NULL;
                                       SDL_DestroyTexture(regisRedTex);
                                       regisRedTex = NULL;
                                       SDL_DestroyTexture(informTexture1);
                                       informTexture1 = NULL;
                                       SDL_DestroyTexture(informTexture2);
                                       informTexture2 = NULL;
                                       SDL_FreeSurface(temp);
                                       temp = NULL;
                                       SDL_FreeSurface(temp2);
                                       temp2 = NULL;
                                       SDL_DestroyTexture(userTexture);
                                       userTexture = NULL;
                                       SDL_DestroyTexture(passTexture);
                                       passTexture = NULL;
                                       for (int i = 0; i < 2; i++) {
                                           SDL_DestroyTexture(optionTexture[i]);
                                           optionTexture[i] = NULL;
                                           SDL_DestroyTexture(deleteTexture[i]);
                                           deleteTexture[i] = NULL;
                                       }
                                       SDL_DestroyRenderer(renderer);
                                       SDL_DestroyWindow(window);
                                       registerDisplay();
                                       return;
                                   }
                                   // press login button
                                   if (event2.button.x >= loginRect.x && event2.button.x <= loginRect.x + loginRect.w &&
                                       event2.button.y >= loginRect.y && event2.button.y <= loginRect.y + loginRect.h) {
                                       Mix_PlayChannel(-1, clickSound, 0);
                                       // check username
                                       int check = checkRepeatedUsername(username);
                                       printf("%d\n", check);
                                       if (check == 1) {
                                           printf("Wrong Username!\n");
                                           SDL_RenderCopy(renderer, informTexture1, NULL, &informRect);
                                           SDL_RenderPresent(renderer);
                                       }
                                       else if (check == 0) {
                                           int check2 = checkPassword(username, password);
                                           printf("%d\n", check2);
                                           if (check2 == 1) {
                                               printf("Wrong Pass!\n");
                                               SDL_RenderCopy(renderer, informTexture2, NULL, &informRect2);
                                               SDL_RenderPresent(renderer);
                                           }
                                           else
                                               if (check2 == 0) {
                                                   SDL_DestroyWindow(window);
                                                   accountDisplay();
                                               }
                                       }
                                   }
                               }
                               //
                               if (event2.type == SDL_MOUSEBUTTONDOWN)
                                   if (event2.button.button == SDL_BUTTON_LEFT)
                                       if (!(event2.button.x >= accessLogin.x && event2.button.x <= accessLogin.x + 345 &&
                                           event2.button.y >= accessLogin.y && event2.button.y <= accessLogin.y + 28)) {
                                            //printf("OK\n");
                                            outLogin = true;
                                            break;
                                       }
                                //
                                userTexture = NULL;
                                if (event2.type == SDL_TEXTINPUT || event2.type == SDL_KEYDOWN) {

                                    if (event2.type == SDL_KEYDOWN && event2.key.keysym.sym == SDLK_KP_ENTER) {
                                        printf("OK\n");
                                        outLogin = true;
                                        break;
                                    }
                                    if (event2.type == SDL_KEYDOWN && event2.key.keysym.sym == SDLK_BACKSPACE && strlen(username) > 0) {
                                        printf("You just press BackSpace\n");
                                        textLength -= 1;
                                        username[textLength] = '\0';
                                        printf("%s\n", username);
                                        SDL_RenderCopy(renderer, barTexture, NULL, &accessLogin);
                                        SDL_RenderPresent(renderer);
                                        if (userTexture) {
                                            SDL_DestroyTexture(userTexture);
                                        }
                                        temp = TTF_RenderText_Solid(font_Kanit_L24, username, (SDL_Color) { 255, 255, 255, 255 });
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
                                        if (event2.type == SDL_TEXTINPUT && textLength < 20) {
                                            strcat_s(username, sizeof(username), event2.text.text);
                                            textLength += strlen(event2.text.text);
                                            if (userTexture) {
                                                SDL_DestroyTexture(userTexture);
                                            }
                                            temp = TTF_RenderText_Solid(font_Kanit_L24, username, (SDL_Color) { 255, 255, 255, 255 });
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
                                //
                                if (event2.type == SDL_MOUSEMOTION) {
                                    //login
                                    if (event2.motion.x >= loginRect.x && event2.motion.x <= loginRect.x + loginRect.w &&
                                        event2.motion.y >= loginRect.y && event2.motion.y <= loginRect.y + loginRect.h) {
                                        SDL_RenderCopy(renderer, logAquaTex, NULL, &loginRect);
                                        SDL_RenderPresent(renderer);
                                    }
                                    else {
                                        SDL_RenderCopy(renderer, optionTexture[0], NULL, &loginRect);
                                        SDL_RenderPresent(renderer);
                                    }
                                    // register
                                    if (event2.motion.x >= registerRect.x && event2.motion.x <= registerRect.x + registerRect.w &&
                                        event2.motion.y >= registerRect.y && event2.motion.y <= registerRect.y + registerRect.h) {
                                        SDL_RenderCopy(renderer, regisRedTex, NULL, &registerRect);
                                        SDL_RenderPresent(renderer);
                                    }
                                    else {
                                        SDL_RenderCopy(renderer, optionTexture[1], NULL, &registerRect);
                                        SDL_RenderPresent(renderer);
                                    }
                                }
                            }
                        }
                    }

                    // access password
                    if (event.button.x >= accessPass.x && event.button.x <= accessPass.x + 345 &&
                        event.button.y >= accessPass.y && event.button.y <= accessPass.y + 28) {
                       // delete arrow login
                        SDL_RenderCopy(renderer, deleteTexture[0], NULL, &deleteRect[0]);
                        // appear arrow pass
                        SDL_RenderCopy(renderer, arrowTexture, NULL, &arrowRect2);
                        SDL_RenderPresent(renderer);
                        SDL_RenderCopy(renderer, trickTexture, NULL, &trickRect);
                        SDL_RenderPresent(renderer);
                    
                        SDL_StartTextInput();
                        bool outPass = false;
                        SDL_Event event3;
                        //passLength = 0;
                        while (!outPass) {
                            while (SDL_PollEvent(&event3)) {
                                if (event3.type == SDL_QUIT) { outPass = 1; done = 1; }
                                //
                                if (event3.type == SDL_MOUSEBUTTONDOWN) {
                                    // press register button
                                    if (event3.button.x >= registerRect.x && event3.button.x <= registerRect.x + registerRect.w &&
                                        event3.button.y >= registerRect.y && event3.button.y <= registerRect.y + registerRect.h) {
                                        Mix_PlayChannel(-1, clickSound, 0);
                                        //   free textture
                                        SDL_DestroyTexture(imageTexture);
                                        imageTexture = NULL;
                                        SDL_DestroyTexture(textTexture);
                                        textTexture = NULL;
                                        SDL_DestroyTexture(textTexture2);
                                        textTexture2 = NULL;
                                        SDL_DestroyTexture(trickTexture);
                                        trickTexture = NULL;
                                        SDL_DestroyTexture(logAquaTex);
                                        logAquaTex = NULL;
                                        SDL_DestroyTexture(regisRedTex);
                                        regisRedTex = NULL;
                                        SDL_DestroyTexture(informTexture1);
                                        informTexture1 = NULL;
                                        SDL_DestroyTexture(informTexture2);
                                        informTexture2 = NULL;
                                        SDL_FreeSurface(temp);
                                        temp = NULL;
                                        SDL_FreeSurface(temp2);
                                        temp2 = NULL;
                                        SDL_DestroyTexture(userTexture);
                                        userTexture = NULL;
                                        SDL_DestroyTexture(passTexture);
                                        passTexture = NULL;
                                        for (int i = 0; i < 2; i++) {
                                            SDL_DestroyTexture(optionTexture[i]);
                                            optionTexture[i] = NULL;
                                            SDL_DestroyTexture(deleteTexture[i]);
                                            deleteTexture[i] = NULL;
                                        }
                                        SDL_DestroyRenderer(renderer);
                                        SDL_DestroyWindow(window);
                                        registerDisplay();
                                        return;
                                    }
                                    // press login button
                                    if (event3.button.x >= loginRect.x && event3.button.x <= loginRect.x + loginRect.w &&
                                        event3.button.y >= loginRect.y && event3.button.y <= loginRect.y + loginRect.h) {
                                        Mix_PlayChannel(-1, clickSound, 0);
                                        int check = checkRepeatedUsername(username);

                                        if (check == 1) { // 1 is false , 0 is true
                                            SDL_RenderCopy(renderer, informTexture1, NULL, &informRect);
                                            SDL_RenderPresent(renderer);
                                        }
                                        else if (check == 0) {  // 0 is false , 1 is true 
                                            int check2 = checkPassword(username, password);
                                            if (check2 == 1) {
                                                SDL_RenderCopy(renderer, informTexture2, NULL, &informRect2);
                                                SDL_RenderPresent(renderer);
                                            }
                                            else
                                                if (check2 == 0) {
                                                    SDL_DestroyWindow(window);
                                                    accountDisplay();
                                                }
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
                                        passLength -= 1;
                                        password[passLength] = '\0';
                                        printf("%s\n", password);
                                        SDL_RenderCopy(renderer, barTexture, NULL, &accessPass);
                                        if (passTexture) {
                                            SDL_DestroyTexture(passTexture);
                                        }
                                        temp2 = TTF_RenderText_Solid(font_Kanit_L24, password, white);
                                        passTexture = SDL_CreateTextureFromSurface(renderer, temp2);
                                        SDL_QueryTexture(passTexture, NULL, NULL, &passRect.w, &passRect.h);
                                        SDL_RenderCopy(renderer, passTexture, NULL, &passRect);
                                        SDL_RenderPresent(renderer);

                                        SDL_DestroyTexture(passTexture);
                                        passTexture = NULL;
                                        SDL_FreeSurface(temp2);
                                        temp2 = NULL;
                                    }
                                    else {
                                        if (event3.type == SDL_TEXTINPUT && passLength < 20) {
                                            strcat_s(password, sizeof(password), event3.text.text);
                                            passLength += strlen(event3.text.text);
                                            if (passTexture) {
                                                SDL_DestroyTexture(passTexture);
                                            }
                                            temp2 = TTF_RenderText_Solid(font_Kanit_L24, password, white);
                                            passTexture = SDL_CreateTextureFromSurface(renderer, temp2);
                                            SDL_QueryTexture(passTexture, NULL, NULL, &passRect.w, &passRect.h);
                                            SDL_RenderCopy(renderer, passTexture, NULL, &passRect);
                                            SDL_RenderPresent(renderer);

                                            SDL_DestroyTexture(passTexture);
                                            passTexture = NULL;
                                            SDL_FreeSurface(temp2);
                                            temp2 = NULL;
                                        }
                                    }
                                }
                                //
                                if (event3.type == SDL_MOUSEMOTION) {
                                    // login
                                    if (event3.motion.x >= loginRect.x && event3.motion.x <= loginRect.x + loginRect.w &&
                                        event3.motion.y >= loginRect.y && event3.motion.y <= loginRect.y + loginRect.h) {
                                        SDL_RenderCopy(renderer, logAquaTex, NULL, &loginRect);
                                        SDL_RenderPresent(renderer);
                                    }
                                    else {
                                        SDL_RenderCopy(renderer, optionTexture[0], NULL, &loginRect);
                                        SDL_RenderPresent(renderer);
                                    }
                                    // login
                                    if (event3.motion.x >= registerRect.x && event3.motion.x <= registerRect.x + registerRect.w &&
                                        event3.motion.y >= registerRect.y && event3.motion.y <= registerRect.y + registerRect.h) {
                                        SDL_RenderCopy(renderer, regisRedTex, NULL, &registerRect);
                                        SDL_RenderPresent(renderer);
                                    }
                                    else {
                                        SDL_RenderCopy(renderer, optionTexture[1], NULL, &registerRect);
                                        SDL_RenderPresent(renderer);
                                    }
                                }
                                //
                            }
                        }
                    }

                    // press login button
                    if (event.button.x >= loginRect.x && event.button.x <= loginRect.x + loginRect.w &&
                        event.button.y >= loginRect.y && event.button.y <= loginRect.y + loginRect.h) {
                        Mix_PlayChannel(-1, clickSound, 0);
                        // kanit MI 24
                        int check = checkRepeatedUsername(username); 
                        printf("%d\n", check);
                    
                        if (check == 1 ) {
                            printf("Wrong Username!\n");
                            SDL_RenderCopy(renderer, informTexture1, NULL, &informRect);
                            SDL_RenderPresent(renderer);
                        }
                        else if (check == 0 ) {
                            int check2 = checkPassword(username , password);
                            printf("%d\n", check2);
                            if (check2 == 1) {
                                printf("Wrong Pass!\n");
                                SDL_RenderCopy(renderer, informTexture2, NULL, &informRect2);
                                SDL_RenderPresent(renderer);
                            }
                            else 
                                if (check2 == 0) {
                                    SDL_StopTextInput(); // stop text input
                                    //   free textture
                                    SDL_DestroyTexture(imageTexture);
                                    imageTexture = NULL;
                                    SDL_DestroyTexture(textTexture);
                                    textTexture = NULL;
                                    SDL_DestroyTexture(textTexture2);
                                    textTexture2 = NULL;
                                    SDL_DestroyTexture(trickTexture);
                                    trickTexture = NULL;
                                    SDL_DestroyTexture(logAquaTex);
                                    logAquaTex = NULL;
                                    SDL_DestroyTexture(regisRedTex);
                                    regisRedTex = NULL;
                                    SDL_DestroyTexture(informTexture1);
                                    informTexture1 = NULL;
                                    SDL_DestroyTexture(informTexture2);
                                    informTexture2 = NULL;
                                    SDL_FreeSurface(temp);
                                    temp = NULL;
                                    SDL_FreeSurface(temp2);
                                    temp2 = NULL;
                                    SDL_DestroyTexture(userTexture);
                                    userTexture = NULL;
                                    SDL_DestroyTexture(passTexture);
                                    passTexture = NULL;
                                    for (int i = 0; i < 2; i++) {
                                        SDL_DestroyTexture(optionTexture[i]);
                                        optionTexture[i] = NULL;
                                        SDL_DestroyTexture(deleteTexture[i]);
                                        deleteTexture[i] = NULL;
                                    }
                                    SDL_DestroyRenderer(renderer);
                                    renderer = NULL;
                                    SDL_DestroyWindow(window);
                                    window = NULL;
                                    accountDisplay();
                                }
                        }
                    }
                  
                    // press register button
                    if (event.button.x >= registerRect.x && event.button.x <= registerRect.x + registerRect.w &&
                        event.button.y >= registerRect.y && event.button.y <= registerRect.y + registerRect.h) {
                        Mix_PlayChannel(-1, clickSound, 0);
                            SDL_StopTextInput(); // stop text input
                            //   free textture
                            SDL_DestroyTexture(imageTexture);
                            imageTexture = NULL;
                            SDL_DestroyTexture(textTexture);
                            textTexture = NULL;
                            SDL_DestroyTexture(textTexture2);
                            textTexture2 = NULL;
                            SDL_DestroyTexture(trickTexture);
                            trickTexture = NULL;
                            SDL_DestroyTexture(logAquaTex);
                            logAquaTex = NULL;
                            SDL_DestroyTexture(regisRedTex);
                            regisRedTex = NULL;
                            SDL_DestroyTexture(informTexture1);
                            informTexture1 = NULL;
                            SDL_DestroyTexture(informTexture2);
                            informTexture2 = NULL;
                            SDL_FreeSurface(temp);
                            temp = NULL;
                            SDL_FreeSurface(temp2);
                            temp2 = NULL;
                            SDL_DestroyTexture(userTexture);
                            userTexture = NULL;
                            SDL_DestroyTexture(passTexture);
                            passTexture = NULL;
                            for (int i = 0; i < 2; i++) {
                                SDL_DestroyTexture(optionTexture[i]);
                                optionTexture[i] = NULL;
                                SDL_DestroyTexture(deleteTexture[i]);
                                deleteTexture[i] = NULL;
                            }
                            SDL_DestroyRenderer(renderer);
                            renderer = NULL;
                            SDL_DestroyWindow(window);
                            window = NULL;
                            registerDisplay();
                            return;
                    }
                }
                else if (event.type == SDL_MOUSEMOTION) {
                    // login
                    if (event.motion.x >= loginRect.x && event.motion.x <= loginRect.x + loginRect.w &&
                        event.motion.y >= loginRect.y && event.motion.y <= loginRect.y + loginRect.h) {
                        SDL_RenderCopy(renderer, logAquaTex, NULL, &loginRect);
                        SDL_RenderPresent(renderer);
                    }
                    else {
                        SDL_RenderCopy(renderer, optionTexture[0], NULL, &loginRect);
                        SDL_RenderPresent(renderer);
                    }
                    // register
                    if (event.motion.x >= registerRect.x && event.motion.x <= registerRect.x + registerRect.w &&
                        event.motion.y >= registerRect.y && event.motion.y <= registerRect.y + registerRect.h) {
                        SDL_RenderCopy(renderer, regisRedTex, NULL, &registerRect);
                        SDL_RenderPresent(renderer);
                    }
                    else {
                        SDL_RenderCopy(renderer, optionTexture[1], NULL, &registerRect);
                        SDL_RenderPresent(renderer);
                    }
                }
            // Mouse Button
        }
        // While running
    }

    SDL_StopTextInput();
    SDL_DestroyTexture(imageTexture);
    imageTexture = NULL;
    SDL_DestroyTexture(textTexture);
    textTexture = NULL;
    SDL_DestroyTexture(textTexture2);
    textTexture2 = NULL;
    SDL_DestroyTexture(trickTexture);
    trickTexture = NULL;
    SDL_DestroyTexture(logAquaTex);
    logAquaTex = NULL;
    SDL_DestroyTexture(regisRedTex);
    regisRedTex = NULL;
    SDL_DestroyTexture(informTexture1);
    informTexture1 = NULL;
    SDL_DestroyTexture(informTexture2);
    informTexture2 = NULL;
    SDL_FreeSurface(temp);
    temp = NULL;
    SDL_FreeSurface(temp2);
    temp2 = NULL;
    SDL_DestroyTexture(userTexture);
    userTexture = NULL;
    SDL_DestroyTexture(passTexture);
    passTexture = NULL;
    for (int i = 0; i < 2; i++) {
        SDL_DestroyTexture(optionTexture[i]);
        optionTexture[i] = NULL;
        SDL_DestroyTexture(deleteTexture[i]);
        deleteTexture[i] = NULL;
    }
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(window);
    window = NULL;
    TTF_Quit();
    SDL_Quit();

}




