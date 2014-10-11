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

//TODO

Dragon::Dragon()
{
	name = "Not set";
	rider = "Not set";
	colour = "unknown";
	wingspan = -1;
	posX = posY = -1;
}

ifstream& operator>> (ifstream& ifs, Dragon& dragon)
{		
	return dragon >> ifs;
}

ifstream& Dragon::operator>> (ifstream& ifs)
{
	ifs >> name >> rider >> colour >> wingspan;
	setInitialPos();

	return ifs;
}

void Dragon::setInitialPos()
{
	posX = initialDragonXPos();
	posY = initialDragonYPos();
}

ostream& operator << (ostream& os, const Dragon dragon)
{
	os << "Dragon" << endl
		<< "name: " << dragon.name
		<< " rider: " << dragon.rider
		<< " colour: " << dragon.colour
		<< " wingspan: " << dragon.wingspan << endl
		<< "is at position X = " << dragon.posX << " Y = " << dragon.posY << endl;

	return os;
}