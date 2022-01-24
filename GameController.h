#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include "SDL.h"
#include "TextureHelper.h"
#include "GameView.h"
#include "EntityManager.h"
#include "LinkedList.h"

class GameController {
	SDL_Renderer* renderer;
	GameView* view;
	EntityManager* entityManager;
	LinkedList<CollidingGameObject*> colliders;
	LinkedList<GameObject*> visibleGameObjects;
	bool gameIsOver;
public:
	GameController() : renderer(nullptr), view(nullptr), gameIsOver(false) {};
	GameController(SDL_Renderer* renderer);
	void init();
	__int32 run();
	__int32 handleInput();
	void update();
	void render();
};
