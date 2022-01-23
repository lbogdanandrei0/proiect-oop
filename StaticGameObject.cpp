#include "StaticGameObject.h"

StaticGameObject::StaticGameObject(SDL_Rect* area) : GameObject(area) {
	this->setCollidingArea(this->getArea());
}