#include "Pathfinder.h"

Pathfinder::Pathfinder(MazeBot& associatedBot, MazeGenerator& mazeRef ) : m_connectedBot(&associatedBot), m_mazeInfos(&mazeRef), m_start(Vector2Int(0,0)), m_end(Vector2Int(0,0))
{

}

void Pathfinder::SetParameters(Vector2Int& start, Vector2Int& end)
{
	m_start = start;
	m_end = end;
	m_connectedBot->m_pos = start;
}

DelegateWrapper<std::function<void(Vector2Int)>> Pathfinder::OnTileDiscovery;
DelegateWrapper<std::function<void(std::vector<Vector2Int>)>> Pathfinder::OnSolutionFound;