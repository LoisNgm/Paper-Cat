// Gameplay Programming Common Test Oct 2016
// Student Name: Ngm Hui Min, Lois
// Student Number: S10158786C
// Class: P02

// GPP Common Test
#include "Minion.h"

//=============================================================================
// default constructor
//=============================================================================
Minion::Minion() : Entity()
{
	spriteData.width = minionNS::WIDTH;		        // size of comet
	spriteData.height = minionNS::HEIGHT;
	spriteData.x = minionNS::X;						// location on screen
	spriteData.y = minionNS::Y;
	spriteData.rect.bottom = minionNS::HEIGHT;			// rectangle to select parts of an image
	spriteData.rect.right = minionNS::WIDTH;
	startFrame = minionNS::START_FRAME;				// start button for menu
	endFrame = minionNS::END_FRAME;
	int highscoreFrame = minionNS::HIGHSCORE_FRAME;	// highscore button for menu
	int creditsFrame = minionNS::CREDITS_FRAME;		// credits button for menu
	spriteData.scale = 1;
}

//=============================================================================
// Initialize the Comet.
// Post: returns true if successful, false if failed
//=============================================================================
bool Minion::initialize(Game *gamePtr, int width, int height, int ncols)
{
	//character textures
	if (!minionTexture.initialize(gamePtr->getGraphics(), ELEMENTS_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing minon textures"));
	minion.initialize(gamePtr->getGraphics(), width, height, ncols, &minionTexture);
	return(Entity::initialize(gamePtr, width, height, ncols, &minionTexture));
}

//=============================================================================
// draw the comet
//=============================================================================
void Minion::draw()
{

	Image::draw();              // draw comet


}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Minion::update(float frameTime)
{
	Entity::update(frameTime);

	spriteData.x += frameTime * velocity.x;         // move ship along X 
	spriteData.y += frameTime * velocity.y;         // move ship along Y
	if (spriteData.y > GAME_HEIGHT - minionNS::HEIGHT*getScale())
	{
		this->setX(0);
		this->setY(0);
	}
	if (getX() < 0 || getX() > GAME_WIDTH-getWidth())
	{
		velocity.x *= -1;
	}

}

// End of GPP Common Test