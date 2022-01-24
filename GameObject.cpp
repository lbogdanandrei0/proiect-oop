#include "GameObject.h"
__int32 GameObject::idGenerator = 0;

GameObject::GameObject() {
	this->id = ++idGenerator;
	this->area.x = 0;
	this->area.y = 0;
	this->area.w = 0;
	this->area.h = 0;
	this->texture = nullptr;
	this->rotation = 0;
}


GameObject::GameObject(SDL_Rect* area) {
	this->id = ++idGenerator;
	this->area.x = area->x;
	this->area.y = area->y;
	this->area.w = area->w;
	this->area.h = area->h;
	this->texture = nullptr;
	this->rotation = 0;
}