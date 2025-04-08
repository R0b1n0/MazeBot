#pragma once
#include <unordered_map>
#include <iostream>
#include <functional>

struct Vector2Int
{
public:
	Vector2Int();
	Vector2Int(int x, int y);
	~Vector2Int();
	bool IsEqual(Vector2Int const& other) const;

	int m_x;
	int m_y;

	bool operator==(const Vector2Int& other) const;
};
//bool operator == (Vector2Int const& a, Vector2Int const& b);


namespace std {
	template <>
	struct hash<Vector2Int> {
		std::size_t operator()(const Vector2Int& v) const {
			return std::hash<int>()(v.m_x) ^ (std::hash<int>()(v.m_y) << 1);
		}
	};
}