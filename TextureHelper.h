#pragma once
#include <string>
#include "SDL_Image.h"
#include "SDL.h"

class TextureHelper {
public:
	static const std::string ASSETS_BASE_PATH;
	static const std::string ASSETS_MAIN_MENU;
	static const std::string ASSETS_GAME;
	static SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string path);
};