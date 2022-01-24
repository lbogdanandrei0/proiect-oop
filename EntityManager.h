#pragma once
#include "SDL.h"
#include "Constants.h"
#include "LinkedList.h"
#include "PlayerModel.h"
#include "PlayerView.h"
#include "BulletModel.h"

class EntityManager {
	SDL_Renderer* renderer;
	LinkedList<CollidingGameObject*>* colliders;
	LinkedList<MobileGameObject*> movingObjects;
	LinkedList<GameObject*> objects;
	PlayerModel* playerModel;
	PlayerView* playerView;
public:
	EntityManager(SDL_Renderer* renderer, LinkedList<CollidingGameObject*>* colliders);
	void initPlayer();
	void addWalls();
	void handleCollisions();
	StaticGameObject* addBox(__int32 x, __int32 y);
	void fireBullet(__int32 xOrigin, __int32 yOrigin, __int32 xDestination, __int32 yDestination);
	PlayerModel* getPlayerModel() { return this->playerModel; }
	PlayerView* getPlayerView() { return this->playerView; }
	LinkedList<GameObject*> getObjects() { return objects; }
	LinkedList<MobileGameObject*> getMovingObjects() { return movingObjects; }
};