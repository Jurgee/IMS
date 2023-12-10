#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <math.h>

#include "Car.h"

/**
 * @brief Road class represents a road with cars
 *
 */
class Road {
public:
  Road(std::vector<std::shared_ptr<Car>> initRoadState)
      : cars(std::move(initRoadState)) {}

  void step();

  void printRoad();

private:
  std::vector<std::shared_ptr<Car>> cars;
};
