#pragma once

#include <iostream>
#include <optional>
#include <vector>

#include "Car.h"

class Road {
public:
  Road();

  int getLen() const { return cars_.size(); };
  std::vector<std::optional<Car>> getCars() const { return cars_; };
  void setCars(std::vector<std::optional<Car>> cars) { cars_ = cars; };

  void step();

  void printRoad();

private:
  std::vector<std::optional<Car>> cars_;
};
