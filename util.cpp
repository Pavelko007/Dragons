/*
 * File Name:    util.cpp
 *
 * Author:        Your Name
 * Creation Date: Wednesday, August 27 2014, 20:24
 * Last Modified: Thursday, September 04 2014, 19:05
 *
 * File Description:
 *
 * For CSE1CPP Assignment 1 2014
 *
 */
#include "util.h"

/* This function calculates the new X pos for a Dragon
 * based on both the wingspan of the Dragon and
 * whether the Dragon is turning left or right
 *
 * right = true, left = false
 *
 * The new position takes into account the current position
 * and applies the formula, based on wingspan, to
 * calculate the new position.
 *
 * NOTE: if the new position would take the Dragon outside
 *       the edges of the area, then the new figure is set
 *       to the edge, either MAX_DRAGON_XPOS or MIN_DRAGON_XPOS
 *
 * The formula for calculating the newX is
 *     newX = oldX +/- (( 100 / wingspan ) * 50 ) (+/- means plus or minus)
 *
 * If the X position is being changed (left or right) then the Y position
 * stays the same.
 *
 * We pass a Dragon object into this function. For this function to
 * work the Dragon object will need a way of getting the value of the
 * wingspan, meaning that the Dragon class will need a public
 * get function that returns the value of the wingspan.
 *
 * As well, the Dragon object needs a public get function to give
 * this function the value of the old X position.
 *
 * This function returns the newX position.
 *
 * This function does NOT set the new value in the Dragon object, it
 * just returns the new value.
 *
 * To set the new X position in the Dragon object, the Dragon class
 * will need a set method for updating the X position. The figure
 * returned by this function completely replaces the old X position
 * figure, it does not add or subtract with the old figure, it overwrites
 * the old figure.
 *
 * Even though all the values in the formula are ints, we still want to
 * get an answer that is a double, then cast that answer back to an int.
 *
 */

int dragonNewXPos(const Dragon& d, bool direction)
{
	int newX = 0;

	int posDiff = (int)((100 / (double)d.getWingspan()) * 50);
	//TODO
	if (direction)
	{
		newX = d.getCurrentPosX() + posDiff;
	}
	else
	{
		newX = d.getCurrentPosX() - posDiff;
	}

	if (newX > MAX_DRAGON_XPOS)
	{
		newX = MAX_DRAGON_XPOS;
	}
	if (newX < MIN_DRAGON_XPOS)
	{
		newX = MIN_DRAGON_XPOS;
	}

	return newX;
}

/* This function calculates the new Y pos for a Dragon
 * based on both the wingspan of the Dragon and
 * whether the Dragon is going up or down
 *
 * up = true, down = false
 *
 * The new position takes into account the current position
 * and applies the formula, based on wingspan, to
 * calculate the new position.
 *
 * NOTE: if the new position would take the Dragon outside
 *       the edges of the area, then the new figure is set
 *       to the edge, either MAX_DRAGON_YPOS or 0, as Dragons
 *       cannot operate effectively above MAX_DRAGON_YPOS
 *       and Dragons never crash, so if the newY position is
 *       less than 0 the Dragon would land on the ground
 *       (at Y pos = 0 )
 *
 * The formula for calculating the newY is
 *     newY = oldY +/- (wingspan  * 5 ) (+/- means plus or minus)
 *
 * If the Y position is being changed (up or down) then the X position
 * stays the same.
 *
 * After calculating the newY this function must check that the newY
 * is not above the max Y (height) for a Dragon
 *
 * If the newY is above this max then the newY is set to the max Y
 * for a Dragon.
 *
 * Equally, if the newY is < 0 then the newY is set to 0
 * as Dragons never crash, at Y = 0, they land on the ground
 *
 * As with the function above that calculates the new X position,
 * this function calcualates the new Y (vertical) position and
 * returns that figure.
 *
 * Being based on the wingspan, the Dragon object needs a get function
 * to supply the value of the wingspan to this function.
 *
 * As well, the Dragon object needs a public get function to give
 * this function the value of the old Y position.
 *
 * As with the function above, the figure returned  by this function
 * completely replaces the old Y position figure so the Dragon
 * class needs a set method to update its Y position.
 *
 * Unlike the function above for the X position everything in the
 * formula is fine as ints (no division) so there is no need for any
 * casting.
 *
 */
