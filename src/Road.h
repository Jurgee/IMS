#pragma once

#include <optional>
#include <vector>

#include "Car.h"

class Road {
public:
  Road(int len);

  int getLen() const { return len_; };
  std::vector<std::optional<Car>> getCars() const { return cars_; };
  void setCars(std::vector<std::optional<Car>> cars) { cars_ = cars; };

private:
  int len_;
  std::vector<std::optional<Car>> cars_;
};
