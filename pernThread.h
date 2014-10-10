/*
 * File Name:    pernThread.h
 *
 * Author:        Your Name
 * Creation Date: Monday, September 01 2014, 15:41 
 * Last Modified: Thursday, September 04 2014, 19:02
 * 
 * File Description:
 *
 * There can only be one PernThread object in existence at a time
 * Hence the constructor is private and is called by the public
 * getPernThread( ) function which returns a (the only) pointer to a 
 * newly created PernThread object, if the instance flag is false,
 * otherwise it returns the existing pointer.
 *
 * The pointer is static, as is the instance flag. Being static
 * there is only one of each regardless of the number of objects.
 *
 * This is known as the Singleton pattern.
 *
 * Note that the constructor is private. Access to this class is
 * through the public getThread( ) function
 *
 */
#ifndef PERNTHREAD_H
#define PERNTHREAD_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

#include <string>
using std::string;

#include <fstream>
using std::ofstream;
using std::ifstream;


class PernThread
{
public:

    // we are always going to be using a pointer to the PernThread object
    // so just pass in that pointer.
    friend ostream& operator << ( ostream& os, const PernThread * pt );
    /*
     * There is no keybaord input to create a PernThread
     * the x and y positions are set at random, using the functions
     * in util.cpp
     * and as the PernThread has just been "created", it has not been
     * destroyed, so it is still viable
     */
    // friend istream& operator >> ( istream& is, PernThread & pt );


    int getCurrentXPos( ) const { return ptXPos; }
    int getCurrentYPos( ) const { return ptYPos; }
    void setNewXPos( int newX ) { ptXPos = newX; }
    void setNewYPos( int newY ) { ptYPos = newY; }
    // This function must be static because it operates on a static
    // variable.
    static PernThread * getThread( );
    ~PernThread( );

private:
    PernThread( ) = default;
    static PernThread * single;
    static bool instance;
    static int ptXPos;
    static int ptYPos;
};

#endif
