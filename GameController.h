#pragma once
#include <iostream>
#include "SDL.h"
#include "TextureHelper.h"
#include "GameView.h"
#include "PlayerModel.h"
class GameController {
	SDL_Renderer* renderer;
	GameView* view;
	PlayerModel* player;
	bool gameIsOver;
public:
	GameController() : renderer(nullptr), view(nullptr), gameIsOver(false) {};
	GameController(SDL_Renderer* renderer);
	void init();
	__int32 run();
};
