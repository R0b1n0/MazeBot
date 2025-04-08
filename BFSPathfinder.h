#pragma once
#include "Pathfinder.h"
#include <queue>
#include <unordered_map>

class BFSPathfinder : public Pathfinder
{
public :
	using Pathfinder::Pathfinder;
	virtual void SetParameters(Vector2Int& start, Vector2Int& end) override;
	virtual void NextSearchStep() override;
	virtual const std::vector<Vector2Int*> GetVisitedTiles() override;

private :
	std::queue<MazeNode*> m_searchQueue;
	std::vector<MazeNode*> m_visited;

	std::unordered_map< MazeNode*, MazeNode* > m_prev;

private :
	bool Visited(MazeNode* element);
};

