
#ifndef _PAPERCAT_H             // Prevent multiple definitions if this 
#define _PAPERCAT_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "game.h"
#include "textureManager.h"
#include "image.h"
#include "ship.h"
#include "asteroid.h"
#include "buttons.h"
#include "scissors.h"
#include "mainChar.h"
#include "blackhole.h"
#include <cmath>
#include "draw.h"
#include "Minion.h"
#include "items.h"
#include "textDX.h"


//=============================================================================
// This class is the core of the game
//=============================================================================
class Papercat : public Game
{
private:
	//constants
	static const int MAX_ASTEROIDS_NO = 3;
	static const int BUTTON_SPACING = 120;
	static const int SCISSORS_AMT = 3;
	// game items
	TextureManager nebulaTexture;   // nebula texture
	TextureManager asteroidTexture; //asteroid texture
	TextureManager shipTexture;    // game texture
	TextureManager	menuTexture;		// menu texture
	TextureManager	mainTexture;
	TextureManager	itemTexture;

	//TextureManager		startButtonTexture;		// start button texture
	//TextureManager		highscoreButtonTexture;	// highscore button texture
	//TextureManager		creditsButtonTexture;	// credits button texture
	TextureManager		backgroundStageTexture;	// background for stages
	TextureManager		buttonsTexture;
	Buttons startButton;
	Buttons highscoreButton;
	Buttons creditsButton;
	Scissors scissor1;
	MainChar cat;
	Blackhole blackhole;
	Items items[BUFF_NUM];
	//Image	scissorsArray[SCISSORS_AMT];
	Ship    ship;           // spaceships
	//Image	startButton;		// start button
	//Image	highscoreButton;	// highscore button
	//Image	creditsButton;		// credits button
	Image   nebula;         // backdrop image
	Image	menu;			// menu backdrop image
	//Image	buttons;		// buttons on menu image
	Image	backgroundStage;	// stage backdrop image
	Asteroid asteroidList[MAX_ASTEROIDS_NO]; //asteroids
	int gameStart = 0;		// for game status
	CDraw drawing;			// for platform in stages
	Minion* minion = new Minion();	// minions
	TextDX *mainFont;		// fonts for e.g. highscore/points 
	int playerScore;		// player's score in the game
	int arrayOfNumX = GAME_WIDTH / (itemsNS::WIDTH + 0.2f) * items[0].getScale();
	float arrayOfPosition[10];

public:
	// Constructor
	Papercat();

	// Destructor
	virtual ~Papercat();

	// Initialize the game
	void initialize(HWND hwnd);
	void update();      // must override pure virtual from Game
	void ai();          // "
	void collisions();  // "
	void render();      // "
	void releaseAll();
	void resetAll();
	void gravity();
	void setYvalue(int randLineNum, int arrayNumOfX, float xValue);

};

#endif
