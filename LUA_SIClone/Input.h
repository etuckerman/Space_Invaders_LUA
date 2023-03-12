/*
Space invaders game
Author:		Philip Alassad
Filename:	Input.h
Date:		14/10/2015
Last Updated:	__/__/____

Description: Header file for Input class
*/

#pragma once

//includes go here
#include "Game.h"

//Global vars
enum KEYS_PRESSED_LIST
{
	KEY_ESCAPE, KEY_A, KEY_D, KEY_SPACE, KEY_ENTER,SIZE_OF_KEYS_PRESSED_ENUM
};

class Input /*: public Game*/
{
protected:
	//members	
	bool m_keysPressed[SIZE_OF_KEYS_PRESSED_ENUM];
	ALLEGRO_EVENT_QUEUE* m_event = NULL;
public:
	//constructor
	Input();
	~Input();

	//methods
	void update(void);
	bool key_is_pressed(KEYS_PRESSED_LIST key);	
	void set_key_to_false(KEYS_PRESSED_LIST key);
	void set_key_to_true(KEYS_PRESSED_LIST key);
	ALLEGRO_EVENT_QUEUE* Get_event();
};