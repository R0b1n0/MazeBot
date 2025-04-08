#include "GameManager.h"

GameManager::GameManager(MazeGenerator const& maze) : m_maze(maze), m_currentPathfinderIndex(0), m_running(false), m_pointShape(sf::RectangleShape(sf::Vector2f(m_maze.m_cellSize, m_maze.m_cellSize)))
{
}

#pragma region StartEnd
void GameManager::GenerateGameParameters()
{
	m_start = Vector2Int(rand() % m_maze.m_gridSize, rand() % m_maze.m_gridSize);

	do
	{
		m_end = Vector2Int(rand() % m_maze.m_gridSize, rand() % m_maze.m_gridSize);
	} while (m_end == m_start);


	std::vector<Pathfinder*>::iterator it;
	for (it = m_pathfinders.begin(); it != m_pathfinders.end(); it++)
	{
		(*it)->SetParameters(m_start, m_end);
	}
}

void GameManager::DrawStartEnd(sf::RenderWindow& window)
{
	m_pointShape.setPosition(CalculatePointRenderPos(m_start));
	m_pointShape.setFillColor(sf::Color::Green);
	window.draw(m_pointShape);

	m_pointShape.setPosition(CalculatePointRenderPos(m_end));
	m_pointShape.setFillColor(sf::Color::Magenta);
	window.draw(m_pointShape);
}

sf::Vector2f GameManager::CalculatePointRenderPos(Vector2Int const& pos)
{
	float xPos = pos.m_x * (m_maze.m_cellSize + m_maze.m_wallSize);
	float yPos = pos.m_y * (m_maze.m_cellSize + m_maze.m_wallSize);

	sf::Vector2f posInMaze = sf::Vector2f(xPos, yPos);

	return m_maze.m_mazeVectorOffset + posInMaze;
}
#pragma endregion
#pragma region Pathfinders
void GameManager::StartGame()
{
	m_running = true;
}
void GameManager::UpdateGameState(float deltaTime)
{
	if (!m_running)
		return;

	m_pathfinders[m_currentPathfinderIndex]->NextSearchStep();
}
void GameManager::AddPathfinder(Pathfinder* pathfinder)
{
	m_pathfinders.push_back(pathfinder);
}
#pragma endregion
