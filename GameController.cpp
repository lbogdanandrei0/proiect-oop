#include "GameController.h"

GameController::GameController(SDL_Renderer* renderer) {
	this->renderer = renderer;
	this->view = new GameView(renderer);
	this->entityManager = new EntityManager(renderer, &colliders);
	this->entityManager->initPlayer();
	this->entityManager->addWalls();
	this->entityManager->addBox(200, 300);
	this->entityManager->addBox(400, 300);
	enemySpawnDelay = std::chrono::seconds(2);
	lastEnemyTimestamp = std::chrono::system_clock::now();
	gameIsOver = false;
}

void GameController::init() {
	SDL_RenderClear(renderer);
	visibleGameObjects = this->entityManager->getObjects();
	view->renderFloor();
	view->renderGameObject(this->entityManager->getPlayerModel());
}

__int32 GameController::run() {
	std::chrono::time_point<std::chrono::high_resolution_clock> begin;
	std::chrono::time_point<std::chrono::high_resolution_clock> end;
	std::chrono::duration<double> duration;
	while (!gameIsOver) {
		begin = std::chrono::high_resolution_clock::now();
		if (handleInput() == -1) {
			return -1;
		}
		update();
		render();
		end = std::chrono::high_resolution_clock::now();
		duration = (end - begin);
		if (duration.count() * 1000 < FRAMERATE) {
			std::this_thread::sleep_for(std::chrono::milliseconds((int)(FRAMERATE - duration.count() * 1000)));
		}
	}
	return 0;
}

__int32 GameController::handleInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			gameIsOver = true;
			return -1;
		}
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				this->entityManager->getPlayerModel()->moveUp();
				break;
			case SDLK_DOWN:
				this->entityManager->getPlayerModel()->moveDown();
				break;
			case SDLK_LEFT:
				this->entityManager->getPlayerModel()->moveLeft();
				break;
			case SDLK_RIGHT:
				this->entityManager->getPlayerModel()->moveRight();
				break;
			}
		}
		if (event.type == SDL_KEYUP) {
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				this->entityManager->getPlayerModel()->lookingUp();
				break;
			case SDLK_DOWN:
				this->entityManager->getPlayerModel()->lookingDown();
				break;
			case SDLK_LEFT:
				this->entityManager->getPlayerModel()->lookingLeft();
				break;
			case SDLK_RIGHT:
				this->entityManager->getPlayerModel()->lookingRight();
				break;
			}
		}
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
			this->entityManager->fireBullet(this->entityManager->getPlayerModel()->getArea()->x, this->entityManager->getPlayerModel()->getArea()->y, event.button.x, event.button.y);
		}
	}
}
void GameController::update() {
	LinkedNode<MobileGameObject*>* m = this->entityManager->getMovingObjects().getHead();
	while (m != nullptr) {
		m->getData()->update();
		m = m->getNext();
	}
	this->entityManager->handleCollisions();
	this->entityManager->removeDeadEntities();
	if (std::chrono::duration<double>(std::chrono::system_clock::now() - lastEnemyTimestamp) > enemySpawnDelay) {
		this->entityManager->addEnemy(100, 100);
		this->lastEnemyTimestamp = std::chrono::system_clock::now();
	}
}
void GameController::render() {
	SDL_RenderClear(renderer);
	view->renderFloor();
	LinkedNode<GameObject*>* obj = this->entityManager->getObjects().getHead();
	while (obj != nullptr) {
		view->renderGameObject(obj->getData());
		obj = obj->getNext();
	}
	SDL_RenderPresent(renderer);
}

