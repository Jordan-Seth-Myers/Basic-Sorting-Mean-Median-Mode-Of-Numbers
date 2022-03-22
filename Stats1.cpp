#include "Statistics.h"
#include "BasicSort.h"
#include <fstream>
#include <iostream>


using namespace std;

const double medAdds = .5;									
int* readData (const char* filename, int& size)						// Read the data from text file 
{
	ifstream infile;
	infile.open(filename);
	
	if(!infile)
	{
		cout << "The file you are trying to find did not appear" << endl;
		cout << "Recomplie please :) " << endl;									// If it did not find the appriate text file the output a message 
		exit(-1);
		
	}
	size = 0;
	
	static int num[95];					// settng a limit in the text file 
	
	infile.clear();				// Clear filr after use 
	
	while(!infile.eof())
	{
		infile >> num[size];
		size++;
	}
	return num;
}
float findMean (int* numbers, int size)
{	
	float mean;
	float sum = 0;
	insertionSort(numbers,size);					// Sort the text file in all function before math 
	for (int i = 1; i <= size; i++)						// Make sure you call the function from the basic sort cpp file 
	{
		sum += numbers[i];
	}
	float floatSize = static_cast <float> (size);
	mean = sum / floatSize;
	return mean;
}


float findMedian (int* numbers, int size)				// Fining the median from the givin text file from the user 
{	
	int mid;
	float average, median;
	insertionSort(numbers,size);
	mid = size / 2.0; 
	if(size / 2)
	{
		median = (numbers[mid] + numbers[mid + 1]) / 2;
	}
	else{
		median = numbers[mid + 1];
	}
	float floatSize = static_cast <float> (size);			// change the number of array to a float 
	median = median + medAdds;
	return median; 
}

int findMode (int* numbers, int size)				// Find the mode from the givin text file from user
{
	insertionSort(numbers,size);
	int number = numbers[0];
	int mode = number;
	int count = 1;
	int countMode = 1;

	for (int z = 1; z < size; z++)
	{
      if (numbers[z] == number) 
      {
         ++count;
      }
      else
      { 
            if (count > countMode) 
            {
                  countMode = count; 
                  mode = number;
            }
           count = 1; 
           number = numbers[z];
	  }
}	
	return mode;
}

void displayInfo (float mean, float median, int mode)					// Displaying the mean median and mode to the user 
{
	
	cout << "Welcome to the Statistics Program." << endl; 
	
	cout << "The mean of the data set provided is : " << mean << endl; 
	cout << "The median of the data set provided is : " << median << endl;
	cout << "The mode of the data set provided is : " << mode << endl;
	cout << "Thank you, try and have a nice day" << endl;
}