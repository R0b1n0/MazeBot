#include "StatsRenderer.h"

StatsRenderer::StatsRenderer(sf::Font font, StatsTracker* tracker) : m_font(font), m_statsTracker(tracker)
{
}

void StatsRenderer::DrawStats(sf::RenderWindow& window) const
{
	sf::Vector2f pos(200, 800);

	sf::RectangleShape btnShape = sf::RectangleShape(sf::Vector2f(500, 100));

	btnShape.setPosition(pos);
	btnShape.setFillColor(sf::Color().White);


	sf::Text iterationText;
	sf::Text timeText;

	sf::String count = "Visited tiles count " + std::to_string(m_statsTracker->GetIteration());

	sf::String time = "Search time " + std::to_string(m_statsTracker->GetCalculationTime());

	iterationText.setString(count);
	timeText.setString(time);

	iterationText.setFont(m_font);
	timeText.setFont(m_font);

	iterationText.setFillColor(sf::Color::Black);
	timeText.setFillColor(sf::Color::Black);

	iterationText.setOrigin(iterationText.getLocalBounds().width / 2, (iterationText.getLocalBounds().height / 2) + iterationText.getLocalBounds().top);
	timeText.setOrigin(timeText.getLocalBounds().width / 2, (timeText.getLocalBounds().height / 2) + timeText.getLocalBounds().top);

	sf::Vector2f newPos(btnShape.getPosition().x + (btnShape.getSize().x / 2), btnShape.getPosition().y + (btnShape.getSize().y / 2)-25);


	iterationText.setPosition(newPos);

	sf::Vector2f newPos2(btnShape.getPosition().x + (btnShape.getSize().x / 2), btnShape.getPosition().y + (btnShape.getSize().y / 2)+25);
	timeText.setPosition(newPos2);

	window.draw(btnShape);
	window.draw(iterationText);
	window.draw(timeText);

}
