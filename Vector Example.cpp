#include<iostream>
#include<vector>
using namespace std;

int main ()
{
	//vector<DataType> NameOfVector
	
	vector<int> myVector;
	
	myVector.push_back(3);
	
	cout << "Vector: ";
	
	for (unsigned int i = 0; i < myVector.size(); i++)
	{
		cout << myVector[i] << " ";
	}
	
	cout << endl;
	
	return 0;
}
