/* 
	Author : Jordan Seth Myers
	Date : 11 - 1 - 18
	Purpose: Mean, Median, Mode
	
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Statistics.h"					// use correct include prosessors both . h 
#include "BasicSort.h"

using namespace std;

int main()
{
	const int arraySize = 95;
	int *nums = new int[arraySize];					
	
	char *numFile = new char[25];
	
	cout << "Enter the file name: " << endl; 
	
	cin >> numFile; 									// cin the file from the user 
	
	int newSize;
	
	nums = readData(numFile, newSize);
	
	insertionSort(nums,newSize);						// Calling sort function from BasicSort.cpp 
	float mean = findMean(nums,newSize);
	float median = findMedian(nums,newSize);
	int mode = findMode(nums,newSize);						// Calling all functions from the Stats1.cpp file with parameters 
	
	displayInfo(mean,median,mode);
	
	return 0;
}