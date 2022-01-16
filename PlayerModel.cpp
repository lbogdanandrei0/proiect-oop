#include "PlayerModel.h"

PlayerModel::PlayerModel(__int32 x, __int32 y) : GameObject() {
	this->health = 100;
	this->speed = 10;
	velocity.x = 0;
	velocity.y = 0;
	wasMovingUp = false;
	wasMovingDown = false;
	wasMovingLeft = false;
	wasMovingRight = false;
	nextUpAnimation = 0;
	nextDownAnimation = 0;
	nextRightAnimation = 0;
	nextLeftAnimation = 0;
	this->getArea()->x = x;
	this->getArea()->y = y;
	this->getArea()->w = 64;
	this->getArea()->h = 64;
}

void PlayerModel::loadUpAnimation(SDL_Texture* animation[]) {
	upAnimation[0] = animation[0];
	upAnimation[1] = animation[1];
}

void PlayerModel::loadDownAnimation(SDL_Texture* animation[]) {
	downAnimation[0] = animation[0];
	downAnimation[1] = animation[1];
}

void PlayerModel::loadRightAnimation(SDL_Texture* animation[]) {
	rightAnimation[0] = animation[0];
	rightAnimation[1] = animation[1];
	rightAnimation[2] = animation[2];
	rightAnimation[3] = animation[3];
}

void PlayerModel::loadLeftAnimation(SDL_Texture* animation[]) {
	leftAnimation[0] = animation[0];
	leftAnimation[1] = animation[1];
	leftAnimation[2] = animation[2];
	leftAnimation[3] = animation[3];
}

void PlayerModel::loadStandTextures(SDL_Texture* textures[]) {
	this->standTexture[0] = textures[0];
	this->standTexture[1] = textures[1];
	this->standTexture[2] = textures[2];
	this->standTexture[3] = textures[3];
}


void PlayerModel::moveUp() {
	velocity.y = -this->speed;
}

void PlayerModel::moveDown() {
	velocity.y = this->speed;
}

void PlayerModel::moveRight() {
	velocity.x = this->speed;
}

void PlayerModel::moveLeft() {
	velocity.x = -this->speed;
}

void PlayerModel::update() {
	if (this->velocity.x) {
		if (velocity.x > 0) {
			wasMovingRight = true;
			wasMovingUp = wasMovingDown = wasMovingLeft = false;
			if (nextRightAnimation == 3) {
				this->setTexture(this->rightAnimation[3]);
				nextRightAnimation = 0;
			}
			else {
				this->setTexture(this->rightAnimation[nextRightAnimation++]);
			}
		}
		else {
			wasMovingLeft = true;
			wasMovingUp = wasMovingDown = wasMovingRight = false;
			if (nextLeftAnimation == 3) {
				this->setTexture(this->leftAnimation[3]);
				nextLeftAnimation = 0;
			}
			else {
				this->setTexture(this->leftAnimation[nextLeftAnimation++]);
			}
		}
		this->getArea()->x += this->velocity.x;
		this->velocity.x = 0;
	}
	if (this->velocity.y) {
		if (velocity.y > 0) {
			wasMovingDown = true;
			wasMovingUp = wasMovingRight = wasMovingLeft = false;
			if (nextDownAnimation == 1) {
				this->setTexture(this->downAnimation[1]);
				nextDownAnimation = 0;
			}
			else {
				this->setTexture(this->downAnimation[nextDownAnimation++]);
			}
		}
		else {
			wasMovingUp = true;
			wasMovingRight = wasMovingDown = wasMovingLeft = false;
			if (nextUpAnimation == 1) {
				this->setTexture(this->upAnimation[1]);
				nextUpAnimation = 0;
			}
			else {
				this->setTexture(this->upAnimation[nextUpAnimation++]);
			}
		}
		this->getArea()->y += this->velocity.y;
		this->velocity.y = 0;
	}
}

void PlayerModel::lookingUp() {
	if (wasMovingUp)
		this->setTexture(this->standTexture[0]);
}
void PlayerModel::lookingDown() {
	if (wasMovingDown)
		this->setTexture(this->standTexture[1]);
}
void PlayerModel::lookingLeft() {
	if (wasMovingLeft)
		this->setTexture(this->standTexture[3]);
}
void PlayerModel::lookingRight() {
	if (wasMovingRight)
		this->setTexture(this->standTexture[2]);
}