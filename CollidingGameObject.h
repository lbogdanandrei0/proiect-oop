#pragma once
#include "SDL.h"
#include "Constants.h"
class CollidingGameObject {
	SDL_Rect* collidingArea; // trebuie initializat cu aria din GameObject
public:
	CollidingGameObject() : collidingArea(nullptr) {};
	SDL_Rect* getCollidingArea() { return collidingArea; }
	void setCollidingArea(SDL_Rect* area) { this->collidingArea = area; }
	__int32 getXColl() { return collidingArea->x; };
	__int8 isColliding(CollidingGameObject otherObject);
};