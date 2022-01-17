#include "GameController.h"

GameController::GameController(SDL_Renderer* renderer) {
	this->renderer = renderer;
	this->view = new GameView(renderer);
	this->entityManager = new EntityManager(renderer);
	this->entityManager->initPlayer();
	gameIsOver = false;
}

void GameController::init() {
	SDL_RenderClear(renderer);
	view->renderFloor();
	view->renderGameObject(this->entityManager->getPlayerModel());
}

__int32 GameController::run() {
	SDL_Event event;
	while (!gameIsOver) {
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
		}
		this->entityManager->getPlayerModel()->update();
		SDL_RenderClear(renderer);
		view->renderFloor();
		view->renderGameObject(this->entityManager->getPlayerModel());
		SDL_RenderPresent(renderer);
	}
	return 0;
}

