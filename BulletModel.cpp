#include "BulletModel.h"

BulletModel::BulletModel(SDL_Rect* collidingArea, SDL_Point* origin, SDL_Point* destination) : MobileGameObject(1, collidingArea) {
	this->origin.x = origin->x;
	this->origin.y = origin->y;
	this->setRotation(+45/2 + 180 * asin((sqrt(destination->x * destination->x + destination->y * destination->y) * sin(atan(destination->y / (destination->x * 1.00)) - atan(origin->y / (origin->x * 1.0))) / sqrt((destination->x - origin->x) * (destination->x - origin->x) + (destination->y - origin->y) * (destination->y - origin->y)))) / PI); // TODO: compute rotation using origin and destination, also velocity
	slope = (origin->y - destination->y) / ((origin->x - destination->x) * 1.0);
	this->velocity.x = origin->x > destination->x ? -this->speed : this->speed;
	this->velocity.y = origin->y;
}

void BulletModel::update() {
	this->getArea()->y = slope * (this->getArea()->x + this->velocity.x - origin.x) + this->velocity.y * 1.0;
	this->getArea()->x += this->velocity.x;
}
