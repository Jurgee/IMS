#include "Road.h"

#define PROBABILITY_TO_SLOW_DOWN 0.8

/**
 * @brief Count number of empty cells in front of the car
 *
 */
int countGap(const std::vector<std::unique_ptr<Car>> &array, int currentIndex) {
  int gap = 0;
  std::cout << "counting gap for car " << array[currentIndex].get()->id << ": ";

  for (std::size_t i = (currentIndex + 1) % array.size();;
       i = (i + 1) % array.size()) {
    std::cout << i << " ";
    if (array[i] == nullptr) {
      gap++;
    } else {
      std::cout << std::endl;
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
      std::cout << "Car " << cars[i].get()->id
                << " velocity: " << cars[i].get()->velocity
                << " space in front: " << spaceInFront << " | ";
      cars[i].get()->updateVelocity(i, spaceInFront);
      int newPosition = (i + cars[i].get()->velocity) % length;
      std::cout << "new position: " << newPosition
                << " new velocity: " << cars[i].get()->velocity << std::endl;
      newCars[newPosition] = std::move(cars[i]); // TODO nemovovat ale copy
    }
  }
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
