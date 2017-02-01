#include "highscore.h"

//=============================================================================
// default constructor
//=============================================================================
Highscore::Highscore() : Image()
{

}

//=============================================================================
// Initialize the Ship.
// Post: returns true if successful, false if failed
//=============================================================================
bool Highscore::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{
	input = gamePtr->getInput();                // the input system
	return(Image::initialize(gamePtr->getGraphics(), width, height, ncols, textureM));
}

//=============================================================================
// draw the ship
//=============================================================================
void Highscore::draw()
{
	Image::draw();              // draw highscore page
}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Highscore::update(float frameTime)
{
	//if in highscore page
	input->getCharIn();
	//text updated

}