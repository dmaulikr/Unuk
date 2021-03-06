#pragma once

#include "../Engine/Pathfinding.h"

class LevelGen;

class AStarTile {
public:
  AStarTile() {}
  AStarTile(LevelGen* level, int xArg, int yArg, bool passable) : _level(level), _passable(passable), x(xArg), y(yArg)  {}

  bool IsSameState(AStarTile& tile);
  bool IsGoal(AStarTile& tile);
  float GoalDistanceEstimate(AStarTile& goal);
  float GetCost(AStarTile& goal);
  bool GetSuccessors(AStarSearch<AStarTile>* search);

  int GetX() { return x * FAKE_SIZE; }
  int GetY() { return y * FAKE_SIZE; }

  static const int FAKE_SIZE = 32;

private:
  LevelGen* _level;
  bool _passable;
  int x;
  int y;
};
