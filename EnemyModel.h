#pragma once
#include "MobileGameObject.h"

class EnemyModel : public MobileGameObject {
	SDL_Rect* follow;
	bool wait;
public:
	EnemyModel(SDL_Rect* toFollow, SDL_Rect* collidingArea);
	virtual void update();
};