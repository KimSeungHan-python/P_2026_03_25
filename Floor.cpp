#include "Floor.h"

AFloor::AFloor(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
}

AFloor::~AFloor()
{

}



void AFloor::BeginPlay()
{

}

void AFloor::Tick()
{

}

void AFloor::Render()
{
	__super::Render();
}

