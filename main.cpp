#include <iostream>
#include <vector> //Container
#include "DynamicArray.h"
#include "String.h"
#include "Engine.h"
#include "Map.h"

using namespace std;





int Data[10] = { 10,9,8,7,6,5,4,3,2,1 };
int Result[10] = {0,};

void SelectionSort(int* array, int size)
{
	int min;
	int min_index;
	for (int i = 0; i < size; i++)
	{
		min = array[i];
		min_index = i;
		for (int j = i+1; j < size; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				min_index = j;
			}
		}
		if (i != min_index)
		{
			swap(array[i], array[min_index]);
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << array[i] << endl;
	}
}

int Compare()
{
	cout << "함수 포인터 " << endl;
	return 0;
}







int main()
{

	//cout << Compare << endl;

	//int (*CompareFunction)(void);
	//CompareFunction = Compare;
	//
	//cout << (*CompareFunction)() << endl;


	GEngine->GetInstance();
	GEngine->GetMap()->Load("TestMap.txt");
	GEngine->Run();



	//search and sort
	//selection and bubble
	//SelectionSort(Data, 10);


	return 0;

}