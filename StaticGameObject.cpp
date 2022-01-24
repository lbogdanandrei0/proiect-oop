#include "StaticGameObject.h"

StaticGameObject::StaticGameObject(SDL_Rect* area) : GameObject(area) {
	this->setAbilityToMove(false);
	this->setTakeBulletDamage(false);
	this->setTakeEnemyDamage(false);
	this->setCollidingArea(this->getArea());
}