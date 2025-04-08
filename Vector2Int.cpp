#include "Vector2Int.h"

Vector2Int::Vector2Int() : Vector2Int(0,0)
{

}
Vector2Int::Vector2Int(int x, int y) : m_x(x), m_y(y)
{

}

Vector2Int::~Vector2Int()
{

}


bool Vector2Int::IsEqual(Vector2Int const& other) const
{
	return m_x == other.m_x && m_y == other.m_y;
}

bool Vector2Int::operator==(const Vector2Int& other) const
{
	return m_x == other.m_x && m_y == other.m_y;
}

//inline bool operator == (Vector2Int const& a, Vector2Int const& b)
//{
//	return a.IsEqual(b);
//}