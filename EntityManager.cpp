#include "EntityManager.h"

EntityManager::EntityManager(SDL_Renderer* renderer, LinkedList<CollidingGameObject*>* colliders) {
	this->colliders = colliders;
	this->renderer = renderer;
	this->playerModel = nullptr;
	this->playerView = nullptr;
}

void EntityManager::addWalls() {
	SDL_Rect top;
	top.x = 0;
	top.y = -10;
	top.w = 1280;
	top.h = 20;
	StaticGameObject* topWall = new StaticGameObject(&top);
	topWall->setTexture(TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + "black.png"));
	colliders->add(topWall);
	SDL_Rect bottom;
	bottom.x = 0;
	bottom.y = 758;
	bottom.w = 1280;
	bottom.h = 10;
	StaticGameObject* bottomWall = new StaticGameObject(&bottom);
	bottomWall->setTexture(TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + "black.png"));
	colliders->add(bottomWall);
	SDL_Rect right;
	right.x = 1270;
	right.y = 0;
	right.w = 20;
	right.h = 768;
	StaticGameObject* rightWall = new StaticGameObject(&right);
	rightWall->setTexture(TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + "black.png"));
	colliders->add(rightWall);
	SDL_Rect left;
	left.x = -10;
	left.y = 0;
	left.w = 20;
	left.h = 768;
	StaticGameObject* leftWall = new StaticGameObject(&left);
	leftWall->setTexture(TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + "black.png"));
	colliders->add(leftWall);
}

void EntityManager::handleCollisions() {
	__int8 direction;
	LinkedNode<CollidingGameObject*>* iterator = colliders->getHead();
	while (iterator != nullptr) {
		direction = this->playerModel->isColliding(*iterator->getData());
		switch (direction)
		{
		case COLLISION_UP:
			this->playerModel->getArea()->y += 1;
			break;
		case COLLISION_UP_LEFT:
			this->playerModel->getArea()->x += 1;
			this->playerModel->getArea()->y += 1;
			break;
		case COLLISION_UP_RIGHT:
			this->playerModel->getArea()->x -= 1;
			this->playerModel->getArea()->y += 1;
			break;
		case COLLISION_RIGHT:
			this->playerModel->getArea()->x -= 1;
			break;
		case COLLISION_LEFT:
			this->playerModel->getArea()->x += 1;
			break;
		case COLLISION_DOWN:
			this->playerModel->getArea()->y -= 1;
			break;
		case COLLISION_DOWN_LEFT:
			this->playerModel->getArea()->x += 1;
			this->playerModel->getArea()->y -= 1;
			break;
		case COLLISION_DOWN_RIGHT:
			this->playerModel->getArea()->x += 1;
			this->playerModel->getArea()->y -= 1;
			break;
		default:
			break;
		}
		iterator = iterator->getNext();
	}
}

void EntityManager::initPlayer() {
	SDL_Rect collidingArea;
	collidingArea.x = 600;
	collidingArea.y = 300;
	collidingArea.w = 64;
	collidingArea.h = 64;
	this->playerModel = new PlayerModel(collidingArea.x, collidingArea.y, &collidingArea);
	this->playerView = new PlayerView();
	this->playerModel->loadUpAnimation(this->playerView->loadUpAnimation(this->renderer));
	this->playerModel->loadDownAnimation(this->playerView->loadDownAnimation(this->renderer));
	this->playerModel->loadRightAnimation(this->playerView->loadRightAnimation(this->renderer));
	this->playerModel->loadLeftAnimation(this->playerView->loadLeftAnimation(this->renderer));
	SDL_Texture** standTextures = this->playerView->loadStandTextures(this->renderer);
	this->playerModel->loadStandTextures(standTextures);
	this->playerModel->setTexture(standTextures[0]);
	objects.add(playerModel);
}

StaticGameObject* EntityManager::addBox(__int32 x, __int32 y) {
	SDL_Rect area;
	area.x = x;
	area.y = y;
	area.w = 64;
	area.h = 64;
	StaticGameObject* box = new StaticGameObject(&area);
	box->setTexture(TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + "box.png"));
	colliders->add(box);
	objects.add(box);
	return box;
}