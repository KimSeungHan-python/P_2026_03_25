#include <iostream>
#include <vector> //Container
#include "DynamicArray.h"

using namespace std;



int main()
{
	vector<int> IntDArray;

	DynamicArray OurArray;

	OurArray.PushBack(1);
	OurArray.PushBack(2);
	OurArray.PushBack(3);
	OurArray.PushBack(4);

	cout << OurArray.GetSize() << endl;
	cout << OurArray.GetCapacity() << endl;
	OurArray.Pop(2);

	for (int i = 0; i < OurArray.GetSize(); i++)
	{
		cout << OurArray[i] << " ";
	}

	OurArray.PushBack(6);
	for (int i = 0; i < OurArray.GetSize(); i++)
	{
		cout << OurArray[i] << " ";
	}

}