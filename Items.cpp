//  Module:             Gameplay Programming
//  Assignment2:		Paper cat the hero
//  Student Name:       Ngm Hui Min, Lois	| Jessica Tan Hwee Ching	| Pang Jin Xiang
//  Student Number:     S10158786C			| S10156827G				| S10157119D

#include "Items.h"

//=============================================================================
// default constructor
//=============================================================================
Items::Items() :Entity()
{
	spriteData.width = itemsNS::WIDTH;		        // size of item
	spriteData.height = itemsNS::HEIGHT;
	spriteData.x = itemsNS::X;						// location on screen
	spriteData.y = itemsNS::Y;
	spriteData.rect.bottom = itemsNS::HEIGHT;			// rectangle to select parts of an image
	spriteData.rect.right = itemsNS::WIDTH;
	spriteData.scale = 1;

}

//=============================================================================
// Initialize the item
// Post: returns true if successful, false if failed
//=============================================================================
bool Items::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{	
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// draw the item
//=============================================================================
void Items::draw()
{
	Image::draw();              // draw item
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

