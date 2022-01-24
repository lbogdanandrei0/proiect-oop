#include "GlobalController.h"

GlobalController::GlobalController() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this->showMainMenu = true;
	this->exit = false;
}

void GlobalController::init() {
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_HIDDEN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	IMG_Init(IMG_INIT_PNG);
	mainMenu.loadMainMenu(SDL_GetWindowSurface(window));
	mainMenu.renderButtons(this->renderer);
}

void GlobalController::run() {
	SDL_ShowWindow(this->window);
	while (!exit) {
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				exit = true;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				__int32 x, y;
				SDL_GetMouseState(&x, &y);
				std::cout << x << " " << y << "\n";
				if (showMainMenu) {
					__int32 buttonClicked = mainMenu.getClickedButton(x, y);
					std::cout << buttonClicked << "\n";
					switch (buttonClicked) {
					case 1:
						gamecontroller = new GameController(renderer);
						gamecontroller->init();
						gameStatus = gamecontroller->run();
						if (gameStatus == -1) {
							exit = true;
						}
						break;
					case 2:
						//settings
						break;
					case 3:
						exit = true;
						break;
					}
				}
			}
		}
		if (showMainMenu) {
			SDL_RenderPresent(renderer);
		}
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}