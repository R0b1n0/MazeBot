#include "MazeNode.h"
MazeNode::MazeNode(const Vector2Int& id) : m_id(id), m_neighborCount(0), m_maxNeighborCount(4)
{
}

MazeNode::~MazeNode()
{
	
}

void MazeNode::AddNeighbor(MazeNode& other)
{
	if (m_neighborCount >= m_maxNeighborCount)
		return;

	m_neighbors[m_neighborCount] = &other;
	m_neighborCount++;
}

bool MazeNode::IsEqual(MazeNode const& other) const
{
	return m_id == other.m_id;
}

bool operator == (MazeNode const& a, MazeNode const& b)
{
	return a.IsEqual(b);
}