#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Constants.h"
#include "GameObject.h"
#include "TextureHelper.h"

const __int32 BUTTON_WIDTH = 150;
const __int32 BUTTON_HEIGHT = 60;
const __int32 BUTTON_X_START = SCREEN_WIDTH / 2 - BUTTON_WIDTH / 2;
const __int32 BUTTON_Y_START = SCREEN_HEIGHT / 2 - BUTTON_HEIGHT / 2;
const __int8 BUTTON_MARGIN = 10;

class MainMenu {
	SDL_Surface* menuSurface;
	GameObject* background;
	GameObject* button1;
	GameObject* button2;
	GameObject* button3;
public:
	SDL_Surface* loadMainMenu(SDL_Surface* windowSurface);
	void renderButtons(SDL_Renderer* renderer);
	void loadButtons(SDL_Renderer* renderer);
	__int32 getClickedButton(__int32 x, __int32 y);
	SDL_Surface* getMenuSurface() { return menuSurface; }
};