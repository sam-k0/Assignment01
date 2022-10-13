// Assignment01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// reads a number from stdin and returns.
double getJudgeData() {
	printf("Input a number: \n");
	int num = 0;
	if (scanf_s("%d", &num))
	{
		//printf("OK!\n");
	}
	return (double)num;
}

int getInputCleaned()
{
	double n;
	n = getJudgeData(); // get input from console

	while (true) // repeat forever
	{
		if (n > 0) // check if input is valid
		{
			// Input is valid
			return n;
		}
		else
		{
			// Input is invalid
			n = getJudgeData(); // get another number.
		}
	}
}

double findLowest(double* numbers, int n) // finds the lowest number in array
{
	int i; // for the forloop
	double lowest; // Stores the currently lowest value
	lowest = 11;   // only numbers from 1 to 10 exist, so 11 is out of bounds
	double current; // Holds the current number

	for (i = 0; i < (int)n; i++) // Loop all numbers
	{
		current = numbers[i]; // get the current

		if (current < lowest) // compare current number to lowest and assign if true
		{
			lowest = current;
		}
	}
	return lowest;
}


double findHighest(double* numbers, int n) // finds the lowest number in array
{
	int i; // for the forloop
	double highest; // Stores the currently lowest value
	highest = 0;   // only numbers from 1 to 10 exist, so 0 is always lowest
	double current; // Holds the current number

	for (i = 0; i < (int)n; i++) // Loop all numbers
	{
		current = numbers[i]; // get the current

		if (current > highest) // compare current number to lowest and assign if true
		{
			highest = current;
		}
	}
	return highest;
}

void calcScore(double* numbers, int n)
{
	int lowest, highest, total;
	int i;
	double current, average;
	total = 0;

	lowest = findLowest(numbers, n);
	highest = findHighest(numbers, n);

	for (i = 0; i < (int)n; i++) // Loop all numbers
	{
		current = numbers[i]; // get the current

		total += current; // Add up to total
	}

	total -= highest + lowest; // subtract the lowest and highest

	if (total <= 0 || n - 2 <= 0) // if there are only 2 numbers, we would divide by zero
	{
		printf("Not enough numbers in array...");
		return;
	}

	average = (double)total / (n - 2);

	printf("Average: %f\n", average);
}

int main()
{
	printf("How many numbers:\n");

	/**
		This will handle the input
	*/
	int num;
	int maxAmount;
	double* numArr;
	// Set the limit for numbers (maxAmount)
	maxAmount = (int)getInputCleaned();

	printf("Max Amount is: %d \n", maxAmount);
	
	// Dynamic array allocation
	// https://www.scaler.com/topics/c/dynamic-array-in-c/
	numArr = (double*)calloc(maxAmount, sizeof(double));
	
	// Loop maxAmount times
	int i;
	for (i = 0; i < maxAmount; i++)
	{
		//printf("%d number: \n", i+1);
		num = getInputCleaned();
		numArr[i] = double(num);
	}

	// Do stuff with the numbers

	printf("-----------------------------\n");
	printf("Lowest: %d", (int)findLowest(numArr, maxAmount));
	printf("Highest: %d", (int)findHighest(numArr, maxAmount));

	calcScore(numArr, maxAmount);

	return 0;
}

