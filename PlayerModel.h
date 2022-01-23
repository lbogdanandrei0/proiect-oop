#pragma once
#include "MobileGameObject.h"

class PlayerModel : public MobileGameObject {
	__int8 health;
	SDL_Texture* upAnimation[2];
	SDL_Texture* downAnimation[2];
	SDL_Texture* leftAnimation[4];
	SDL_Texture* rightAnimation[4];
	SDL_Texture* standTexture[4];
	__int8 nextUpAnimation;
	__int8 nextDownAnimation;
	__int8 nextLeftAnimation;
	__int8 nextRightAnimation;
	bool wasMovingUp;
	bool wasMovingDown;
	bool wasMovingRight;
	bool wasMovingLeft;
public:
	PlayerModel(__int32 xPos, __int32 yPos, SDL_Rect* collidingArea);
	void loadUpAnimation(SDL_Texture* animation[]);
	void loadDownAnimation(SDL_Texture* animation[]);
	void loadRightAnimation(SDL_Texture* animation[]);
	void loadLeftAnimation(SDL_Texture* animation[]);
	void loadStandTextures(SDL_Texture* textures[]);
	void lookingUp();
	void lookingDown();
	void lookingLeft();
	void lookingRight();
	virtual void update();
};