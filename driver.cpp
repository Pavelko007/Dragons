/*
 * File Name:    driver.cpp
 *
 * Author:        Your Name
 * Creation Date: Wednesday, August 27 2014, 19:52
 * Last Modified: Thursday, September 04 2014, 19:00
 *
 * File Description:
 *
 */
#include "driver.h"

/*
 * This the main function. It is fully implemented
 *
 */
int main()
{
	initialize();

	Dragon dragons[NUMBER_OF_DRAGONS];

	int currDragonNumbers = loadFile(dragons);

	run(dragons, currDragonNumbers);

	cout << "That's all folks" << endl;
}

/*
 * This function takes the array of Dragons as a parameter and asks
 * the user for the name of the text file to open.
 *
 * If the file exists, then it is opened and the Dragon records in the
 * file are read into the array of Dragon objects.
 *
 * The return value is the number of Dragon records that were read from the
 * file. This number is both the stopping number when searching/printing
 * the array and the index of the next free space in the array
 *
 * If the file cannot be opened then this function returns 0.
 * It does NOT exit.
 *
 * NOTE: use the .c_str( ) function of the string class to convert
 *       a string object to a cstring (array of char)
 *
 */
int loadFile(Dragon * dragons)
{
	int index = 0;

	//TODO
	cout << "Enter filename >> ";
	string filename;
	getline(cin, filename);
	ifstream inputFile(filename.c_str(), ifstream::binary);

	if (inputFile.fail())
	{
		cout << "Can't open file" << endl;
		return 0;
	}	

	while (index < NUMBER_OF_DRAGONS && inputFile.good())
	{
		inputFile >> dragons[index];
		index++;
	}

	inputFile.close();
	return index;
}

/*
 * This function is fully implemented
 *
 */
void run(Dragon * dragons, int & currentDragonNumbers)
{
	int choice = -1;
	PernThread * pernPtr = nullptr;
	while (choice != QUIT)
	{
		displayMainMenu();
		cout << "Enter choice >> ";
		cin >> choice;
		cin.ignore(10000, '\n');
		process(dragons, currentDragonNumbers, choice, pernPtr);
	}
}

/*
 * This function is fully implemented
 *
 */
void displayMainMenu()
{
	cout << "\nDragon Menu " << endl;
	cout << ADD << ". Add Dragon" << endl;
	cout << DETECT << ". Locate new thread" << endl;
	cout << SELECT_ACTION << ". Select action" << endl;
	cout << DISPLAY << ". Display current situation" << endl;
	cout << QUIT << ". Quit" << endl;
}

/*
 * This function is fully implemented
 *
 * The functions that are called need to be implemented to actually
 * do something
 *
 */
void process(Dragon * dragons, int & currentDragonNumbers, int choice,
	PernThread *& pernPtr)
{
	switch (choice)
	{
	case ADD:
		addDragon(dragons, currentDragonNumbers);
		break;

	case DETECT:
		makeThread(pernPtr);
		break;
	case SELECT_ACTION:
		action(dragons, currentDragonNumbers, pernPtr);
		break;

	case DISPLAY:
		showAll(dragons, currentDragonNumbers, pernPtr);
		break;

	case QUIT:
		// just trap this choice so that it does not show as an error
		break;

	default:
		cout << choice << " is not a valid option" << endl;
		break;
	}
}

/*
 * This function uses the overloaded istream operator written in the
 * Dragon class to add another Dragon to the array.
 *
 * This only works if the array is not full, in which case a message
 * should be printed to the screen and function just returns
 *
 */
void addDragon(Dragon * dragons, int & currentDragonNumbers)
{
	if (currentDragonNumbers == NUMBER_OF_DRAGONS)
	{
		cout << "You can't add more dragons" << endl;
		return;
	}
	cin >> dragons[currentDragonNumbers];
	currentDragonNumbers++;
	//TODO
}

/*
 * This function is used by the action function to return the
 * index of a Dragon. The user is asked to enter the name of a Dragon
 * and this function then searches the array for the Dragon with that
 * name.
 *
 * If the Dragon with that name is not found then -1 is returned
 *
 */
int selectDragon(const Dragon * dragons, int currentDragonNumbers)
{
	int index = -1;

	//TODO
	string dragonName;
	cout << "Enter Dragon Name >> ";
	cin >> dragonName;
	for (int i = 0; i < currentDragonNumbers; i++)
	{
		if (dragons[i].getDragonName() == dragonName)
		{
			return i;
		}
	}

	return index;
}

