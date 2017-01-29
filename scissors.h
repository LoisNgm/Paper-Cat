
#ifndef _SCISSORS_H                 // Prevent multiple definitions if this 
#define _SCISSORS_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace scissorsNS
{
	const int WIDTH = 96;                   // image width
	const int HEIGHT = 48;                  // image height

	const int X = 0;   // location on screen
	const int Y = 0;
	const float SPEED = 0;                  // 0 pixels per second
	const float MASS = 100.0f;              // mass


	const int   TEXTURE_COLS = 4;
	const int   SCISSORS_START_FRAME = 4;
	const int   SCISSORS_END_FRAME = 5;


	const float SCISSORS_ANIMATION_DELAY = 1.0f;    // time between frames

}

// inherits from Entity class
class Scissors : public Entity
{
private:

	boolean active = true;

public:
	// constructor
	Scissors();

	// inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void update(float frameTime);


	boolean getActive();
	void setActive(boolean flag);

};
#endif

