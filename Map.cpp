#include <fstream>
#include <iostream>
#include "Map.h"
#include "Actor.h"
#include "Monster.h"
#include "Wall.h"
#include "Goal.h"
#include "Floor.h"
#include "Player.h"


UMap::UMap()
{

}

UMap::~UMap()
{
	for (auto Actor : Actors)
	{
		delete Actor;
	}

	Actors.clear();
}

void UMap::Tick()
{
	for (auto actor : Actors)
	{
		actor->Tick();
	}
}
void UMap::Render()
{
	for (auto actor : Actors)
	{
		actor->Render();
	}
}

void UMap::Load(string s)
{
	int YlineCount = 0;
	std::ifstream file(s);
	std::string line;
	if (file.is_open()) {
		// 더 이상 읽을 줄이 없을 때까지 반복
		while (std::getline(file, line))
		{
			YlineCount++;
			for (int i = 0; i < line.size(); i++)//맵은 잘 불러짐
			{
				if (line[i] == 'P')
				{
					SpawnActors<APlayer>()->SetActorLocation(i, YlineCount);
				}
				else if (line[i] == 'M')
				{
					SpawnActors<AMonster>()->SetActorLocation(i, YlineCount);

				}
				else if (line[i] == 'G')
				{
					SpawnActors<AGoal>()->SetActorLocation(i, YlineCount);

				}
				else if (line[i] == '#')
				{
					SpawnActors<AWall>()->SetActorLocation(i, YlineCount);

				}
				else
				{
					SpawnActors<AFloor>()->SetActorLocation(i, YlineCount);

				}
			}
		
		}
		file.close();
	}
}


