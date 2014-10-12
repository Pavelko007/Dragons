/*
 * File Name:    dragon.h
 *
 * Author:        Your Name
 * Creation Date: Wednesday, August 27 2014, 19:42 
 * Last Modified: Thursday, September 04 2014, 18:52
 * 
 * File Description:
 *
 */
#ifndef DRAGON_H
#define DRAGON_H

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

#include <fstream>
using std::ifstream;

class Dragon
{
public:

	//TODO
	Dragon();	
	string getDragonName() const;
	string getRiderName()const;

	ifstream& operator>>(ifstream& ifs);
	istream & operator>>(std::istream &is);
	friend ostream& operator<<(ostream& os, const Dragon dragon);
private:

	//TODO
	string name;
	string colour;
	string rider;
	int wingspan;
	int posX;
	int posY;
	void setInitialPos();
};

ifstream& operator>> (ifstream& ifs, Dragon& dragon);
istream& operator>> (istream& is, Dragon& dragon);

#endif
