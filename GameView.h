#pragma once
#include <iostream>
#include "SDL.h"
#include "Constants.h"
#include "TextureHelper.h"
#include "GameObject.h"
class GameView {
	SDL_Renderer* renderer;
	SDL_Texture* floor;

public:
	GameView(SDL_Renderer* renderer);
	void renderFloor();
	void renderTexture(SDL_Texture* texture);
	void renderTextureE(SDL_Texture* texture, SDL_Rect* area, double rotation);
	void renderGameObject(GameObject* object);
};