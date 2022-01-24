#pragma once
#include "StaticGameObject.h"

class MobileGameObject : public StaticGameObject {
protected:
	SDL_Point velocity;
	double speed;
public:
	MobileGameObject(double speed, SDL_Rect* collidingArea);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	virtual void update() = 0;
};