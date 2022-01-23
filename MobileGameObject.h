#pragma once
#include "StaticGameObject.h"

class MobileGameObject : public StaticGameObject {
protected:
	SDL_Point velocity;
	__int32 speed;
public:
	MobileGameObject(__int32 speed, SDL_Rect* collidingArea);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	virtual void update() = 0;
};