#pragma once
#include <SFML/Graphics/Shader.hpp>
#include "Vector2Int.h"
#include "MazeGenerator.h"
#include "Pathfinder.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <unordered_set>

class TraceRenderer
{
public : 
	TraceRenderer(MazeGenerator& const maze, sf::Color explorationColor, sf::Color solutionColor);

	void DrawTrace(sf::RenderWindow& window);
	void SaveSolution(std::vector<Vector2Int> solution);
	void RefreshTrace();
	void AddTrace(const Vector2Int& trace);

	void testMethode() {}

private :
	MazeGenerator const& m_maze;
	sf::Color m_explorationColor;
	sf::Color m_solutionColor;
	std::vector<Vector2Int> m_traces;
	std::vector<Vector2Int> m_solution;
	bool m_foundSolution;

	void DrawTileBatch(std::vector<Vector2Int>& batch, const sf::Color& batchColor, sf::RenderWindow& window);
};

