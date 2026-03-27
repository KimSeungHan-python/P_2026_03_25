#pragma once
#include <string>
#include <Windows.h>


class UMap;

class UEngine
{
public:
	virtual ~UEngine();

	static UEngine* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new UEngine();
		}

		return Instance;
	}

	inline UMap* GetMap()
	{
		return Map;
	}
	void Init();
	void Term();
	void Run();
	void Input();
	void Tick();
	void Render();
	//void LoadMap();

	static int KeyCode;

	//Renderer
	HANDLE ScreenBufferHandle[2];// ¹öÆÛ 2°³ ¾¸
	int ActiveScreenBufferIndex = 0;

	void InitBuffer();
	void Clear();
	void Draw(int InX, int InY, char InMesh);
	void Flip();
	void TermBuffer();


protected:
	UEngine();

	static UEngine* Instance;

	bool IsRunning;
	UMap* Map;
};

#define GEngine			UEngine::GetInstance()
