#if !defined STATISTICS_H
#define STATISTICS_H

// Reads the data from teh files and size
int* readData (const char* filename, int& size);

// Finds the Median of the Given numbers in the text file
float findMean (int* numbers, int size);

// Finds the Median  of the Given numbers in the text file 
float findMedian (int* numbers, int size);

// Finds the Mode of the Given numbers int the text file 
int findMode (int* numbers, int size);

// Displays the information to the user
void displayInfo (float mean, float median, int mode);

#endif 