/*
Space invaders game
Author:		Philip Alassad
Filename:	laser.h
Date:		23/10/2015
Last Updated:	__/__/____

Description: Header file for laser class
*/

#pragma once

#include <string>
#include "Input.h"

class laser 
{
protected:
	//members
	float m_xpos;
	float m_ypos;
	ALLEGRO_BITMAP* m_laser = NULL;

public:
	//constructor
	laser(int xpos, int ypos, string filename);
	~laser();

	//methods
	void setX(int xVal);
	void setY(int yVal);
	int getX();
	int getY();
	void up();
	void down();
	void draw(void);

};