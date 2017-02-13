
#ifndef _STAR_H                 // Prevent multiple definitions if this 
#define _STAR_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace starNS
{

	const int WIDTH = 48;                   // image width
	const int HEIGHT = 48;                  // image height

	const int X = 0;   // location on screen
	const int Y = 0;
	const float ROTATION_RATE = 0; // radians per second
	const float SPEED = 0;                  // 0 pixels per second
	const float MASS = 100.0f;              // mass


	const int   TEXTURE_COLS = 8;
	const int   STAR_FRAME = 48;


	const float STAR_ANIMATION_DELAY = 0.1f;    // time between frames

}

// inherits from Entity class
class Star : public Entity
{
private:

	boolean active = true;

public:
	// constructor
	Star();

	// inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void update(float frameTime);


	boolean getActive();
	void setActive(boolean flag);

};
#endif

