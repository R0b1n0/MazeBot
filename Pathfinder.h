#pragma once
#include "Vector2Int.h"
#include "MazeBot.h"
#include "MazeGenerator.h"

class Pathfinder
{
public:
	Pathfinder(MazeBot& associatedBot, MazeGenerator& mazeRef);
	virtual void SetParameters(Vector2Int& start, Vector2Int& end);
	virtual void NextSearchStep() = 0;
	virtual const std::vector<Vector2Int*> GetVisitedTiles() = 0;

protected:
	Vector2Int m_start;
	Vector2Int m_end;
	MazeBot* m_connectedBot;
	MazeGenerator* m_mazeInfos;
};

