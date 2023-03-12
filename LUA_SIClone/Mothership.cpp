/*
Space invaders game
Author:		Philip Alassad
Filename:	Mothership.cpp
Date:		14/10/2015
Last Updated:	25/10/2015

Description: Source file for Mothership class
*/

#include "Mothership.h"
#include <stdio.h>

//Constructor
Mothership::Mothership(float xPos, float yPos, string filename)
	:Ship(xPos, yPos, filename)
{	
	m_lives = 10;
	m_xpos = xPos;
	m_ypos = yPos;
}

Mothership::~Mothership()
{

}

//Methods
void Mothership::left()
{
}

void Mothership::right()
{
	m_xpos = m_xpos + 3 ;
}

void Mothership::reduceLives()
{
	m_lives --;
}

int Mothership::getLives()
{
	return m_lives;
}
