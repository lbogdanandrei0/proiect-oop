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
	ids.reset();
	LinkedNode<CollidingGameObject*>* iterator = colliders->getHead();
	while (iterator != nullptr) {
		LinkedNode<CollidingGameObject*>* other = colliders->getHead();
		while (other != nullptr) {
			if (iterator != other) {
				direction = iterator->getData()->isColliding(*other->getData());
				if (direction != -1) {
					if (iterator->getData()->getCanMove() == true && other->getData()->getCanMove() == false) {
						MobileGameObject* m = static_cast<MobileGameObject*>(iterator->getData());
						if (!m->takeBulletDamage() && !m->takeEnemyDamage()) {
							ids[m->getId()] = 1;
						}
						else {
							switch (direction)
							{
							case COLLISION_UP:
								m->getArea()->y += 10;
								break;
							case COLLISION_UP_LEFT:
								m->getArea()->x += 5;
								m->getArea()->y += 5;
								break;
							case COLLISION_UP_RIGHT:
								m->getArea()->x -= 5;
								m->getArea()->y += 5;
								break;
							case COLLISION_RIGHT:
								m->getArea()->x -= 10;
								break;
							case COLLISION_LEFT:
								m->getArea()->x += 10;
								break;
							case COLLISION_DOWN:
								m->getArea()->y -= 10;
								break;
							case COLLISION_DOWN_LEFT:
								m->getArea()->x += 5;
								m->getArea()->y -= 5;
								break;
							case COLLISION_DOWN_RIGHT:
								m->getArea()->x -= 5;
								m->getArea()->y -= 5;
								break;
							default:
								break;
							}
						}
					}
					else {
						if (other->getData()->takeBulletDamage()) {
							other->getData()->takeDamage(iterator->getData()->getDamage());
							if (other->getData()->getHealth() <= 0) {
								StaticGameObject* m = static_cast<StaticGameObject*>(other->getData());
								ids[m->getId()] = 1;
								colliders->deleteNode(other);
							}
						}
					}
				}
			}
			other = other->getNext();
		}
		iterator = iterator->getNext();
	}
}

void EntityManager::removeDeadEntities() {
	LinkedNode<GameObject*>* iterator = objects.getHead();
	LinkedNode<MobileGameObject*>* iterator2 = movingObjects.getHead();
	while (iterator != nullptr) {
		if (ids[iterator->getData()->getId()]) {
			objects.deleteNode(iterator);
		}
		iterator = iterator->getNext();
	}
	while (iterator2 != nullptr) {
		if (ids[iterator2->getData()->getId()]) {
			movingObjects.deleteNode(iterator2);
		}
		iterator2 = iterator2->getNext();
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
	colliders->add(playerModel);
	objects.add(playerModel);
	movingObjects.add(playerModel);
}

void EntityManager::addBox(__int32 x, __int32 y) {
	SDL_Rect area;
	area.x = x;
	area.y = y;
	area.w = 64;
	area.h = 64;
	StaticGameObject* box = new StaticGameObject(&area);
	box->setTexture(TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + "box.png"));
	colliders->add(box);
	objects.add(box);
}

void EntityManager::addEnemy(__int32 x, __int32 y) {
	SDL_Point playerCoords;
	SDL_Rect area;
	area.x = x;
	area.y = y;
	area.w = 32;
	area.h = 32;
	EnemyModel* enemy = new EnemyModel(this->playerModel->getArea(), &area);
	enemy->setTexture(TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + "enemy1.png"));
	colliders->add(enemy);
	objects.add(enemy);
	movingObjects.add(enemy);
}

void EntityManager::fireBullet(__int32 xOrigin, __int32 yOrigin, __int32 xDestination, __int32 yDestination) {
	SDL_Point origin;
	SDL_Point destination;
	SDL_Rect collidingArea;
	origin.x = xOrigin + 32;
	origin.y = yOrigin + 32;
	destination.x = xDestination;
	destination.y = yDestination;
	collidingArea.x = xOrigin + 32;
	collidingArea.y = yOrigin + 32;
	collidingArea.w = 32;
	collidingArea.h = 12;

	BulletModel* bullet = new BulletModel(&collidingArea, &origin, &destination);
	bullet->setTexture(TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + "bullet1.png"));
	colliders->add(bullet);
	objects.add(bullet);
	movingObjects.add(bullet);
}