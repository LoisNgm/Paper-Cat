
#ifndef _BLACKHOLE_H                 // Prevent multiple definitions if this 
#define _BLACKHOLE_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace blackholeNS
{
	const int WIDTH = 192;                   // image width
	const int HEIGHT = 192;                  // image height

	const int X = 0;   // location on screen
	const int Y = 0;
	const float ROTATION_RATE = 0; // radians per second
	const float SPEED = 0;                  // 0 pixels per second
	const float MASS = 100.0f;              // mass
	const int   TEXTURE_COLS =2;
	const int   BLACKHOLE_START_FRAME =1;
	const int   BLACKHOLE_END_FRAME = 1;


	//const float BLACKHOLE_ANIMATION_DELAY = 0.1f;    // time between frames

}

// inherits from Entity class
class Blackhole : public Entity
{
private:

	boolean active = true;

public:
	// constructor
	Blackhole();

	// inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void update(float frameTime);
	boolean getActive();
	void setActive(boolean flag);

};
#endif

