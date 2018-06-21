#include<string>
#include<iostream>
using namespace std;

void Length_Calculator(int &n1, int &n2, int &length_difference, string &fibonacci1, string &fibonacci2);
void Fibonacci_Generator(string &fibonacci1, string &fibonacci2, string &fibonacci_next);
void Add_LSB(string &fibonacci1, string &fibonacci2, string &fibonacci_next, int &length_difference, int &carry, int &n1, int &n2, int &sum);
void Add_MSB(string &fibonacci1, string &fibonacci2, string &fibonacci_next, int &length_difference, int &carry, int &n1, int &n2, int &sum);

int main()
{
	string fibonacci1 = "1", fibonacci2 = "1", fibonacci_next = "2";
	int length_difference, carry;
	int n1, n2, sum;

	Length_Calculator(n1, n2, length_difference, fibonacci1, fibonacci2);
	Fibonacci_Generator(fibonacci1, fibonacci2, fibonacci_next);
	Add_LSB(fibonacci1, fibonacci2, fibonacci_next, length_difference, carry, n1, n2, sum);
	Add_MSB(fibonacci1, fibonacci2, fibonacci_next, length_difference, carry, n1, n2, sum);
}

void Length_Calculator(int &n1, int &n2, int &length_difference, string &fibonacci1, string &fibonacci2)
{
	n1 = fibonacci1.length();
	n2 = fibonacci2.length();

	length_difference = n2 - n1;
}

void Fibonacci_Generator(string &fibonacci1, string &fibonacci2, string &fibonacci_next)
{
	/*Traditionally, Fnext = F1 + F2 is the first line*/

	fibonacci1 = fibonacci2;
	fibonacci2 = fibonacci_next;
}

void Add_LSB(string &fibonacci1, string &fibonacci2, string &fibonacci_next, int &length_difference, int &carry, int &n1, int &n2, int &sum)
{
	/*Add the least significant bits of both numbers*/

	for (int i = n1 - 1; i >= 0; i--)
	{
		sum = (fibonacci1[i] - '0') + (fibonacci2[i + length_difference] - '0') + carry;

		fibonacci_next.push_back(sum % 10 + '0');

		carry = sum / 10;
	}
}

void Add_MSB(string &fibonacci1, string &fibonacci2, string &fibonacci_next, int &length_difference, int &carry, int &n1, int &n2, int &sum)
{
	for (int i = n2 - n1 - 1; i <= 0; i--)
	{

	}
}