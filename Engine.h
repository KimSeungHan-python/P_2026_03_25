#pragma once
#include <string>


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
protected:
	UEngine();

	static UEngine* Instance;

	bool IsRunning;
	UMap* Map;
};

#define GEngine			UEngine::GetInstance()
