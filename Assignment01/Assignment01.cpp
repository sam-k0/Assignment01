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

double findLowest(int* arr, int n) // finds the lowest number in array
{
	int i;
	double lowest;
	lowest = 11;
	double current;
	printf("Find lowest\n");

	for (i = 0; i < n; i++)
	{
		current = arr[i];

		printf("curr: %d", current);

		if (current < lowest)
		{
			lowest = current;
		}
	}

	return lowest;
}

int main()
{
	printf("How many numbers:\n");

	/**
		This will handle the input
	*/
	int num;
	int maxAmount;
	int* numArr;
	// Set the limit for numbers (maxAmount)
	maxAmount = (int)getInputCleaned();

	printf("Max Amount is: %d \n", maxAmount);

	numArr = (int*)calloc(maxAmount, sizeof(int));
	

	// Loop maxAmount times
	int i;
	for (i = 0; i < maxAmount; i++)
	{
		printf("%d number: \n", i+1);
		num = getInputCleaned();
		numArr[i] = num;
	}

	// Do stuff with array
	for (i = 0; i < maxAmount; i++)
	{
		printf("%d number: %d\n", i, numArr[i]);
	}

	printf("-----------------------------");

	printf("Lowest: %d", findLowest(numArr, maxAmount));

	return 0;
}

