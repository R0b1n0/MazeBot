#pragma once
#include "Pathfinder.h"

class StatsTracker
{
private:
	int m_iterationCount;
	float m_calculationTime;
	bool m_trackTime;

public : 
	StatsTracker();
	void RefreshStats();
	void StartCounter();
	void TrackTime(float deltaTime);
	int GetIteration() { return m_iterationCount; };
	float GetCalculationTime() { return m_calculationTime; };
	

private :
	void StoreResult(std::vector<Vector2Int> solutionPath);
};

