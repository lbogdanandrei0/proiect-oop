#include "TextureHelper.h"

SDL_Texture* TextureHelper::loadTexture(SDL_Renderer* renderer, std::string path) {
	SDL_Surface* surface = IMG_Load(path.c_str());
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	return texture;
}

const std::string TextureHelper::ASSETS_BASE_PATH = "./assets";
const std::string TextureHelper::ASSETS_MAIN_MENU = TextureHelper::ASSETS_BASE_PATH + "/mainMenu/";
const std::string TextureHelper::ASSETS_GAME = TextureHelper::ASSETS_BASE_PATH + "/game/";