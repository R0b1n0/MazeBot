#include "BotRenderer.h"

BotRenderer::BotRenderer(MazeGenerator const& maze) : m_maze(maze)
{
	m_botSize = m_maze.m_cellSize / 2 ;
	m_botShape =  sf::RectangleShape(sf::Vector2f((float)m_botSize, (float)m_botSize));
}

void BotRenderer::AddBot(MazeBot& bot)
{
	m_bots.push_back(&bot);
}

void BotRenderer::RenderBots(sf::RenderWindow& window)
{
	std::vector<MazeBot*>::iterator it;

	for (it = m_bots.begin(); it != m_bots.end(); it++)
	{
		sf::Vector2f pos(
			(float)(m_maze.m_mazeOffset + (*it)->m_pos.m_x * (m_maze.m_cellSize + m_maze.m_wallSize) + (m_maze.m_cellSize - m_botSize) / 2),
			(float)(m_maze.m_mazeOffset + (*it)->m_pos.m_y * (m_maze.m_cellSize + m_maze.m_wallSize) + (m_maze.m_cellSize - m_botSize) / 2)
		);

		m_botShape.setPosition(pos);
		m_botShape.setFillColor((*it)->m_color);

		window.draw(m_botShape);
	}
}