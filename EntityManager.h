#pragma once
#include "SDL.h"
#include "PlayerModel.h"
#include "PlayerView.h"

class EntityManager {
	SDL_Renderer* renderer;
	PlayerModel* playerModel;
	PlayerView* playerView;
public:
	EntityManager(SDL_Renderer* renderer);
	void initPlayer();
	PlayerModel* getPlayerModel() { return this->playerModel; }
	PlayerView* getPlayerView() { return this->playerView; }
};