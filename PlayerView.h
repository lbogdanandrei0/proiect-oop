#pragma once
#include "SDL.h"
#include "TextureHelper.h"

class PlayerView {

public:
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
};