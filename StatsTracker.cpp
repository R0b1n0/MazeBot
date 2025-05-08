#include "StatsTracker.h"

StatsTracker::StatsTracker() : m_iterationCount(0), m_calculationTime(0), m_trackTime(false)
{
	Pathfinder::OnTileDiscovery += [this](Vector2Int tile) { m_iterationCount++; };
	Pathfinder::OnSolutionFound += [this](std::vector<Vector2Int> solutionPath) { StoreResult(solutionPath); };
}

void StatsTracker::RefreshStats()
{
	m_calculationTime = 0;
	m_iterationCount = 0;
	m_trackTime = false;
}

void StatsTracker::TrackTime(float deltaTime)
{
	if (m_trackTime)
	{
		m_calculationTime += deltaTime;
	}
}

void StatsTracker::StartCounter()
{
	m_trackTime = true;
}

void StatsTracker::StoreResult(std::vector<Vector2Int> solutionPath)
{
	m_trackTime = false;
}
