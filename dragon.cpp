/*
 * File Name:    dragon.cpp
 *
 * Author:        Your Name
 * Creation Date: Wednesday, August 27 2014, 19:52 
 * Last Modified: Thursday, September 04 2014, 18:52
 * 
 * File Description:
 *
 */
#include "dragon.h"
#include "util.h"

/* *** to do *** */

Dragon::Dragon()
{
	name = "Not set";
	rider = "Not set";
	colour = "unknown";
	wingspan = -1;
	posX = posY = -1;
}

ifstream& operator>> (ifstream& is, Dragon& dragon)
{
	is >> dragon.name >> dragon.rider >> dragon.colour >> dragon.wingspan;
	return is;
}