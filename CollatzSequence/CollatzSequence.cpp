// CollatzSequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int n_max; //User specified upper limit (should be constant int?)
	int n;
	int seq_length; //Current sequence length evaluated
	int max_length = 0; //Maximum sequence length found
	int max_seq_pos = 0;//Number with the longest Collatz sequence

	cout << "This program finds the integer below a user specified limit which has the longest Collatz sequence. \n";
	cout << "Enter the upper limit: "; //this ends the line and clears the buffer
	cin >> n_max; //Reads the input buffer into n_max
	//cout << endl;
	cin.ignore();

	/*Simplified version with low memory requirements*/
	for (int i = 1; i < n_max; i++)
	{
		seq_length = 1;
		n = i;
		
		while (n != 1)// ( (n != 1) && (n >= i) )
		{
			if ((n % 2) == 0)
				n = n / 2;
			else
				n = 3 * n + 1;

			seq_length++;
		}//end while

		if (seq_length > max_length)
		{
			max_length = seq_length;
			max_seq_pos = i;//Since n was used to run the seq
		}
	}//end for i

	/*Optimised Version at Expense of Memory*/
	for (int i = 1; i < n_max; i++)
	{

	}

	/*	THEORETICAL
		A version which breaks the search space into a number of smaller sequential
		search spaces could be made. In this event a multithreaded processor could
		process each space independantly to minimise the time required.
	*/
		
	cout << "\n The number with longest sequence below " << n_max << " is " <<max_seq_pos;
	cout << "\n with a sequence length of " << max_length << endl;

	cin.ignore(); //Wait for keypress to end program
    
	return 0;
}

