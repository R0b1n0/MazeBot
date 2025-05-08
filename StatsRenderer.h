#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include "StatsTracker.h"
#include "string"

class StatsRenderer
{
public :
	StatsRenderer(sf::Font font, StatsTracker* tracker);
	void DrawStats(sf::RenderWindow& window) const ;

private :
	sf::Font m_font;
	StatsTracker* m_statsTracker;
};

