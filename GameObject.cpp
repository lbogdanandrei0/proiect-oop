#include "GameObject.h"
GameObject::GameObject(SDL_Rect* area) {
	this->area.x = area->x;
	this->area.y = area->y;
	this->area.w = area->w;
	this->area.h = area->h;
}