/*
Space invaders game
Author:		Philip Alassad
Filename:	Ufo.cpp
Date:		14/10/2015
Last Updated:	__/__/____

Description: Source file for Ufo class
*/

#include "Ufo.h"
#include <stdio.h>

//Constructor
Ufo::Ufo( float xPos, float yPos, string filename)
	:Ship(xPos, yPos, filename)
{
	m_xpos = xPos;
	m_ypos = yPos;
}

Ufo::~Ufo()
{
	
}

//Methods
void Ufo::right(int counter, int level)
{
	m_direction_flag = true;
	m_current_frame = m_current_frame + 0.1f;
	m_xpos = m_xpos+(0.5+(counter/17)+(level/40));
	if (m_current_frame > 1.9)
		m_current_frame = 0;
}

void Ufo::left(int counter, int level)
{
	m_direction_flag = false;
	m_current_frame = m_current_frame + 0.1f;
	m_xpos = m_xpos - (0.5 + (counter / 17)+(level/40));
	if (m_current_frame > 1.9)
		m_current_frame = 0;
}


