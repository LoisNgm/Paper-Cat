#include "scissors.h"

//=============================================================================
// default constructor
//=============================================================================
Scissors::Scissors() : Entity()
{
	spriteData.width = scissorsNS::WIDTH;           // size of asteroid
	spriteData.height = scissorsNS::HEIGHT;
	spriteData.x = scissorsNS::X;                   // location on screen
	spriteData.y = scissorsNS::Y;
	spriteData.rect.bottom = scissorsNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = scissorsNS::WIDTH;
	velocity.x = 300;                             // velocity X
	velocity.y = 0;                             // velocity Y
	frameDelay = scissorsNS::SCISSORS_ANIMATION_DELAY;
	startFrame = scissorsNS::SCISSORS_START_FRAME;     // first frame of asteroid animation
	endFrame = scissorsNS::SCISSORS_END_FRAME;     // last frame of asteroid animation
	currentFrame = startFrame;
	mass = scissorsNS::MASS;
	spriteData.scale = 1;

}

//=============================================================================
// Initialize the Asteroid.
// Post: returns true if successful, false if failed
//=============================================================================
bool Scissors::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{

	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// draw the asteroid
//=============================================================================
void Scissors::draw()
{

	Image::draw();              // draw asteroid


}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Scissors::update(float frameTime)
{

	setX(getX() + frameTime*velocity.x);
	Entity::update(frameTime);
	if (getX() > GAME_WIDTH)
	{
		setX(0);
		setY(50 * (rand() % 15 + 1));
	}
}

boolean Scissors::getActive()
{
	return active;
}

void Scissors::setActive(boolean flag)
{
	active = flag;
}