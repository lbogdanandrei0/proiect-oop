#pragma once
#include "SDL.h"
#include "LinkedList.h"
#include "PlayerModel.h"
#include "PlayerView.h"

class EntityManager {
	SDL_Renderer* renderer;
	LinkedList<CollidingGameObject*>* colliders;
	PlayerModel* playerModel;
	PlayerView* playerView;
public:
	EntityManager(SDL_Renderer* renderer, LinkedList<CollidingGameObject*>* colliders);
	void initPlayer();
	void addWalls();
	void handleCollisions();
	PlayerModel* getPlayerModel() { return this->playerModel; }
	PlayerView* getPlayerView() { return this->playerView; }
};