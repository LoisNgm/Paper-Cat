
//  Module:             Gameplay Programming
//  Assignment2:		Paper cat the hero
//  Student Name:       Ngm Hui Min, Lois	| Jessica Tan Hwee Ching	| Pang Jin Xiang
//  Student Number:     S10158786C			| S10156827G				| S10157119D

#ifndef _PAPERCAT_H             // Prevent multiple definitions if this 
#define _PAPERCAT_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "game.h"
#include "star.h"
#include "textureManager.h"
#include "image.h"
#include "buttons.h"
#include "scissors.h"
#include "mainChar.h"
#include "blackhole.h"
#include <cmath>
#include "draw.h"
#include "Minion.h"
#include "items.h"
#include "textDX.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include "highscore.h"

using namespace std;

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
	TextureManager	menuTexture;		// menu texture
	TextureManager	mainTexture;
	TextureManager	itemTexture;
	TextureManager		backgroundStageTexture;	// background for stages
	TextureManager		highscoreTexture;	// background for highscore
	TextureManager		creditTexture;	// background for credit
	TextureManager		buttonsTexture;
	TextureManager      backgroundStage2Texture;
	TextureManager		tutorialTexture;
	TextureManager		tutorial2Texture;
	TextureManager		rainbowTexture;
	Buttons startButton;
	Buttons highscoreButton;
	Buttons creditsButton;
	Scissors scissor1;
	Star	stars[NUMBER_OF_STARS];
	MainChar cat;
	Blackhole blackhole;
	string playerName = "";
	Items items[BUFF_NUM];
	Items coins[NUMBER_OF_COINS];
	//Image	scissorsArray[SCISSORS_AMT];
	Image   nebula;         // backdrop image
	Image	menu;			// menu backdrop image
	Image	backgroundStage;	// stage backdrop image
	Image	backgroundStage2;	// stage 2 backdrop image
	Image	backgroundHighscore;	// highscore backdrop image
	Image	rainbow;
	Highscore* highscoreLogging;
	Image	backgroundCredit;	// Credit backdrop image
	Image	backgroundTutorial;
	Image	backgroundTutorial2;
	int gameStart = 0;		// for game status
	CDraw drawing;			// for platform in stages
	Minion* minion = new Minion();	// minions
	TextDX *mainFont;		// fonts for e.g. highscore/points 
	TextDX *pausedFont;
	int playerScore;		// player's score in the game
	float arrayOfPosition[arrayOfNumX];
	int numberOfCoinsCollected = 0;
	int numberOfStarsCollected = 0;
	TextureManager doorTexture;
	Image doorFinal;
	Image doorBonus;
	float flashTimer = 0;


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
	void setArray(float arrayOfPosition[arrayOfNumX]);
	void setYvalue(int lineNum, int position, int type);
	bool collisionWithItem(Items item1, Items item2);
	void playBGM();
	void characterPlatformCheckingForStage1();
	void characterPlatformCheckingForBonusStage();
	int SetRandomNum(int lineNum);
	bool checkCollisionforStage2();
	void checkScissorCollision();
	void checkCoinCollision();
	void checkBuffCollision();
	void checkFinalDoor();
	void checkBonusDoor();
	void setItemsInPosition(Entity* item);
	void checkCoinCollisionWithCatAndBlackhole();
	void resetForStage2();
	void initalizePosition();
};

#endif
