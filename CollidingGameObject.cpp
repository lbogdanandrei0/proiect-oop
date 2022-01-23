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

	if (contains(*other.getCollidingArea(), thisXLeft, thisYUp)) { //up
		if (contains(*other.getCollidingArea(), thisXLeft, thisYDown)) {
			return COLLISION_LEFT;
		}
		if (contains(*other.getCollidingArea(), thisXRight, thisYUp)) {
			return COLLISION_UP;
		}
		return COLLISION_UP_LEFT;
	}

	if (contains(*other.getCollidingArea(), thisXRight, thisYUp)) { //right
		if (contains(*other.getCollidingArea(), thisXRight, thisYDown)) {
			return COLLISION_RIGHT;
		}
		return COLLISION_UP_RIGHT;
	}

	if (contains(*other.getCollidingArea(), thisXLeft, thisYDown)) { //left
		if (contains(*other.getCollidingArea(), thisXRight, thisYDown)) {
			return COLLISION_DOWN;
		}
		return COLLISION_DOWN_LEFT;
	}

	if (contains(*other.getCollidingArea(), thisXRight, thisYDown)) { //down
		return COLLISION_DOWN_RIGHT;
	}

	return -1;
}