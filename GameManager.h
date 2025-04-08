#pragma once
#include "MazeGenerator.h"
#include "Vector2Int.h"
#include "Pathfinder.h"

class GameManager
{
public :
	GameManager(MazeGenerator const& maze);
	void GenerateGameParameters();
	void StartGame();
	void DrawStartEnd(sf::RenderWindow& window);
	void UpdateGameState(float deltaTime);
	void AddPathfinder(Pathfinder* pathfinder);

private: 
	//GM parameters
	bool m_running;
	MazeGenerator const& m_maze;
	
	//Pathfinders
	std::vector<Pathfinder*> m_pathfinders;
	int m_currentPathfinderIndex;

	//Render parameters 
	Vector2Int m_start;
	Vector2Int m_end;
	sf::RectangleShape m_pointShape;
	sf::Vector2f CalculatePointRenderPos(Vector2Int const& pos);
};