void deleteThread(PernThread *& ptPtr)
{
	delete ptPtr;
	ptPtr = nullptr;
}

/*
 * This function processes the action for a Dragon
 * first the function asks the user to enter the name of a Dragon.
 *
 * This name, along with the Dragon array is passed to the selectDragon
 * function. If the index returned from the selectDragon function is not
 * -1, then we have the index number in the array of the requested Dragon.
 *
 *  The user is then asked to enter a direction
 *
 *  left, right, up or down
 *
 *  The position of the selected Dragon is updated, using the
 *  appropriate function in the util.cpp file and the set function in the
 *  Dragon class.
 *
 *  After the Dragon position is updated, this function then checks
 *  whether the Dragon is close enough to destroy the PernThread object,
 *  using the flameThread function that you have implemented in the
 *  util.cpp file.
 *
 *  If the PernThread is destroyed, then the PernThread object is deleted
 *  (remembering to set the ptPtr to nullptr)
 *  and an appropriate congratulatory message is displayed to the screen.
 *
 *  If the PernThread is not destroyed, then the PernThread object has its
 *  position updated, again using the appropriate function in the util.cpp
 *  file.
 *
 *  After this update, this function checks whether or not the Y position
 *  of the PernThread object is 0 or not.
 *
 *  If the Y position is 0 then the PernThread object has reached the
 *  ground. An appropriate warning message should be displayed to the
 *  screen, the PernThread object is deleted again remembering to set
 *  ptPtr ot nullptr.
 *
 */
void action(Dragon * dragons, int currentDragonNumbers, PernThread *& ptPtr)
{
	cout << "First select a Dragon" << endl;
	int index = selectDragon(dragons, currentDragonNumbers);
	if (-1 == index)
	{
		cout << "Dragon isn't exist" << endl;
		return;
	}
	
	string direction;
	
	cin.get();
	while (true)
	{
		cout << "Enter direction (left, right, up, down) >> ";
		getline(cin, direction);
		if (direction == "left")
		{
			dragons[index].setNewPosX(dragonNewXPos(dragons[index], false));
		}
		else if (direction == "right")
		{
			dragons[index].setNewPosX(dragonNewXPos(dragons[index], true));
		}
		else if (direction == "up")
		{
			dragons[index].setNewPosY(dragonNewYPos(dragons[index], true));
		}
		else if (direction == "down")
		{
			dragons[index].setNewPosY(dragonNewYPos(dragons[index], false));
		}
		else
		{
			cout << "Invalid input" << endl;
			continue;
		}

		break;
	}

	if (nullptr == ptPtr)
		return;

	if (flameThread(dragons[index], ptPtr))
	{
		deleteThread(ptPtr);
		cout << "Congratulations Rider " << dragons[index].getRiderName()
			<< " and Dragon " << dragons[index].getDragonName() << "!!!!!"
			<< "You have successfully destroyed this Thread" << endl
			<< "More thread is on the way, stay alert!!" << endl;
	}
	else
	{
		threadNewPos(ptPtr);
		if (ptPtr->getCurrentYPos() == 0)
		{
			deleteThread(ptPtr);
			cout << "Try harder next time riders!!!" << endl
				<< "You must not let Thread reach the ground!" << endl;
		}

	}

	//TODO
}

/*
 * This function displays to the screen all the details of the
 * PernThread object, or an appropriate message if there is no
 * PernThread object.
 *
 * Then the function displays all the details of the Dragons in the
 * array, BUT ONLY THE NON-DEFAULT Dragons
 *
 */
void showAll(const Dragon * dragons, int currentDragonNumbers,
	const PernThread * ptPtr)
{
	//TODO
	cout << endl;
	if (nullptr == ptPtr)
	{
		cout << "The sky is clear of Thread riders" << endl
			<< "but stay alert!!";
	}
	else
	{
		cout << PernThread::getThread();
	}
	cout << endl;
	for (int i = 0; i < currentDragonNumbers; i++)
	{
		cout << dragons[i];
	}
}

/*
 * This function is fully implelmented.
 * This calls the public getThread( ) function of the PernThread class.
 * This returns the address of the one PernThread object, creating the
 * object if it does not exist.
 *
 * As in the action( ) function, be very careful to set this pointer
 * to nullptr when you delete the pointer when the PernThread object
 * either hits the ground or is destroyed by a Dragon
 *
 */
void makeThread(PernThread *& ptPtr)
{
	ptPtr = PernThread::getThread();
}
