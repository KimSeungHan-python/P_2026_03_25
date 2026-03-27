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
	InitBuffer();
	IsRunning = true;
}

void UEngine::Term()
{
	delete Map;
	TermBuffer();
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
void UEngine::InitBuffer()
{
	ScreenBufferHandle[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL,
		CONSOLE_TEXTMODE_BUFFER, NULL);
	ScreenBufferHandle[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL,
		CONSOLE_TEXTMODE_BUFFER, NULL);

	CONSOLE_CURSOR_INFO ConsoleCUrsorInfo;
	ConsoleCUrsorInfo.dwSize = 1;
	ConsoleCUrsorInfo.bVisible = FALSE;

	SetConsoleCursorInfo(ScreenBufferHandle[0], &ConsoleCUrsorInfo);
	SetConsoleCursorInfo(ScreenBufferHandle[1], &ConsoleCUrsorInfo);
}
void UEngine::Clear()
{
	DWORD DW;
	FillConsoleOutputCharacter(ScreenBufferHandle[ActiveScreenBufferIndex], ' ', 80 * 25,
		COORD{0,0}, &DW);
}
void UEngine::Draw(int InX, int InY, char InMesh)
{
	char MeshString[2] = { 0, };
	MeshString[0] = InMesh;
	SetConsoleCursorPosition(ScreenBufferHandle[ActiveScreenBufferIndex],
			COORD{(SHORT)InX, (SHORT)InY});
	WriteFile(ScreenBufferHandle[ActiveScreenBufferIndex], MeshString, 1, NULL, NULL);

}
void UEngine::Flip()
{
	SetConsoleActiveScreenBuffer(ScreenBufferHandle[ActiveScreenBufferIndex]);
	ActiveScreenBufferIndex = !ActiveScreenBufferIndex;
}
void UEngine::TermBuffer()
{
	CloseHandle(ScreenBufferHandle[0]);
	CloseHandle(ScreenBufferHandle[1]);
}

//void UEngine::LoadMap()
//{
//	Map->Load();
//}
