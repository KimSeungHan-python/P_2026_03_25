#pragma once
class AActor
{
public:
	AActor();
	AActor(int InX, int InY, char InMesh);
	virtual ~AActor();

	virtual void BeginPlay();
	virtual void Tick();
	virtual void Render();
	virtual void SetActorLocation(int InX, int InY);

protected:
	int X;
	int Y;
	char Mesh;
};

