#pragma once

#include <iostream>
#include <optional>
#include <vector>

#include "Car.h"

class Road {
public:
  Road(std::vector<std::optional<Car>> initRoadState)
      : cars(std::move(initRoadState)) {}

  void step();

  void printRoad();

private:
  std::vector<std::optional<Car>> cars;
};
