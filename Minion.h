#ifndef _MINION_H                 // Prevent multiple definitions if this 
#define _MINION_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace minionNS
{

	const int SMALL_MINION_WIDTH = 48;                   // image width
	const int SMALL_MINION_HEIGHT = 48;                  // image height
	 
	const int LARGE_MINION_WIDTH = 192;                   // image width
	const int LARGE_MINION_HEIGHT = 192;                  // image height

	const int X = GAME_WIDTH - LARGE_MINION_WIDTH;
	const int Y = GAME_HEIGHT - LARGE_MINION_HEIGHT;
	const int	LARGE_MINION_TEXTURE_COLS = 2;
	const int LARGE_MINION_FRAME = 0;

	const int   SMALL_MINION_TEXTURE_COLS = 8;

	const int   SMALL_MINION_START_FRAME = 36;
	const int	SMALL_MINION_END_FRAME = 38;


}

// inherits from Entity class
class Minion : public Entity
{
private:
	TextureManager minionTexture;
	TextureManager minionBossTexture;
	Image minionBoss;
	Image minion;
	Image minion2;
	Image minion3;
public:
	// constructor
	Minion();

	// inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols);
	void update(float frameTime);
	void collisionDetectionWithCharacter(Entity cat);
};
#endif