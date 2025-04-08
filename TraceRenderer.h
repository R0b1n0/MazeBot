#pragma once
#include <SFML/Graphics/Shader.hpp>
#include "Vector2Int.h"
#include "MazeGenerator.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <unordered_set>

class TraceRenderer
{
public : 
	TraceRenderer(MazeGenerator& const maze, sf::Color color);

	void DrawTrace(sf::RenderWindow& window);
	void RefreshTrace();
	void AddTrace(const Vector2Int& trace);

private :
	MazeGenerator const& m_maze;
	sf::Color m_color;
	std::unordered_set<Vector2Int> m_traces;
};

