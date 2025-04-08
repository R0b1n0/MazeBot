#pragma once
#include <vector>
#include "MazeBot.h"
#include "MazeGenerator.h"
#include <unordered_map>

class BotRenderer
{
public :
	BotRenderer(MazeGenerator const& maze);
	void AddBot(MazeBot& bot);
	void RenderBots(sf::RenderWindow& window);

private:
	MazeGenerator const& m_maze;
	sf::RectangleShape m_botShape;
	int m_botSize;
	std::vector<MazeBot*> m_bots;
	
};

