#pragma once
#include <iostream>
#include "SDL.h"
#include "TextureHelper.h"
#include "GameView.h"
#include "EntityManager.h"

class GameController {
	SDL_Renderer* renderer;
	GameView* view;
	EntityManager* entityManager;
	bool gameIsOver;
public:
	GameController() : renderer(nullptr), view(nullptr), gameIsOver(false) {};
	GameController(SDL_Renderer* renderer);
	void init();
	__int32 run();
};
