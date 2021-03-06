#pragma once
#include <SDL.h>
#include <iostream>

class GameObject {
private:
	__int32 id;
	SDL_Rect area;
	SDL_Texture* texture;
	double rotation;
public:
	static __int32 idGenerator;
	GameObject();
	GameObject(SDL_Rect* a);
	void setTexture(SDL_Texture* texture) { this->texture = texture; };
	SDL_Rect* getArea() { return &area; }
	SDL_Texture* getTexture() { return texture; }
	inline __int32 getId() { return id; }
	void setRotation(double rotation) { this->rotation = rotation; }
	double getRotation() { return rotation; }
};