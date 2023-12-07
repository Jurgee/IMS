#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "Car.h"

class Road {
public:
  Road(std::vector<std::unique_ptr<Car>> initRoadState)
      : cars(std::move(initRoadState)) {}

  void step();

  void printRoad();

private:
  std::vector<std::unique_ptr<Car>> cars;
};
