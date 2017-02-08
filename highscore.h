
//  Module:             Gameplay Programming
//  Assignment2:		Paper cat
//  Student Name:       Ngm Hui Min, Lois	| Jessica Tan Hwee Ching	| Pang Jin Xiang
//  Student Number:     S10158786C			| S10156827G				| S10157119D

#ifndef _HIGHSCORE_H_
#define _HIGHSCORE_H_

#include "image.h"
#include "input.h"
#include "game.h"
#include "textDX.h"
#include <fstream>
#include <string>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

class Highscore
{
private:
	bool displaying;
	string *scoreName = new string[numOfTopScore];
	TextureManager highscore2Texture;
	Image backgroundHighscore2;
	TextDX* dxFontForScore;
	int highScore[numOfTopScore];
	int currentNumberOfHighScorers=0;
public:
	Highscore();
	virtual void draw();
	virtual void initialize(Graphics *graphics);
	void getScores();
	void setScores(int playerScore, string playerName);
	void display();
	void disableDisplay();
	void setDisplayStatus(bool ifDisplaying);
	bool getDisplayStatus();
	void recordingScore(int score, string name);
	bool checkingScore(int score);
};
#endif



