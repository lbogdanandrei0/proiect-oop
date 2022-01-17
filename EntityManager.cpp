#include "EntityManager.h"

EntityManager::EntityManager(SDL_Renderer* renderer) {
	this->renderer = renderer;
	this->playerModel = nullptr;
	this->playerView = nullptr;
}

void EntityManager::initPlayer() {
	this->playerModel = new PlayerModel(600, 300);
	this->playerView = new PlayerView();
	this->playerModel->loadUpAnimation(this->playerView->loadUpAnimation(this->renderer));
	this->playerModel->loadDownAnimation(this->playerView->loadDownAnimation(this->renderer));
	this->playerModel->loadRightAnimation(this->playerView->loadRightAnimation(this->renderer));
	this->playerModel->loadLeftAnimation(this->playerView->loadLeftAnimation(this->renderer));
	SDL_Texture** standTextures = this->playerView->loadStandTextures(this->renderer);
	this->playerModel->loadStandTextures(standTextures);
	this->playerModel->setTexture(standTextures[0]);
}