#include <bits/stdc++.h>
using namespace std;

int main (void)
{
	long long int n = 50;
	long long int a = 0;
	
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));
	long long int sum = 0;
	long long int count = 0;
	long long int possiblesum = 0;
	long long int answersum = 1;
	long long int possiblecount = 0;
	long long int answercount = 1;
	
	while (a < 50)
	{
		for(long long int p = 2; p*p <= n; p++)
		{
			for(long long int i = 2*p; i <= n; i += p)
			{
				prime[i] = false;
			}
		}
	
		for(long long int c = 2; c <= n; c++)
		{
			
			
			
			for(long long int b = c; b <= n; b++)
			{
				if (prime[b] == true)
				{	
					sum += c;
					count++;
				}
				
				if (prime[sum] == true && prime[b] == true && sum < n)
				{	
					possiblesum = sum;
					answercount = count;
				}
			}
		}
	}	
	
	cout << possiblesum << ": " << answercount;
}
