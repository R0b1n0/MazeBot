#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>

static class InputListener
{
public :
	using InputCallback = std::function<void(sf::Vector2i mousePos)>;
	InputListener();
	void ListenForInputs(sf::Event event, sf::RenderWindow& const win);
	void AddListener(InputCallback listener);
	
private :
	std::vector<InputCallback> m_mouseEventlisteners;
};

