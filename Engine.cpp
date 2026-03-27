#include "Engine.h"
#include <conio.h>
#include "Map.h"

UEngine* UEngine::Instance = nullptr;
int UEngine::KeyCode = 0;

UEngine::UEngine()
{
	Init();
}

UEngine::~UEngine()
{
	Term();
}

void UEngine::Init()
{
	Map = new UMap;
	IsRunning = true;
}

void UEngine::Term()
{
	delete Map;
	Map = nullptr;
}

void UEngine::Run()
{
	while (IsRunning)
	{
		Input();
		Tick();
		Render();
	}
}

void UEngine::Input()
{
	KeyCode = _getch();
}

void UEngine::Tick()
{
	Map->Tick();
}
void UEngine::Render()
{
	Map->Render();
}

//void UEngine::LoadMap()
//{
//	Map->Load();
//}