int dragonNewYPos(const Dragon & d, bool direction)
{
	int newY = 0;

	//TODO
	int posDiff = d.getWingspan() * 5;

	if (direction)
	{
		newY = d.getCurrentPosY() + posDiff;
	}
	else
	{
		newY = d.getCurrentPosY() - posDiff;
	}

	if (newY > MAX_DRAGON_YPOS)
	{
		newY = MAX_DRAGON_YPOS;
	}
	if (newY < 0)
	{
		newY = 0;
	}

	return newY;	 
}

// Thread always moves 200 units, but it can be down, left or right
// determine this randomly.
/*
 * This function is fully implemented
 *
 */
void  threadNewPos(PernThread*& pt)
{
	int dir = rand() % 15;
	int newPos = 0;
	switch (dir)
	{
	case 0: // down
	case 1:
	case 4:
	case 8:
	case 11:
	case 12:
	case 14:
		newPos = pt->getCurrentYPos() - 200;
		if (newPos < 0)
		{
			newPos = 0;
		}
		pt->setNewYPos(newPos);

		break;

	case 2: // left
	case 5:
	case 9:
	case 13:
		newPos = pt->getCurrentXPos() - 200;
		if (newPos < MIN_THREAD_XPOS)
		{
			newPos = MIN_THREAD_XPOS;
		}
		pt->setNewXPos(newPos);

		break;

	case 3: // right
	case 6:
	case 7:
	case 10:
		newPos = pt->getCurrentXPos() + 200;
		if (newPos > MAX_THREAD_XPOS)
		{
			newPos = MAX_THREAD_XPOS;
		}
		pt->setNewXPos(newPos);

		break;

	default:

		cout << "\nSerious system error!! " <<
			"\nInvalid Thread direction generated" << endl;
		break;
	}
}



/*
 * Thread is destroyed if a Dragon is within 100 units of Thread
 *
 * The formula for calculating the distance is
 *
 * distance = square_root( ( x1 - x2)^2 + ( y1 - y2 )^2 )
 *
 * where x1 and y1 are the x and y positions of the Dragon and
 * x2 and y2 are the x and y positions of the Thread object
 *
 * This function returns true or false depending on whether or not
 * the Thread object has been destroyed.
 *
 * The PernThread class has already been implelemented so it has
 * get functions to return the value of the x and y positin of the
 * Thread object. The Dragon also needs get functions to return
 * the value of its X and Y position
 *
 */
bool flameThread(const Dragon & d, const PernThread * pt)
{
	//TODO

	if (distance(d, pt) <= 100)
		return true;
	else
		return false;
}

/* *************************************************************
 *      All the functions below are fully implelmented         *
 *                                                             *
 * *************************************************************
 */

/*
 * This function is called when we create a Dragon object with
 * keyboard input, to generate the initial X position, which is
 * then set in the Dragon object
 *
 */
int initialDragonXPos()
{
	int pos = rand() % (MAX_DRAGON_XPOS * 2);
	pos = pos + MIN_DRAGON_XPOS;

	return pos;
}

/*
 * This function is called when we create a Dragon object with
 * keyboard input, to generate the initial Y position, which is
 * then set in the Dragon object
 *
 */
int initialDragonYPos()
{
	int pos = rand() % (MAX_DRAGON_YPOS - MIN_DRAGON_YPOS);
	pos += MIN_DRAGON_YPOS;

	return pos;
}

/*
 * This function is called when we create a PernThread object
 * to generate the initial X position, which is then set in the
 * PernThread object
 *
 */
int initialThreadXPos()
{
	int pos = rand() % (MAX_THREAD_XPOS * 2);
	pos = pos + MIN_THREAD_XPOS;

	return pos;
}

/*
 * This function is called when we create a PernThread object
 * to generate the initial Y position, which is then set in the
 * PernThread object
 *
 */
int initialThreadYPos()
{
	int pos = rand() % (MAX_THREAD_YPOS - MIN_THREAD_YPOS);
	pos += MIN_THREAD_YPOS;

	return pos;
}

/*
 * This function is called from main( ) in the driver program to
 * initialize the random number generator
 *
 * Only call this function once (alredy done for you)
 *
 */
void initialize()
{
	// seed the random generator just once
	srand((unsigned int)time(NULL));
}

int distance(const Dragon &d, const PernThread * pt)
{
	double xDistance = d.getCurrentPosX() - pt->getCurrentXPos();
	double yDistance = d.getCurrentPosX() - pt->getCurrentYPos();
	return (int)sqrt(pow(xDistance, 2) + pow(yDistance, 2));
}
