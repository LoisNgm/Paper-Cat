// GPP Common Test
#include "Items.h"

//=============================================================================
// default constructor
//=============================================================================
Items::Items() :Entity()
{
	spriteData.width = itemsNS::WIDTH;		        // size of comet
	spriteData.height = itemsNS::HEIGHT;
	spriteData.x = itemsNS::X;						// location on screen
	spriteData.y = itemsNS::Y;
	spriteData.rect.bottom = itemsNS::HEIGHT;			// rectangle to select parts of an image
	spriteData.rect.right = itemsNS::WIDTH;
	/*	startFrame = itemsNS::START_FRAME;
	int Frame = buttonsNS::HIGHSCORE_FRAME;	// highscore button for menu
	int cFrame = buttonsNS::CREDITS_FRAME;		// credits button for menu*/
	spriteData.scale = 1;

}

//=============================================================================
// Initialize the Comet.
// Post: returns true if successful, false if failed
//=============================================================================
bool Items::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{

	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// draw the comet
//=============================================================================
void Items::draw()
{
	Image::draw();              // draw comet
}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Items::update(float frameTime)
{
	Entity::update(frameTime);
}



// End of GPP Common Test
