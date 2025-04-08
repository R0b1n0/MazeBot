#include "Bouton.h"

Bouton::Bouton(int width, int height, Vector2Int pos, std::string label, sf::Font font) : m_width(width), m_height(height), m_pos(pos), m_label(label), m_font(font)
{
}

void Bouton::AddListeners(BtnCallBack listener)
{
	m_listeners.push_back(listener);
}

void Bouton::OnClickEvent()
{
	for (auto& callback : m_listeners)
	{
		callback();
	}
}
