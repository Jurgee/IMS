#include "Road.h"

#define PROBABILITY_TO_SLOW_DOWN 0.8

Road::Road() {}

int countGap(const std::vector<std::optional<Car>> &array, int currentIndex) {
  int gap = 0;
  for (std::size_t i = currentIndex + 1;; i = (i + 1) % array.size()) {
    if (!array[i].has_value()) {
      gap++;
    } else {
      return gap;
    }
  }
}

void Road::step() {
  std::vector<std::optional<Car>> newCars =
      std::vector<std::optional<Car>>(cars.size());

  for (int i = 0; i < cars.size(); i++) {
  }

  this->cars = newCars;
}

void Road::printRoad() {
  for (auto car : this->cars) {
    if (car.has_value()) {
      printf("%1d", car.value().velocity);
    } else {
      std::cout << ".";
    }
  }
  std::cout << std::endl;
}
