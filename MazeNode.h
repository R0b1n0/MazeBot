#pragma once
#include "Vector2Int.h"
struct MazeNode
{
public:
	MazeNode(const Vector2Int& id);
	~MazeNode();
	void AddNeighbor(MazeNode& other);
	bool IsEqual(MazeNode const& other) const;

	Vector2Int m_id;
	MazeNode* m_neighbors[4]{ 0,0,0,0 };

private:
	const int m_maxNeighborCount;
	int m_neighborCount;
	
	
};

bool operator == (MazeNode const& a, MazeNode const& b);