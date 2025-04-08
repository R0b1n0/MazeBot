#pragma once
#include "vector"
#include "Bouton.h"
#include "Vector2Int.h"
#include <SFML/Graphics.hpp>

class BtnManager
{
public :
	BtnManager(float yOffset);
	void AddBtn(Bouton* newBtn);
	void DrawBtns(sf::RenderWindow& window)const;
	void TriggerButons(sf::Vector2i mousePos);

private :
	std::vector<Bouton*> m_allBtns;
	float m_yOffset;
};

