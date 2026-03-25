#include <iostream>
#include <vector> //Container
#include "DynamicArray.h"

using namespace std;

//template<typename T>
//class Data
//{
//public:
//	T InnerData;
//};

class FVector2D
{
public:
	FVector2D(int InX = 0, int InY = 0) : X(InX), Y(InY)
	{

	}
	int X;
	int Y;

	//oprator overloading
	FVector2D operator+(FVector2D RightHandSide)
	{
		FVector2D New;
		New.X = X + RightHandSide.X;
		New.Y = Y + RightHandSide.Y;

		return New;
	}
};



int main()
{
	FVector2D First(0, 0);
	FVector2D Second(2, 2);

	FVector2D Three(First + Second);

	Three = First + Second;

	First + Second;
	// = First.operator+(Second); 위에 거랑 같음
}