#include "GameObject.h"

SDL_Texture* GameObject::loadTexture(SDL_Renderer* renderer, const char* path) {
	SDL_Surface* surface = IMG_Load(path);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	this->texture = texture;
	return this->texture;
}