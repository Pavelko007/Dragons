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
	while (true)
	{
		cout << "Enter Dragon Name >> ";
		getline(cin, name);
		if (string::npos != name.find(' '))
		{
			cout << "Dragon name is only ever one word" << endl;
		}
		else
		{
			break;
		}
	}

	while (true)
	{
		cout << "Enter Dragon rider name >> ";
		getline(cin, rider);
		if (string::npos != rider.find(' '))
		{
			cout << "Dragon rider name is only ever one word" << endl;
		}
		else
		{
			break;
		}
	}

	while (true)
	{
		cout << "Enter Dragon colour >> ";
		getline(cin, colour);
		if (string::npos != colour.find(' '))
		{
			cout << "Dragon colour is only ever one word" << endl;
		}
		else
		{
			break;
		}
	}

	cout << "Enter wingspan >> ";
	is >> wingspan;

	while (is.fail() || wingspan < 0){
		is.clear();
		is.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Bad entry. Enter wingspan >> ";
		is >> wingspan;
	}
	is.ignore(numeric_limits<streamsize>::max(), '\n');
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

int Dragon::getCurrentPosX() const
{
	return posX;
}

int Dragon::getCurrentPosY() const
{
	return posY;
}

int Dragon::getWingspan() const
{
	return wingspan;
}

void Dragon::setNewPosX(int newPosX)
{
	posX = newPosX;
}

void Dragon::setNewPosY(int newPosY)
{
	posY = newPosY;
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