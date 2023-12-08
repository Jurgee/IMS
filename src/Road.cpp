#include "Road.h"

#define PROBABILITY_TO_SLOW_DOWN 0.8

/**
 * @brief Count number of empty cells in front of the car
 *
 */
int countGap(const std::vector<std::optional<Car>> &array, int currentIndex) {
  int gap = 0;
  std::cout << "counting gap for car " << array[currentIndex].value().id
            << ": ";

  for (std::size_t i = (currentIndex + 1) % array.size();;
       i = (i + 1) % array.size()) {
    std::cout << i << " ";
    if (array[i] == std::nullopt) {
      gap++;
    } else {
      std::cout << std::endl;
      return gap;
    }
  }
}

void Road::step() {
  int length = cars.size();
  std::vector<std::optional<Car>> newCars(length);

  for (int i = 0; i < length; i++) {
    if (cars[i] != std::nullopt) {
      int spaceInFront = countGap(cars, i);
      std::cout << "Car " << cars[i].value().id
                << " velocity: " << cars[i].value().velocity
                << " space in front: " << spaceInFront << " | ";
      cars[i].value().updateVelocity(i, spaceInFront);
      int newPosition = (i + cars[i].value().velocity) % length;
      std::cout << "new position: " << newPosition
                << " new velocity: " << cars[i].value().velocity << std::endl;
        }
  }
}

void Road::printRoad() {
  for (std::size_t i = 0; i < cars.size(); i++) {
    if (!cars[i]) {
      std::cout << "|.";
    } else {
      std::cout << "|" << cars[i].value().id;
      // std::cout << "|" << cars[i].value().velocity;
    }
  }
  std::cout << std::endl;
}
