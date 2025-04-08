#include "BtnManager.h"

BtnManager::BtnManager(float yOffset) : m_yOffset(yOffset)
{
}

void BtnManager::AddBtn(Bouton* newBtn)
{
	m_allBtns.push_back(newBtn);
}

void BtnManager::DrawBtns(sf::RenderWindow&  window) const
{
	std::vector<Bouton*>::const_iterator it;

	for (it = m_allBtns.cbegin(); it != m_allBtns.cend(); it++)
	{
		sf::Vector2f pos((*it)->m_pos.m_x, (*it)->m_pos.m_y + m_yOffset);

		sf::RectangleShape btnShape = sf::RectangleShape(sf::Vector2f((*it)->m_width, (*it)->m_height));

		btnShape.setPosition(pos);
		btnShape.setFillColor(sf::Color().White);

		
		sf::Text btnText;
		btnText.setString((*it)->m_label);
		btnText.setFont((*it)->m_font);
		btnText.setFillColor(sf::Color::Black);
		
		btnText.setOrigin(btnText.getLocalBounds().width/2, (btnText.getLocalBounds().height / 2) + btnText.getLocalBounds().top);
		sf::Vector2f newPos(btnShape.getPosition().x + (btnShape.getSize().x / 2), btnShape.getPosition().y + (btnShape.getSize().y / 2));
		
		
		btnText.setPosition(newPos);

		window.draw(btnShape);
		window.draw(btnText);
	}
}

void BtnManager::TriggerButons(sf::Vector2i mousePos)
{
	std::vector<Bouton*>::const_iterator it;

	for (it = m_allBtns.cbegin(); it != m_allBtns.cend(); it++)
	{
		sf::Vector2f pos((*it)->m_pos.m_x, (*it)->m_pos.m_y + m_yOffset);

		sf::RectangleShape btnShape = sf::RectangleShape(sf::Vector2f((*it)->m_width, (*it)->m_height));

		btnShape.setPosition(pos);

		if (btnShape.getGlobalBounds().contains(mousePos.x, mousePos.y))
		{
			(*it)->OnClickEvent();
		}
	}
}
