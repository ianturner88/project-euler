#include<iostream>
#include <vector>
#include <array>
#include <string>
#include <time.h>
using namespace std;

void Parse_Six_Digit_Number(int six_digit_number, int number_counter, int zero_through_nine[]);
int Create_Fingerprint(int zero_through_nine[], int power_10[]);
void Power_10_Array(int power_10[]);
void Store_Fingerprint(int fingerprint_int, string fingerprint_string, vector<string> &fingerprint, int number_counter);
void Program_Execution_Time(clock_t total_time);
void Find_Answer(vector<string> &fingerprint);

int main(void)
{
	clock_t total_time;
	//start clock
	total_time = clock();
	
	int six_digit_number = 100000, number_counter = 0, zero_through_nine[10] = { 0 }, power_10[6], fingerprint_int;
	string fingerprint_string = "";
	vector<string> fingerprint;

	Power_10_Array(power_10);

	while (six_digit_number < 1000000)
	{
		Parse_Six_Digit_Number(six_digit_number, number_counter, zero_through_nine);
		fingerprint_int = Create_Fingerprint(zero_through_nine, power_10);
		Store_Fingerprint(fingerprint_int, fingerprint_string, fingerprint, number_counter);
		six_digit_number++;
	}

	Find_Answer(fingerprint);

	//output program's execution time
	Program_Execution_Time(total_time);

	getchar();
}

void Find_Answer(vector<string> &fingerprint)
{
	int answer_counter = 0, vector_index_counter = 0;
	string possible_answer = "";

	for (int i = 0; i < fingerprint.size(); i++)
	{
		//retrieve new fingerprint to see if there's 5 other matches
		possible_answer = fingerprint[i];
		//starting point is at index value off current fingerprint
		vector_index_counter = i;
		//reset
		answer_counter = 0;

		while ((i < fingerprint.size()) && (answer_counter != 6))
		{
			//cycle the new fingerprint through all remaining cases

			if (possible_answer == fingerprint[vector_index_counter])
			{
				// increment number of matches recorded
				answer_counter++;
			}
		}
	}
}

void Store_Fingerprint(int fingerprint_int, string fingerprint_string, vector<string> &fingerprint, int number_counter)
{
	/*converts fingerprint int to a 10 digit string*/
	int remainder;

	while (fingerprint_int > 0)
	{
		//identify least significant digit of fingerprint_int
		remainder = fingerprint_int % 10;
		//shrink number
		fingerprint_int /= 10;
		//create string length
		fingerprint_string += (remainder + '0');
	}

	//store the individual number's fingerprint 
	fingerprint.push_back(fingerprint_string);
}

int Create_Fingerprint(int zero_through_nine[], int power_10[])
{
	/*create & store all individual numbers' fingerprints*/
	
	int fingerprint_to_store = 0, power_counter = 0;

	for (int i = 0; i < 11; i++)
	{
		// final output will be in form abcdefghij (a = 0, ... j = 9)
		fingerprint_to_store += (zero_through_nine[i] * power_10[power_counter]);
		//icrease power of 10
		power_counter++;
	}

	return fingerprint_to_store;
}

void Parse_Six_Digit_Number(int six_digit_number, int number_counter, int zero_through_nine[])
{
	/*create a fingprint for every number that is 6 digits long*/
	
	int least_significant_digit;
	zero_through_nine[10];

	for (int i = 0; i < 11; i++)
	{
		zero_through_nine[i] = 0;
	}
	
	while (six_digit_number > 0)
	{
		/*parse each given number*/
		
		//identify right-most digit
		least_significant_digit = six_digit_number % 10;
		//downsize number by one digit
		six_digit_number /= 10;
		//tally up the given number's fingerprint
		zero_through_nine[least_significant_digit] += 1;
	}
}

void Program_Execution_Time(clock_t total_time)
{
	//calculate total execution time
	total_time = clock() - total_time;
	//output program's execution time
	cout << "program's execution took: " << total_time << endl;
}

void Power_10_Array(int power_10[])
{
	for (int i = 0; i < 11; i++)
	{
		power_10[i] = pow(10, i);
	}
}