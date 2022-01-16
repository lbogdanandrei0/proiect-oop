#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>	
#include "MainMenu.h"
#include "GameController.h"


class GlobalController {
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;
	MainMenu mainMenu;
	GameController* gamecontroller;
	bool showMainMenu;
	bool exit;
	__int32 gameStatus;
public:
	static const int SCREEN_WIDTH = 1024;
	static const int SCREEN_HEIGHT = 768;

	GlobalController();
	void init();
	void run();
};