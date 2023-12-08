#include "Road.h"

#define PROBABILITY_TO_SLOW_DOWN 0.8

/**
 * @brief Count number of empty cells in front of the car
 *
 */
int countGap(const std::vector<std::unique_ptr<Car>> &array, int currentIndex) {
  int gap = 0;
  for (std::size_t i = (currentIndex + 1) % array.size();;
       i = (i + 1) % array.size()) {
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
      int spaceInFront = countGap(cars, i);
      cars[i].get()->updateVelocity(i, spaceInFront);
      int newPosition = (i + cars[i].get()->velocity) % length;
      newCars.emplace(newCars.begin() + newPosition, cars[i].get());
    }
  }

  cars = newCars;
}

void Road::printRoad() {
  for (std::size_t i = 0; i < cars.size(); i++) {
    if (!cars[i]) {
      std::cout << "|.";
    } else {
      std::cout << "|" << cars[i].get()->id;
      // std::cout << "|" << cars[i].get()->velocity;
    }
  }
  std::cout << std::endl;
}
