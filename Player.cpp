#include "Player.h"
#include "Engine.h"

APlayer::APlayer()
{
	X = 1;
	Y = 1;
	Mesh = 'P';
	ZOrder = 10;
}

APlayer::~APlayer()
{

}



void APlayer::BeginPlay()
{
	__super::BeginPlay();
}

void APlayer::Tick()
{
	__super::Tick();

	if (UEngine::KeyCode == 'w')
	{
		Y--;
	}
	if (UEngine::KeyCode == 's')
	{
		Y++;
	}
	if (UEngine::KeyCode == 'a')
	{
		X--;
	}
	if (UEngine::KeyCode == 'd')
	{
		X++;
	}
}

void APlayer::Render()
{
	__super::Render();
}

