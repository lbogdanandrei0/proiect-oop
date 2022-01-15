#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class GameObject {
private:
	__int32 id;
	SDL_Rect area;
	SDL_Texture* texture;
public:
	GameObject() : id(1), texture(nullptr) {};
	GameObject(SDL_Rect a) : area(a), id(1), texture(nullptr) {};
	SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* path);
	SDL_Rect* getArea() { return &area; }
	SDL_Texture* getTexture() { return texture; }
	inline __int32 getId() { return id; }
};