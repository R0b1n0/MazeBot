#include "DepthFirstPathfinder.h"

void DepthFirstPathfinder::SetParameters(Vector2Int& start, Vector2Int& end)
{
	Pathfinder::SetParameters(start,end);
	m_open.clear();
	m_closed.clear();
}

void DepthFirstPathfinder::NextSearchStep()
{

}
