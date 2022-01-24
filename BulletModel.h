#pragma once
#include <math.h>
#include "MobileGameObject.h"

class BulletModel : public MobileGameObject {
	SDL_Point origin;
	double slope; // trebuie la ecuatia dreptei obiectului
public:
	BulletModel(SDL_Rect* collidingArea, SDL_Point* origin, SDL_Point* destination);
	virtual void update();
};