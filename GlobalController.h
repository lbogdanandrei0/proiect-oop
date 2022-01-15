#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>	
#include "MainMenu.h"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

class GlobalController {
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;
	MainMenu mainMenu;
	bool showMainMenu;
	bool exit;
public:
	GlobalController();
	void init();
	void run();
};