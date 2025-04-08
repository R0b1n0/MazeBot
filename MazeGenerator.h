#pragma once
#include "MazeNode.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <iostream>
#include <stdio.h>

class MazeGenerator
{
public :
	MazeGenerator(int windowWidth, int windowHeight, int gridCount);
	void DrawMaze(sf::RenderWindow & window);
	void Build();
	MazeNode* GetNode(Vector2Int& pos);

private :
	void GenerateLinkLessGrid();
	void GenerateRandomConnections(std::vector<MazeNode*>& open, std::vector<MazeNode*>& closed);
	std::vector<MazeNode*> GetNodesAround(const MazeNode& node);

public :
	int m_mazeOffset;
	int m_cellSize;
	int m_wallSize;
	const int m_gridSize;
	sf::Vector2f m_mazeVectorOffset;

private :
	const int m_windowWidth;
	const int m_windowHeight;
	
	std::vector <MazeNode> m_mazeNodes;
	std::vector <int> m_test;
};