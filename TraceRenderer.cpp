#include "TraceRenderer.h"

TraceRenderer::TraceRenderer(MazeGenerator& const maze, sf::Color color) : m_maze(maze), m_color(color)
{
}

void TraceRenderer::DrawTrace(sf::RenderWindow& window)
{
	std::unordered_set<Vector2Int>::iterator traceIt = m_traces.begin();
	sf::RectangleShape cellRect(sf::Vector2f(m_maze.m_cellSize - 4, m_maze.m_cellSize - 4));
	cellRect.setFillColor(m_color);

	for (traceIt = m_traces.begin(); traceIt != m_traces.end(); traceIt++)
	{
		sf::Vector2f pos(
			m_maze.m_mazeOffset + traceIt->m_x * (m_maze.m_cellSize + m_maze.m_wallSize) + 2,
			m_maze.m_mazeOffset + traceIt->m_y * (m_maze.m_cellSize + m_maze.m_wallSize) + 2
		);

		cellRect.setPosition(pos);

		window.draw(cellRect);
	}
}

void TraceRenderer::RefreshTrace()
{
	m_traces.clear();
}

void TraceRenderer::AddTrace(const Vector2Int& trace)
{
	m_traces.insert(trace);
}
