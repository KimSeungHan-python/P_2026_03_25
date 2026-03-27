#include "Monster.h"

AMonster::AMonster()
{
	X = 1;
	Y = 1;
	Mesh = 'M';
}

AMonster::~AMonster()
{

}



void AMonster::BeginPlay()
{
}

void AMonster::Tick()
{

}

void AMonster::Render()
{
	__super::Render();
}
