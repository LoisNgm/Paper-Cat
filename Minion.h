#ifndef _MINION_H                 // Prevent multiple definitions if this 
#define _MINION_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace minionNS
{

	const int WIDTH = 48;                   // image width
	const int HEIGHT = 48;                  // image height


	const int   TEXTURE_COLS = 7;
	const int X = GAME_WIDTH - WIDTH;
	const int Y = GAME_HEIGHT-HEIGHT-160;
	const int   START_FRAME = 4;
	const int END_FRAME = 6;

	const int   HIGHSCORE_FRAME = 1;
	const int	CREDITS_FRAME = 2;
}

// inherits from Entity class
class Minion : public Entity
{
private:
	TextureManager minionTexture;
	Image minion;
public:
	// constructor
	Minion();

	// inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols);
	void update(float frameTime);

};
#endif