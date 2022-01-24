#include "GameView.h"

GameView::GameView(SDL_Renderer* renderer) {
	this->renderer = renderer;
	floor = TextureHelper::loadTexture(renderer, TextureHelper::ASSETS_GAME + BOARD_TEXTURE);
}

void GameView::renderTexture(SDL_Texture* texture) {
	SDL_RenderCopy(renderer, texture, NULL, NULL);
}
void GameView::renderTextureE(SDL_Texture* texture, SDL_Rect* area, double rotation) {
	SDL_RenderCopyEx(renderer, texture, NULL, area, rotation, NULL, SDL_FLIP_NONE);
}

void GameView::renderGameObject(GameObject* object) {
	renderTextureE(object->getTexture(), object->getArea(), object->getRotation());
}

void GameView::renderFloor() {
	renderTexture(floor);
}

//void GameView::renderBoard(SDL_Texture* texture, __int32 screenWidth, __int32 screenHeight) {
//	SDL_RenderCopy(renderer, texture, NULL, NULL);
//	//__int32 textureWidth, textureHeight;
//	//SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
//	//__int32 cols = screenWidth / textureWidth;
//	//__int32 rows = screenHeight / textureHeight;
//	//SDL_Rect aux;
//	//aux.w = textureWidth;
//	//aux.h = textureHeight;
//	//for (int row = 0; row < rows; row++) {
//	//	for (int col = 0; col < cols; col++) {
//	//		aux.x = textureWidth * col;
//	//		aux.y = textureHeight * row;
//	//		SDL_RenderCopy(renderer, texture, NULL, &aux);
//	//	}
//	//}
//}