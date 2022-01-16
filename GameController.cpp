#include "GameController.h"

GameController::GameController(SDL_Renderer* renderer) {
	this->renderer = renderer;
	this->view = new GameView(renderer);
	gameIsOver = false;
}

SDL_Texture** loadUpAnimation(SDL_Renderer* renderer) {
	SDL_Texture* frames[2];
	frames[0] = TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + "player_up_1.png");
	frames[1] = TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + "player_up_2.png");
	return frames;
}

SDL_Texture** loadDownAnimation(SDL_Renderer* renderer) {
	SDL_Texture* frames[2];
	frames[0] = TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + "player_down_1.png");
	frames[1] = TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + "player_down_2.png");
	return frames;
}

SDL_Texture** loadRightAnimation(SDL_Renderer* renderer) {
	SDL_Texture* frames[4];
	frames[0] = TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + "player_right_1.png");
	frames[1] = TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + "player_right_2.png");
	frames[2] = TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + "player_right_3.png");
	frames[3] = TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + "player_right_4.png");
	return frames;
}


SDL_Texture** loadLeftAnimation(SDL_Renderer* renderer) {
	SDL_Texture* frames[4];
	frames[0] = TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + "player_left_1.png");
	frames[1] = TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + "player_left_2.png");
	frames[2] = TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + "player_left_3.png");
	frames[3] = TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + "player_left_4.png");
	return frames;
}

SDL_Texture** loadStandTextures(SDL_Renderer* renderer) {
	SDL_Texture* frames[4];
	frames[0] = TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + "player_up.png");
	frames[1] = TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + "player_down.png");
	frames[2] = TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + "player_right.png");
	frames[3] = TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + "player_left.png");
	return frames;
}


void GameController::init() {
	player = new PlayerModel(648, 300);
	player->setTexture(TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + "player_up.png"));
	player->loadUpAnimation(loadUpAnimation(renderer));
	player->loadDownAnimation(loadDownAnimation(renderer));
	player->loadRightAnimation(loadRightAnimation(renderer));
	player->loadLeftAnimation(loadLeftAnimation(renderer));
	player->loadStandTextures(loadStandTextures(renderer));
	SDL_RenderClear(renderer);
	view->renderFloor();
	view->renderGameObject(player);
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
					player->moveUp();
					break;
				case SDLK_DOWN:
					player->moveDown();
					break;
				case SDLK_LEFT:
					player->moveLeft();
					break;
				case SDLK_RIGHT:
					player->moveRight();
					break;
				}
			}
			if (event.type == SDL_KEYUP) {
				switch (event.key.keysym.sym) {
				case SDLK_UP:
					player->lookingUp();
					break;
				case SDLK_DOWN:
					player->lookingDown();
					break;
				case SDLK_LEFT:
					player->lookingLeft();
					break;
				case SDLK_RIGHT:
					player->lookingRight();
					break;
				}
			}
		}
		player->update();
		SDL_RenderClear(renderer);
		view->renderFloor();
		view->renderGameObject(player);
		SDL_RenderPresent(renderer);
	}
	return 0;
}

