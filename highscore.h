
#ifndef _HIGHSCORE_H                 // Prevent multiple definitions if this 
#define _HIGHSCORE_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "image.h"
#include "input.h"
#include "game.h"
#include "textDX.h"

namespace highscoreNS
{
	const int WIDTH = 48;                   // image width
	const int HEIGHT = 48;                  // image height
	const int X = 0;   // location on screen
	const int Y = 0;
	const float SPEED = 0;                  // 0 pixels per second
	const float MASS = 100.0f;              // mass
	const int   TEXTURE_COLS = 4;
	const int   _START_FRAME = 0;
	const int   CAT_END_FRAME = 3;
	const float CAT_ANIMATION_DELAY = 1.0f;    // time between frames
}

class Highscore: public Image
{
private:
	Input   *input;         // pointer to the input system
	TextDX *nameText;
public:
	// constructor
	Highscore();

	// inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void update(float frameTime);
};
#endif

