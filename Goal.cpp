#include "Goal.h"

AGoal::AGoal()
{
	X = 3;
	Y = 3;
	Mesh = 'G';
}

AGoal::~AGoal()
{
}



void AGoal::BeginPlay()
{
}

void AGoal::Tick()
{

}

void AGoal::Render()
{
	__super::Render();
}
