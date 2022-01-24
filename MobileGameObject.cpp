#include "MobileGameObject.h"

MobileGameObject::MobileGameObject(double speed, SDL_Rect* collidingArea) : StaticGameObject(collidingArea) {
	this->speed = speed;
	velocity.x = 0;
	velocity.y = 0;
}

void MobileGameObject::moveUp() {
	velocity.y = -this->speed;
}

void MobileGameObject::moveDown() {
	velocity.y = this->speed;
}

void MobileGameObject::moveRight() {
	velocity.x = this->speed;
}

void MobileGameObject::moveLeft() {
	velocity.x = -this->speed;
}