#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main (void)
{
	int n = 1000000;
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));
	
	for(long long int p = 2; p*p <= n; p++)
	{
		for(long long int i = 2*p; i <= n; i += p)
		{
			prime[i] = false;
		}
	}
	
	int flag = 1;
	int Goldbach = 7;
	int square, p;
	
	while (flag == 1)
	{
		Goldbach += 2;
		
		if (prime[Goldbach] == false)
		{
			for (square = 1; sqaure < Goldbach; square++)
			{
				square = 2 * pow(square, 2);
				
				for (p = 2; p < n; )
			}
		}
	}

}
