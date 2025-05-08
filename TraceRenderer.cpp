#include "TraceRenderer.h"

TraceRenderer::TraceRenderer(MazeGenerator& const maze, sf::Color color, sf::Color solutionColo) : m_maze(maze), m_explorationColor(color), m_solutionColor(solutionColo)
{
	Pathfinder::OnTileDiscovery += [this](Vector2Int newVisited) { AddTrace(newVisited); };
	Pathfinder::OnSolutionFound += [this](std::vector<Vector2Int> solution) {SaveSolution(solution); };
}

void TraceRenderer::DrawTrace(sf::RenderWindow& window)
{
	//draw the explored tiles
	DrawTileBatch(m_traces, m_explorationColor, window);

	//Draw solution if ther's one :)
	if (m_foundSolution)
	{
		DrawTileBatch(m_solution, m_solutionColor, window);
	}
}



void TraceRenderer::SaveSolution(std::vector<Vector2Int> solution)
{
	m_solution = solution;
	m_foundSolution = true;
}

void TraceRenderer::RefreshTrace()
{
	m_traces.clear();
	m_solution.clear();
	m_foundSolution = false;
}

void TraceRenderer::AddTrace(const Vector2Int& trace)
{
	m_traces.push_back(trace);
}

void TraceRenderer::DrawTileBatch(std::vector<Vector2Int>& batch, const sf::Color& batchColor, sf::RenderWindow& window)
{
	std::vector<Vector2Int>::iterator batchIt;

	sf::RectangleShape cellRect(sf::Vector2f(m_maze.m_cellSize - 4, m_maze.m_cellSize - 4));
	cellRect.setFillColor(batchColor);

	for (batchIt = batch.begin(); batchIt != batch.end(); batchIt++)
	{
		sf::Vector2f pos(
			m_maze.m_mazeOffset + batchIt->m_x * (m_maze.m_cellSize + m_maze.m_wallSize) + 2,
			m_maze.m_mazeOffset + batchIt->m_y * (m_maze.m_cellSize + m_maze.m_wallSize) + 2
		);

		cellRect.setPosition(pos);

		window.draw(cellRect);
	}
}
