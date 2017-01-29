
#include "papercat.h"

//=============================================================================
// Constructor
//=============================================================================
Papercat::Papercat()
{}

//=============================================================================
// Destructor
//=============================================================================
Papercat::~Papercat()
{
	releaseAll();           // call onLostDevice() for every graphics item
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void Papercat::initialize(HWND hwnd)
{
	Game::initialize(hwnd); // throws GameError

	// menu texture
	if (!menuTexture.initialize(graphics, MENU_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu texture"));

	// background stage texture
	if (!backgroundStageTexture.initialize(graphics, BACKGROUND_STAGE_PAGE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing backround stage texture"));
	//buttons
	if (!buttonsTexture.initialize(graphics, BUTTONS_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing button texture"));

	// main textures
	if (!mainTexture.initialize(graphics, ELEMENTS_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing main texture"));


	//   // nebula texture
	//   if (!nebulaTexture.initialize(graphics,NEBULA_IMAGE))
	//       throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing nebula texture"));

	//   // main game textures
	//   if (!shipTexture.initialize(graphics,SHIP_IMAGE))
	//       throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ship texture"));
	//// main game textures
	//if (!asteroidTexture.initialize(graphics, ASTEROID_IMAGE))
	//	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing asteroid texture"));

	//   // nebula image
	//   if (!nebula.initialize(graphics,0,0,0,&nebulaTexture))
	//       throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing nebula"));

	// menu image
	if (!menu.initialize(graphics, 0, 0, 0, &menuTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu"));

	// background stage image
	if (!backgroundStage.initialize(graphics, 0, 0, 0, &backgroundStageTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background stage"));

	// buttons
	// start
	if (!startButton.initialize(this, buttonsNS::WIDTH, buttonsNS::HEIGHT, buttonsNS::TEXTURE_COLS, &buttonsTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing buttons"));
	startButton.setFrames(buttonsNS::START_FRAME, buttonsNS::START_FRAME);
	startButton.setCurrentFrame(buttonsNS::START_FRAME);
	startButton.setX(GAME_WIDTH / 3);
	startButton.setY(GAME_HEIGHT / 2.5);

	// highscore
	if (!highscoreButton.initialize(this, buttonsNS::WIDTH, buttonsNS::HEIGHT, buttonsNS::TEXTURE_COLS, &buttonsTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing buttons"));
	highscoreButton.setFrames(buttonsNS::HIGHSCORE_FRAME, buttonsNS::HIGHSCORE_FRAME);
	highscoreButton.setCurrentFrame(buttonsNS::HIGHSCORE_FRAME);
	highscoreButton.setX(GAME_WIDTH / 3);
	highscoreButton.setY(GAME_HEIGHT / 2.5 + BUTTON_SPACING);

	// credits
	if (!creditsButton.initialize(this, buttonsNS::WIDTH, buttonsNS::HEIGHT, buttonsNS::TEXTURE_COLS, &buttonsTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing buttons"));
	creditsButton.setFrames(buttonsNS::CREDITS_FRAME, buttonsNS::CREDITS_FRAME);
	creditsButton.setCurrentFrame(buttonsNS::CREDITS_FRAME);
	creditsButton.setX(GAME_WIDTH / 3);
	creditsButton.setY(GAME_HEIGHT / 2.5 + BUTTON_SPACING * 2);

	// elements
	// scissors
	if (!scissor1.initialize(this, scissorsNS::WIDTH, scissorsNS::HEIGHT, scissorsNS::TEXTURE_COLS, &mainTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing scissors"));
	scissor1.setFrames(scissorsNS::SCISSORS_START_FRAME, scissorsNS::SCISSORS_END_FRAME);
	scissor1.setCurrentFrame(scissorsNS::SCISSORS_START_FRAME);
	scissor1.setX(50);
	scissor1.setY(100);
	scissor1.setVisible(0);
	//asteroids
	for (int i = 0; i < MAX_ASTEROIDS_NO; i++)
	{
		//if (!asteroidList[i].initialize(this, asteroidNS::WIDTH, asteroidNS::HEIGHT, asteroidNS::TEXTURE_COLS, &asteroidTexture))
		//throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing asteroid"));
		//asteroidList[i].setFrames(asteroidNS::ASTEROID_START_FRAME, asteroidNS::ASTEROID_END_FRAME);
		//asteroidList[i].setCurrentFrame(asteroidNS::ASTEROID_START_FRAME);
		//asteroidList[i].setX(GAME_WIDTH/4);
		//asteroidList[i].setY(GAME_HEIGHT/4 * (i+1));

	}

	return;
}

//=============================================================================
// Update all game items
//=============================================================================
void Papercat::update()
{

	//ship.update(frameTime);

	for (int i = 0; i < MAX_ASTEROIDS_NO; i++)
	{
		//asteroidList[i].update(frameTime);
	}

}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void Papercat::ai()
{}

//=============================================================================
// Handle collisions
//=============================================================================
void Papercat::collisions()
{
	VECTOR2 collisionVector;



}

//=============================================================================
// Render game items
//=============================================================================
void Papercat::render()
{
	graphics->spriteBegin();                // begin drawing sprites
	if (gameStart == 0)
	{
		menu.draw();							// add the menu to the scene
		startButton.draw();						// add start button to menu scene
		highscoreButton.draw();					// add highscore button to menu scene
		creditsButton.draw();					// add credits button to menu scene
		//nebula.draw();                          // add the orion nebula to the scene
		//ship.draw();                           // add the spaceship to the scene

		for (int i = 0; i < MAX_ASTEROIDS_NO; i++)//add the asteroids to the scene
		{
			//asteroidList[i].draw();
		}
		if (input->wasKeyPressed(VK_RETURN))
		{
			gameStart = 1;
		}
	}
	else if (gameStart == 1)
	{
		backgroundStage.draw();
	}
	graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Papercat::releaseAll()
{
	menuTexture.onLostDevice();
	buttonsTexture.onLostDevice();
	backgroundStageTexture.onLostDevice();
	mainTexture.onLostDevice();
	//nebulaTexture.onLostDevice();
	//shipTexture.onLostDevice();
	//asteroidTexture.onLostDevice();

	Game::releaseAll();
	return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void Papercat::resetAll()
{
	menuTexture.onResetDevice();
	buttonsTexture.onResetDevice();
	backgroundStageTexture.onResetDevice();
	mainTexture.onResetDevice();
	//nebulaTexture.onResetDevice();
	//shipTexture.onResetDevice();
	//asteroidTexture.onResetDevice();

	Game::resetAll();
	return;
}
