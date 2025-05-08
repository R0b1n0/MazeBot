#include "BFSPathfinder.h"
#include "BotRenderer.h"

void BFSPathfinder::SetParameters(Vector2Int& start, Vector2Int& end)
{
	Pathfinder::SetParameters(start, end);
	m_searchQueue = std::queue<MazeNode*>();
	m_visited.clear();
	m_prev.clear();

	m_searchQueue.push(m_mazeInfos->GetNode(start));
	m_visited.push_back(m_mazeInfos->GetNode(start));
	m_prev[m_mazeInfos->GetNode(start)] = 0;

	//NextSearchStep();
}

void BFSPathfinder::NextSearchStep()
{
	if (m_searchQueue.size() > 0)
	{
		MazeNode* current = m_searchQueue.front();
		
		m_searchQueue.pop();

		MazeNode** it;
		int unvisitedCount(0);

		//iterate among neighbors
		for (it = &(current->m_neighbors[0]); it != &(current->m_neighbors[4]); it++)
		{
			if (*it != 0)
			{
				if (!Visited(*it))
				{
					m_searchQueue.push((*it));
					OnTileDiscovery.Invoke((**it).m_id);
					m_visited.push_back((*it));
					m_prev[*it] = current;
					m_connectedBot->m_pos = current->m_id;

					if ((*it)->m_id == m_end)
					{
						std::cout << " Found exit" << std::endl;

						MazeNode* lastParentPtr = (m_prev[m_mazeInfos->GetNode(m_end)]);
						Vector2Int lastParent;
						m_searchQueue = std::queue<MazeNode*>();

						std::vector<Vector2Int> solutionPath;
						//Recreate Path 
						while (lastParentPtr != 0)
						{
							lastParent = lastParentPtr->m_id;
							solutionPath.push_back(lastParent);
							std::cout << lastParent.m_x << ";" << lastParent.m_y << std::endl;
							lastParentPtr = m_prev[lastParentPtr];
						}
						OnSolutionFound.Invoke(solutionPath);
					}
				}
			}
		}
	}
}

const std::vector<Vector2Int*> BFSPathfinder::GetVisitedTiles()
{
	return std::vector<Vector2Int*>();
}

bool BFSPathfinder::Visited(MazeNode* element)
{
	std::vector<MazeNode*>::iterator it;

	for (it = m_visited.begin(); it != m_visited.end(); it++)
	{
		if (*it == element)
			return true;
	}

	return false;
}
