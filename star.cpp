// Gameplay Programming Common Test Oct 2016
// Student Name: Ngm Hui Min, Lois
// Student Number: S10158786C
// Class: P02

#include "star.h"

//=============================================================================
// default constructor
//=============================================================================
Star::Star() : Entity()
{
	spriteData.width = starNS::WIDTH;           // size of asteroid
	spriteData.height = starNS::HEIGHT;
	spriteData.x = starNS::X;                   // location on screen
	spriteData.y = starNS::Y;
	spriteData.rect.bottom = starNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = starNS::WIDTH;
	velocity.x = 0;                             // velocity X
	velocity.y = 0;                             // velocity Y
	frameDelay = starNS::STAR_ANIMATION_DELAY;
	startFrame = starNS::STAR_FRAME;     // first frame of asteroid animation
	currentFrame = startFrame;
	radius = starNS::WIDTH / 2.0;
	mass = starNS::MASS;
	collisionType = entityNS::CIRCLE;
	spriteData.scale = 1;

}

//=============================================================================
// Initialize the Asteroid.
// Post: returns true if successful, false if failed
//=============================================================================
bool Star::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{

	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// draw the star
//=============================================================================
void Star::draw()
{

	Image::draw();              // draw star


}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Star::update(float frameTime)
{
	Entity::update(frameTime);
	spriteData.angle += frameTime * starNS::ROTATION_RATE;  // rotate the star
	spriteData.x += frameTime * velocity.x;         // move star along X 
	spriteData.y += frameTime * velocity.y;         // move star along Y

	// Bounce off walls
	if (spriteData.x > GAME_WIDTH - starNS::WIDTH*getScale())    // if hit right screen edge
	{
		spriteData.x = GAME_WIDTH - starNS::WIDTH*getScale();    // position at right screen edge
		velocity.x = -velocity.x;                   // reverse X direction
	}
	else if (spriteData.x < 0)                    // else if hit left screen edge
	{
		spriteData.x = 0;                           // position at left screen edge
		velocity.x = -velocity.x;                   // reverse X direction
	}
	if (spriteData.y > GAME_HEIGHT - starNS::HEIGHT*getScale())  // if hit bottom screen edge
	{
		spriteData.y = GAME_HEIGHT - starNS::HEIGHT*getScale();  // position at bottom screen edge
		velocity.y = -velocity.y;                   // reverse Y direction
	}
	else if (spriteData.y < 0)                    // else if hit top screen edge
	{
		spriteData.y = 0;                           // position at top screen edge
		velocity.y = -velocity.y;                   // reverse Y direction
	}
}

boolean Star::getActive()
{
	return active;
}

void Star::setActive(boolean flag)
{
	active = flag;
}