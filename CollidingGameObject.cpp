#include "CollidingGameObject.h"
#include <iostream>

bool contains(SDL_Rect polygon, __int32 x, __int32 y) {
	if (x >= polygon.x && x <= polygon.x + polygon.w && y >= polygon.y && y <= polygon.y + polygon.h)
		return true;
	return false;
}

__int8 CollidingGameObject::isColliding(CollidingGameObject other) {
	__int32 thisXLeft = this->collidingArea->x;
	__int32 thisYUp = this->collidingArea->y;
	__int32 thisXRight = this->collidingArea->x + this->collidingArea->w;
	__int32 thisYDown = this->collidingArea->y + this->collidingArea->h;

	__int32 otherXLeft = other.collidingArea->x;
	__int32 otherYUp = other.collidingArea->y;
	__int32 otherXRight = other.collidingArea->x + other.collidingArea->w;
	__int32 otherYDown = other.collidingArea->y + other.collidingArea->h;

	if (contains(*other.getCollidingArea(), thisXLeft, thisYUp) && contains(*other.getCollidingArea(), thisXRight, thisYUp)) { //up
		return 1;
	}

	if (contains(*other.getCollidingArea(), thisXRight, thisYUp)) { //right
		return 2;
	}

	if (contains(*other.getCollidingArea(), thisXLeft, thisYDown) && contains(*other.getCollidingArea(), thisXLeft, thisYUp)) { //left
		return 3;
	}

	if (contains(*other.getCollidingArea(), thisXRight, thisYDown)) { //down
		return 4;
	}

	return 0;
}