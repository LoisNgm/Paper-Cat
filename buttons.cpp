// Gameplay Programming Common Test Oct 2016
// Student Name: Ngm Hui Min, Lois
// Student Number: S10158786C
// Class: P02

// GPP Common Test
#include "buttons.h"

//=============================================================================
// default constructor
//=============================================================================
Buttons::Buttons() : Entity()
{
	spriteData.width = buttonsNS::WIDTH;		        // size of comet
	spriteData.height = buttonsNS::HEIGHT;
	spriteData.x = buttonsNS::X;						// location on screen
	spriteData.y = buttonsNS::Y;
	spriteData.rect.bottom = buttonsNS::HEIGHT;			// rectangle to select parts of an image
	spriteData.rect.right = buttonsNS::WIDTH;
	startFrame = buttonsNS::START_FRAME;				// start button for menu
	int highscoreFrame = buttonsNS::HIGHSCORE_FRAME;	// highscore button for menu
	int creditsFrame = buttonsNS::CREDITS_FRAME;		// credits button for menu
	spriteData.scale = 1;

}

//=============================================================================
// Initialize the Comet.
// Post: returns true if successful, false if failed
//=============================================================================
bool Buttons::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{

	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// draw the comet
//=============================================================================
void Buttons::draw()
{

	Image::draw();              // draw comet


}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Buttons::update(float frameTime)
{
	Entity::update(frameTime);
	setClickedState();
	spriteData.x += frameTime * velocity.x;         // move ship along X 
	spriteData.y += frameTime * velocity.y;         // move ship along Y
/*	if (spriteData.y > GAME_HEIGHT - buttonsNS::HEIGHT*getScale())
	{
		this->setX(0);
		this->setY(0);
	}*/

}
void Buttons::setClickedState()
{
	//left click start
	if (input->getMouseLButton())
	{
		if (input->getMouseX() > this->getX() && input->getMouseX() < this->getX() + this->getWidth() &&
			input->getMouseY()> this->getY()-10.0f && input->getMouseY() <this->getY() + this->getHeight()-10.0f) //where by 10.0f is a float to enable the left click function to work more accurately
		{
			 this->clickedstate = true;
		}
	}
	else
	{
		this->clickedstate = false;
	}
}
bool Buttons::getClickedState()
{
	return this->clickedstate;
}

		
// End of GPP Common Test