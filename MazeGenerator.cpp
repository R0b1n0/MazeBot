#include "MazeGenerator.h"


MazeGenerator::MazeGenerator(int windowWidth, int windowHeight, int gridCount) : m_windowWidth(windowWidth), m_windowHeight(windowHeight), m_gridSize(gridCount)
{
    Build();
}

void MazeGenerator::DrawMaze(sf::RenderWindow& window) 
{
    sf::RectangleShape backGround(sf::Vector2f(m_windowWidth, m_windowWidth));
    backGround.setFillColor(sf::Color::White);

    window.draw(backGround);

    std::vector<MazeNode>::iterator allIt;
    MazeNode** neighborIterator = 0;
    
    sf::RectangleShape cellRender (sf::Vector2f(m_cellSize, m_cellSize));
    cellRender.setFillColor(sf::Color::Black);
    sf::RectangleShape lowerFill(sf::Vector2f(m_cellSize, m_wallSize));
    lowerFill.setFillColor(sf::Color::Black);
    sf::RectangleShape sideFill(sf::Vector2f(m_wallSize, m_cellSize));
    sideFill.setFillColor(sf::Color::Black);

    sf::Vector2f currentCellPos(0, 0);

    for (allIt = m_mazeNodes.begin(); allIt != m_mazeNodes.end(); allIt++)
    {
        currentCellPos.x = (allIt->m_id.m_x * (m_cellSize + m_wallSize)) + m_wallSize + m_mazeOffset;
        currentCellPos.y = (allIt->m_id.m_y * (m_cellSize + m_wallSize)) + m_wallSize + m_mazeOffset;

        cellRender.setPosition(currentCellPos);
        window.draw(cellRender);

        for (neighborIterator = std::begin(allIt->m_neighbors); neighborIterator != std::end(allIt->m_neighbors); neighborIterator++)
        {
            if (*neighborIterator == 0)
            {
                // no neighbor or out of unexplored neighbors
                break;
            }
            
            if ((*neighborIterator)->m_id.m_x == allIt->m_id.m_x)
            {
                //one node above another 
                if ((*neighborIterator)->m_id.m_y > allIt->m_id.m_y)
                {
                    //neighbor below 
                    lowerFill.setPosition(currentCellPos.x, currentCellPos.y+m_cellSize);
                }
                else
                {
                    //neighbor above
                    lowerFill.setPosition(currentCellPos.x, currentCellPos.y - m_wallSize);
                }
                window.draw(lowerFill);
            }
            else
            {
                //neighbor and current are side by side 
                if ((*neighborIterator)->m_id.m_x > allIt->m_id.m_x)
                {
                    //neighbor rigth 
                    sideFill.setPosition(currentCellPos.x + m_cellSize + m_wallSize, currentCellPos.y);
                }
                else
                {
                    //neighbor left
                    sideFill.setPosition(currentCellPos.x - m_wallSize, currentCellPos.y);
                }
                window.draw(sideFill);
            }
        }
    }
}

void MazeGenerator::Build()
{
    GenerateLinkLessGrid();

    srand(time(0));
    std::vector<MazeNode*> open;
    std::vector<MazeNode*> closed;
    open.push_back(&m_mazeNodes[rand() % m_mazeNodes.size()]);
    closed.push_back(*open.begin());

    GenerateRandomConnections(open, closed);

    // set up render parameters
    m_wallSize = 1;
    m_cellSize = ((m_windowWidth - m_wallSize) / m_gridSize) - m_wallSize;
    //used to place the maze in the middle of the screen
    m_mazeOffset = (m_windowWidth - ((m_gridSize * (m_cellSize + m_wallSize)) + m_wallSize)) / 2;

    m_mazeVectorOffset = sf::Vector2f(m_mazeOffset+1, m_mazeOffset+1);
}

MazeNode* MazeGenerator::GetNode(Vector2Int& pos)
{
    //is this vector in maze bounds ?
    if (pos.m_x >= m_gridSize || pos.m_y >= m_gridSize)
    return nullptr;

    return &m_mazeNodes[pos.m_x + (pos.m_y * m_gridSize)];
}


void MazeGenerator::GenerateLinkLessGrid()
{
	for (int i = 0; i < m_gridSize; i++)
	{
		for ( int j = 0; j < m_gridSize; j++)
		{
			m_mazeNodes.push_back(MazeNode(Vector2Int(j, i)));
		}
	}
}

void MazeGenerator::GenerateRandomConnections(std::vector<MazeNode*>& open, std::vector<MazeNode*>& closed)
{
    // using this method recursivly cause a stack overflow if the maze size is greater than 20, 
    // we'll use a while loop instead

    while (!open.empty())
    {
        MazeNode* current = open[open.size() - 1];
        open.pop_back();

        std::vector<MazeNode*>::iterator it;
        std::vector<MazeNode*> surroundingNodes = GetNodesAround(*current);
        std::random_shuffle(surroundingNodes.begin(), surroundingNodes.end());

        for (it = surroundingNodes.begin(); it != surroundingNodes.end(); it++)
        {
            if (std::count(closed.begin(), closed.end(), *it) == 0)
            {
                // the node pointed by the iterator hasn't been explored yet
                open.push_back(current);

                current->AddNeighbor(**it);
                (*it)->AddNeighbor(*current);

                closed.push_back(*it);
                open.push_back(*it);
                
                break;
            }
        }
    }
}

std::vector<MazeNode*> MazeGenerator::GetNodesAround(const MazeNode& node)
{
    std::vector<MazeNode*> result;

    // left Node
    if (node.m_id.m_x != 0)
    {
        result.push_back(&m_mazeNodes[(node.m_id.m_y * m_gridSize) + node.m_id.m_x - 1]);
    }

    // right Node 
    if (node.m_id.m_x != m_gridSize - 1)
    {
        result.push_back(&m_mazeNodes[(node.m_id.m_y * m_gridSize) + node.m_id.m_x + 1]);
    }

    // top node
    if (node.m_id.m_y != 0)
    {
        result.push_back(&m_mazeNodes[(node.m_id.m_y * m_gridSize) + node.m_id.m_x - m_gridSize]);
    }

    // bottom node
    if (node.m_id.m_y != m_gridSize - 1)
    {
        result.push_back(&m_mazeNodes[(node.m_id.m_y * m_gridSize) + node.m_id.m_x + m_gridSize]);
    }

    return result;
}
