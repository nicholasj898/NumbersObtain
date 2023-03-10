/*----------------------------Count.cpp----------------------------------------------------------------
|  Author: Nicholas Jones                                                                             |
|  Purpose: Sort and display the contents of the 'numbers.txt' file                                   |
|  Required Files: numbers.txt                                                                        |
|  Dependencies: Standard C++                                                                         |
|  Known Bugs: N/A                                                                                    |
|  Licensing Information: You are free to use or extend this project for educational purposes         |
------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

const int SIZE = 50;
// function prototypes 
void sortFunction(int(&nbrs)[SIZE], int idx);
void occursFunction(int(&nbrs)[SIZE], int idx);

int main() {

	ifstream dataIn;
	int lastIndex;
	int nbrArray[SIZE];
	dataIn.open("numbers.txt");
	if (!dataIn)
		cout << "Cannot Open File. \n";
	else {
		lastIndex = 0;
		while (lastIndex < SIZE && dataIn >> nbrArray[lastIndex]) {
			lastIndex++;
		}
		cout << "Array contains " << static_cast<int>(lastIndex) << " numbers. \n";
		sortFunction(nbrArray, lastIndex);
		occursFunction(nbrArray, lastIndex);
	}
	return 0;
}

void sortFunction(int(&array)[SIZE], int arrayLength) {
	//uses the binary bubble sort - reapeatedly loops through array, swaps values
	//(current index with -1 index) until there is no more to swap.
	int swap, swapCount;
	do {
		swapCount = 0;
		for (int inx = 1; inx < arrayLength; inx++) {
			if (array[inx] > array[inx - 1]) {
				swap = array[inx - 1];
				array[inx - 1] = array[inx];
				array[inx] = swap;
				swapCount++;
			}
		}
	} while (swapCount > 0);

	/* used as test to check the sorted order
	for (int inx = 0; inx < arrayLength; inx++)
	{
		cout << static_cast<int>(array[inx]) << endl;
	}*/
	return;
}

void occursFunction(int(&array)[SIZE], int arrayLength) {
	// two dimensionals [the array integer value][the frequency count]
	// the array is set to the default size, in case of all unique values (frequency of 1) 
	int occurs[SIZE][2];
	int occursCount = 0;
	
	bool found;
	//for each array element (outer loop), match against unique occurs (inner loop)
	//if already exists in the occurs array, add 1 and mark as found, 
	//else add the array value to the occurs and initialize it to 1,
	//then bump the occurs array size by 1.
	for (int arrayInx = 0; arrayInx < arrayLength; arrayInx++) {
		found = false;
		for (int occursInx = 0; occursInx < occursCount; occursInx++) {
			if (array[arrayInx] == occurs[occursInx][0]) {
				occurs[occursInx][1]++;
				found = true;
				break;
			}
		}
		if (found == false) {
			occurs[occursCount][0] = array[arrayInx];
			occurs[occursCount][1] = 1;
			occursCount++;
		}
	}

	//display the occurs array and count
	for (int inx = 0; inx < occursCount; inx++) {
		cout << static_cast<int>(occurs[inx][0]) << " | " << static_cast<int>(occurs[inx][1]) << endl;
	}
	return;
}