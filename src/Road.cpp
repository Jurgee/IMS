/**
* Project: IMS 2023/2024 CA in traffic
* Authors: Jiří Štípek (xstipe02) and Štefan Pekník (xpekni01)
*/

#include "Road.h"
/**
 * @brief Count number of empty cells in front of the car
 *
 */
int countGap(const std::vector<std::shared_ptr<Car>> &array, int currentIndex) {
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
  std::vector<std::shared_ptr<Car>> newCars(length);

  for (int i = 0; i < length; i++) {
    if (cars[i] != nullptr) {
      int spaceInFront = countGap(cars, i);
      cars[i].get()->updateVelocity(i, spaceInFront);
      int newPosition = (i + cars[i].get()->getVelocity()) % length;
      newCars[newPosition] = cars[i];
    }
  }
  cars = std::move(newCars);
}

void Road::printRoad() {
  std::cout << "|";
  for (std::size_t i = 0; i < cars.size(); i++) {
    if (!cars[i]) {
      std::cout << " . |";
    } else {
      printf("%03d|", cars[i].get()->getVelocity());
    }
  }
  std::cout << std::endl;
}
