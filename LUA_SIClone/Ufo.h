/*
Space invaders game
Author:		Philip Alassad
Filename:	Ufo.h
Date:		14/10/2015
Last Updated:	__/__/____

Description: Header file for Ufo class
*/

#pragma once

//includes go here
#include "Ship.h"

using namespace std;

class Ufo : public Ship
{
public:
	//constructor
	Ufo( float xPos, float yPos, string filename);
	~Ufo(void);
	//methods
	void left(int counter, int level);
	void right(int counter,int level);
};