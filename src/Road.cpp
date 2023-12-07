#include "Road.h"

#define PROBABILITY_TO_SLOW_DOWN 0.8

/**
 * @brief Count number of empty cells in front of the car
 *
 */
int countGap(const std::vector<std::unique_ptr<Car>> &array, int currentIndex) {
  int gap = 0;
  for (std::size_t i = currentIndex + 1;; i = (i + 1) % array.size()) {
    if (array[i] == nullptr) {
      gap++;
    } else {
      return gap;
    }
  }
}

void Road::step() {
  int length = cars.size();
  std::vector<std::unique_ptr<Car>> newCars(length);

  for (int i = 0; i < length; i++) {
    if (cars[i] != nullptr) {
      int newPosition = cars[i]->calcNewPosition(i, countGap(cars, i)) % length;
      newCars[newPosition] = std::move(cars[i]);
    }
  }

  cars = std::move(newCars);
}

void Road::printRoad() {
  for (std::size_t i = 0; i < cars.size(); i++) {
    if (!cars[i]) {
      std::cout << ".";
    } else {
      std::cout << cars[i].get()->velocity;
    }
  }
  std::cout << std::endl;
}
