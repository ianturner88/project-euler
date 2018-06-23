#include<iostream>
#include<string>
using namespace std;

void Set_Str1_and_Str2(string &str1, string &str2, string &str3);
void Clear_Str3(string &str3);
void Length_Calculator(string &str1, int &n1);
void Add_Digits(string &str1, string &str2, string &str3, int &n1, int &carry);
void Carry(int &carry, string &str3);
void Reverse(string &str3);

int main()
{
	int addition_limit = 2, exponent = 0, n1, carry = 0;
	string str1 = "1", str2, str3 = "1";

	while (exponent < 1000)
	{
		Set_Str1_and_Str2(str1, str2, str3);
		Clear_Str3(str3);
		Length_Calculator(str1, n1);
		Add_Digits(str1, str2, str3, n1, carry);
		Carry(carry, str3);

		exponent++;
	}

	Reverse(str3);

	cout << str3 << endl;

	system("pause");

	return 0;
}

void Set_Str1_and_Str2(string &str1, string &str2, string &str3)
{
	/*We set the second string equal to the first string*/

	str1 = str3;
	str2 = str3;
}

void Length_Calculator(string &str1, int &n1)
{
	/*We calculate the length of str1. This is needed for a
	subsequent for loop.*/
	
	n1 = str1.length();
}

void Add_Digits(string &str1, string &str2, string &str3, int &n1, int &carry)
{
	/*We add the str1 & str2 to 'simulate' multiplication*/
	
	int sum;

	for (int i = 0; i < n1; i++)
	{
		sum = (str1[i] - '0') + (str2[i] - '0') + carry;

		str3.push_back(sum % 10 + '0');

		carry = sum / 10;
	}

	str3.erase(str3.begin());
}

void Clear_Str3(string &str3)
{
	/* Clear out str3 so that str1 & str2 can be added together and 
	placed into str3.*/
	
	str3 = "0";
}

void Carry(int &carry, string &str3)
{
	/* If there is a 'final' carry, add the carry*/
	
	if (carry == 1)
	{
		str3.push_back(carry + '0');
	}

	carry = 0;
}

void Reverse(string &str3)
{
	reverse(str3.begin(), str3.end());
}