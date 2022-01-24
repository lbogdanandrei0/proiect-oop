#pragma once
#include "SDL.h"
#include "Constants.h"
class CollidingGameObject {
	__int16 health;
	__int16 damage;
	bool canMove;
	bool canTakeBulletDamage;
	bool canTakeEnemyDamage;
	SDL_Rect* collidingArea; // trebuie initializat cu aria din GameObject
public:
	CollidingGameObject() : collidingArea(nullptr), canMove(false) {};
	SDL_Rect* getCollidingArea() { return collidingArea; }
	void setCollidingArea(SDL_Rect* area) { this->collidingArea = area; }
	void setAbilityToMove(bool canMove) { this->canMove = canMove; }
	bool getCanMove() { return canMove; }
	void setTakeBulletDamage(bool canTakeDamage) { this->canTakeBulletDamage = canTakeDamage; }
	bool takeBulletDamage() { return canTakeBulletDamage; }
	void setTakeEnemyDamage(bool canTakeDamage) { this->canTakeEnemyDamage = canTakeDamage; }
	bool takeEnemyDamage() { return canTakeEnemyDamage; }
	void takeDamage(__int16 amount) { this->health -= amount; }
	__int16 getDamage() { return damage; }
	void setDamage(__int16 damage) { this->damage = damage; }
	__int16 getHealth() { return health; }
	void setHealth(__int16 health) { this->health = health; }
	__int32 getXColl() { return collidingArea->x; };
	__int8 isColliding(CollidingGameObject otherObject);
};