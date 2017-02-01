#ifndef _BUTTONS_H                 // Prevent multiple definitions if this 
#define _BUTTONS_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace buttonsNS
{

	const int WIDTH = 240;                   // image width
	const int HEIGHT = 96;                  // image height

	const int X = GAME_WIDTH / 3;   // location on screen
	const int Y = GAME_HEIGHT / 2.5;

	const int   TEXTURE_COLS = 3;
	const int   START_FRAME = 0;
	const int   HIGHSCORE_FRAME = 1;
	const int	CREDITS_FRAME = 2;
}

// inherits from Entity class
class Buttons : public Entity
{
private:
	bool clickedstate=false;
public:
	// constructor
	Buttons();

	// inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void update(float frameTime);
	bool getClickedState();
	void setClickedState();

};
#endif