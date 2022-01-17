#pragma once
#include <SDL.h>
#include <iostream>

class GameObject {
private:
	__int32 id;
	SDL_Rect area;
	SDL_Texture* texture;
public:
	GameObject() : id(1), texture(nullptr) {};
	GameObject(SDL_Rect a) : area(a), id(1), texture(nullptr) {};
	void setTexture(SDL_Texture* texture) { this->texture = texture; };
	SDL_Rect* getArea() { return &area; }
	SDL_Texture* getTexture() { return texture; }
	inline __int32 getId() { return id; }
};