#include "MainMenu.h"

SDL_Surface* MainMenu::loadMainMenu(SDL_Surface* windowSurface) {
	this->menuSurface = windowSurface;
	background = new GameObject();
	return windowSurface;
}

void MainMenu::renderButtons(SDL_Renderer* renderer) {
	SDL_FillRect(this->menuSurface, NULL, SDL_MapRGB(this->menuSurface->format, 0x00, 0x00, 0x00));
	background->setTexture(TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_MAIN_MENU + MAIN_MENU_BACKGROUND));
	SDL_RenderCopy(renderer, background->getTexture(), NULL, NULL);
	
	loadButtons(renderer);

	SDL_RenderCopy(renderer, button1->getTexture(), NULL, (button1->getArea()));
	SDL_RenderCopy(renderer, button2->getTexture(), NULL, (button2->getArea()));
	SDL_RenderCopy(renderer, button3->getTexture(), NULL, (button3->getArea()));
}

__int32 MainMenu::getClickedButton(__int32 x, __int32 y) {
	if (x < BUTTON_X_START || x > BUTTON_X_START + BUTTON_WIDTH || y < BUTTON_Y_START || y > BUTTON_Y_START + BUTTON_HEIGHT * 3 + BUTTON_MARGIN * 2) {
		return -1;
	}
	if (y < BUTTON_Y_START + BUTTON_HEIGHT) {
		return 1;
	}
	else if (y > BUTTON_Y_START + BUTTON_MARGIN + BUTTON_HEIGHT && y < BUTTON_Y_START + BUTTON_MARGIN + 2 * BUTTON_HEIGHT) {
		return 2;
	}
	else if (y > BUTTON_Y_START + 2 * BUTTON_HEIGHT + 2 * BUTTON_MARGIN) {
		return 3;
	}
	return -1;
}

void MainMenu::loadButtons(SDL_Renderer* renderer) {
	SDL_Rect b1coords;
	b1coords.x = BUTTON_X_START;
	b1coords.y = BUTTON_Y_START;
	b1coords.w = BUTTON_WIDTH;
	b1coords.h = BUTTON_HEIGHT;
	SDL_Rect b2coords;
	b2coords.x = BUTTON_X_START;
	b2coords.y = BUTTON_Y_START + BUTTON_HEIGHT + BUTTON_MARGIN;
	b2coords.w = BUTTON_WIDTH;
	b2coords.h = BUTTON_HEIGHT;
	SDL_Rect b3coords;
	b3coords.x = BUTTON_X_START;
	b3coords.y = BUTTON_Y_START + 2 * BUTTON_HEIGHT + 2 * BUTTON_MARGIN;
	b3coords.w = BUTTON_WIDTH;
	b3coords.h = BUTTON_HEIGHT;
	button1 = new GameObject(&b1coords);
	button2 = new GameObject(&b2coords);
	button3 = new GameObject(&b3coords);
	button1->setTexture(TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_MAIN_MENU + MAIN_MENU_PLAY_BUTTON));
	button2->setTexture(TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_MAIN_MENU + MAIN_MENU_SETTINGS_BUTTON));
	button3->setTexture(TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_MAIN_MENU + MAIN_MENU_EXIT_BUTTON));
}