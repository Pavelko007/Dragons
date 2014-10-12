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

istream& operator>> (istream& is, Dragon& dragon)
{
	return dragon >> is;
}

istream & Dragon::operator>>(std::istream &is)
{
	//TODO
	cout << "Enter Dragon name >> ";
	is >> name;
	cout << "Enter Dragon rider name >> ";
	is >> rider;
	cout << "Enter Dragon colour >> ";
	is >> colour;
	cout << "Enter wingspan >> ";
	is >> wingspan;

	setInitialPos();

	return is;
}

void Dragon::setInitialPos()
{
	posX = initialDragonXPos();
	posY = initialDragonYPos();
}

string Dragon::getDragonName() const
{
	return name;
}

string Dragon::getRiderName()const
{
	return rider;
}

int Dragon::getCurrentXPos() const
{
	return posX;
}

int Dragon::getCurrentYPos() const
{
	return posY;
}

ostream& operator << (ostream& os, const Dragon dragon)
{
	//TODO
	os << "Dragon" << endl
		<< "name: " << dragon.name
		<< " rider: " << dragon.rider
		<< " colour: " << dragon.colour
		<< " wingspan: " << dragon.wingspan << endl
		<< "is at position X = " << dragon.posX << " Y = " << dragon.posY << endl;

	return os;
}