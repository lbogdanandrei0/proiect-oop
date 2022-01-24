#pragma once
#include <bitset>
#include "SDL.h"
#include "Constants.h"
#include "LinkedList.h"
#include "PlayerModel.h"
#include "PlayerView.h"
#include "BulletModel.h"
#include "EnemyModel.h"

class EntityManager {
	SDL_Renderer* renderer;
	LinkedList<CollidingGameObject*>* colliders;
	LinkedList<MobileGameObject*> movingObjects;
	LinkedList<GameObject*> objects;
	PlayerModel* playerModel;
	PlayerView* playerView;
	std::bitset<1024> ids;
public:
	EntityManager(SDL_Renderer* renderer, LinkedList<CollidingGameObject*>* colliders);
	void initPlayer();
	void addWalls();
	void handleCollisions();
	void removeDeadEntities();
	void addBox(__int32 x, __int32 y);
	void addEnemy(__int32 x, __int32 y);
	void fireBullet(__int32 xOrigin, __int32 yOrigin, __int32 xDestination, __int32 yDestination);
	PlayerModel* getPlayerModel() { return this->playerModel; }
	PlayerView* getPlayerView() { return this->playerView; }
	LinkedList<GameObject*> getObjects() { return objects; }
	LinkedList<MobileGameObject*> getMovingObjects() { return movingObjects; }
};