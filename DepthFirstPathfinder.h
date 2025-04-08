#pragma once
#include "Pathfinder.h"
#include <vector>

class DepthFirstPathfinder : public Pathfinder
{
public :
	using Pathfinder::Pathfinder;
	virtual void SetParameters(Vector2Int& start, Vector2Int& end) override;
	virtual void NextSearchStep() override;

private :
	std::vector<MazeNode*> m_open;
	std::vector<MazeNode*> m_closed;
};

