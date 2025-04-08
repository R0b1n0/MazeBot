#pragma once
#include<SFML/Graphics.hpp>
#include <stdio.h>
#include "Vector2Int.h"
#include <string>

struct MazeBot
{
public :
	MazeBot(std::string name, sf::Color color, Vector2Int pos = Vector2Int(0,0));
	
	std::string const m_name;
	sf::Color const m_color;
	Vector2Int m_pos;
};

