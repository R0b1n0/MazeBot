#include "InputListener.h"

InputListener::InputListener()
{
}

void InputListener::ListenForInputs(sf::Event event, sf::RenderWindow& const win)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			for (auto& callback : m_mouseEventlisteners)
			{
				callback(sf::Mouse::getPosition(win));
			}
		}
	}
	break;
	}
}

void InputListener::AddListener(InputCallback listener)
{
	m_mouseEventlisteners.push_back(listener);
}
