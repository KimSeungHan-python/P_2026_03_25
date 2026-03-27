#include <iostream>
#include <vector> //Container
#include "DynamicArray.h"
#include "String.h"
#include "Engine.h"
#include "Map.h"

using namespace std;



int main()
{

	GEngine->GetInstance();
	GEngine->GetMap()->Load("TestMap.txt");
	GEngine->Run();





	return 0;

}