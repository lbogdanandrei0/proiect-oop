#pragma once
#include <iostream>
#include "SDL.h"
#include "TextureHelper.h"
#include "GameObject.h"
class GameView {
	SDL_Renderer* renderer;
	SDL_Texture* floor;
	const std::string BOARD_TEXTURE = "board.png";

public:
	GameView(SDL_Renderer* renderer);
	void renderFloor();
	void renderTexture(SDL_Texture* texture);
	void renderTextureE(SDL_Texture* texture, SDL_Rect* area);
	void renderGameObject(GameObject* object);
};