#include <iostream>
#include <vector> //Container
#include "DynamicArray.h"
#include "String.h"

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
	//FVector2D First(0, 0);
	//FVector2D Second(2, 2);

	//FVector2D Three(First + Second);

	//Three = First + Second;

	//First + Second;
	//// = First.operator+(Second); 위에 거랑 같음

	char p[5] = "1234";
	String s(p);
	String s1 = "987";
	s = "4234";
	cout << s.length() << endl;
	cout << s[0] << endl;
	s.pushback("56");
	cout << s[5] << endl;
	cout << s.length() << endl;
	s = s1;
	cout << s.length() << endl;// <- 오류남
	s = s + s1;
	cout << s.length() << endl;
	//cout << s.c_str()//Char*


	return 0;

}