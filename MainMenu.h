#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "GameObject.h"
#include "TextureHelper.h"

const __int32 BUTTON_X_START = 452;
const __int32 BUTTON_Y_START = 341;
const __int32 BUTTON_WIDTH = 150;
const __int32 BUTTON_HEIGHT = 60;
const __int8 BUTTON_MARGIN = 10;
const std::string MAIN_MENU_BACKGROUND = "mainMenuBackground.png";
const std::string MAIN_MENU_PLAY_BUTTON = "playButton.png";
const std::string MAIN_MENU_SETTINGS_BUTTON = "settingsButton.png";
const std::string MAIN_MENU_EXIT_BUTTON = "exitButton.png";

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