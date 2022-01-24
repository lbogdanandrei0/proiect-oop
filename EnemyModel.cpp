#include "EnemyModel.h"

EnemyModel::EnemyModel(SDL_Rect* follow, SDL_Rect* collidingArea) : MobileGameObject(1, collidingArea) {
	this->setHealth(5);
	this->setDamage(10);
	this->setTakeBulletDamage(true);
	this->setTakeEnemyDamage(true);
	this->follow = follow;
	wait = false;
}

void EnemyModel::update() {
	if (!wait) {
		this->getArea()->x += this->getArea()->x > follow->x ? -this->speed : this->speed;
		this->getArea()->y += this->getArea()->y > follow->y ? -this->speed : this->speed;
	}
	wait = !wait;
}