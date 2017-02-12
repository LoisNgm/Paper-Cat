#ifndef _ITEMS_H                 // Prevent multiple definitions if this 
#define _ITEMS_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
//  Module:             Gameplay Programming
//  Assignment2:		Paper cat the hero
//  Student Name:       Ngm Hui Min, Lois	| Jessica Tan Hwee Ching	| Pang Jin Xiang
//  Student Number:     S10158786C			| S10156827G				| S10157119D

#include "constants.h"

namespace itemsNS
{

	const int WIDTH = 32;                   // image width
	const int HEIGHT = 32;                  // image height

	const int X = GAME_WIDTH / 3;   // location on screen
	const int Y = GAME_HEIGHT / 2.5;

	const int   TEXTURE_COLS = 6;
	const int   STUN_FRAME = 0;
	const int   TIMES2_FRAME = 1;
	const int	UPDATE_FRAME = 2;
	const int	FLASH_FRAME = 3;
	const int	COIN_FRAME = 4;
	const int	ATTACK_FRAME = 5;
}

// inherits from Entity class
class Items : public Entity
{
private:
	int state = -1;
public:
	// constructor
	Items();

	// inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void update(float frameTime);
};
#endif
