#include "BulletModel.h"

BulletModel::BulletModel(SDL_Rect* collidingArea, SDL_Point* origin, SDL_Point* destination) : MobileGameObject(1, collidingArea) {
	this->origin.x = origin->x;
	this->origin.y = origin->y;
	if (origin->y < destination->y) {
		this->setRotation(180 * atan2(destination->y - origin->y, destination->x - origin->x) / PI);
	}
	else
	{
		this->setRotation(180 * atan2(origin->y - destination->y, origin->x - destination->x) / PI + 180);
	}
	slope = (origin->y - destination->y) / ((origin->x - destination->x) * 1.0);
	this->velocity.x = origin->x > destination->x ? -this->speed : this->speed;
	this->velocity.y = origin->y;
}

void BulletModel::update() {
	this->getArea()->y = slope * (this->getArea()->x + this->velocity.x - origin.x) + this->velocity.y * 1.0;
	this->getArea()->x += this->velocity.x;
}
