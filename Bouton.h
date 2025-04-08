#pragma once
#include "Vector2Int.h"
#include <functional>
#include <string>
#include<vector>
#include <SFML/Graphics.hpp>
#include <iostream>

class Bouton
{
public : 
	 using BtnCallBack = std::function<void()>;
	 Bouton(int width, int height, Vector2Int pos, std::string label, sf::Font font);
	 void AddListeners(BtnCallBack listener);
	 void OnClickEvent();
	 const Vector2Int m_pos;
	 const int m_height;
	 const int m_width;
	 const std::string m_label;
	 const sf::Font m_font;

private :
	
	std::vector<BtnCallBack> m_listeners;
};

