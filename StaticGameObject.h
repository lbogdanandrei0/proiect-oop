#pragma once
#include "GameObject.h"
#include "CollidingGameObject.h"

class StaticGameObject : public GameObject, public CollidingGameObject {
public:
	StaticGameObject(SDL_Rect* area);
};