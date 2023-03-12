/*
Space invaders game
Author:		Philip Alassad
Filename:	Player.h
Date:		14/10/2015
Last Updated:	__/__/____

Description: Header file for Player class
*/

#pragma once

//includes go here
#include "Ship.h"

using namespace std;

class Player: public Ship
{
private:
	//members
	int m_lives;
	int m_score;

public:
	//constructor
	Player(float xPos, float yPos, int lives, string filename);
	~Player(void);

	//methods
	void reduceLives();
	void increaseLives();
	void setScore(int score);
	int getLives();
	int getScore();
	void kill();
	void reset_lives();
	void reset_score();
};