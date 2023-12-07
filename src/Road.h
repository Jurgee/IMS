#pragma once

#include <iostream>
#include <optional>
#include <vector>

#include "Car.h"

class Road {
public:
  Road();

  void step();

  void printRoad();

  std::vector<std::optional<Car>> cars;




};
