#include "Road.h"

Road::Road() {}

int findFirstValueToLeft(const std::vector<std::optional<Car>> &array,
                         int currentIndex) {
  for (int i = currentIndex - 1; i >= 0; i--) {
    if (array[i].has_value()) {
      return i;
    }
  }
  return -1;
}

int findFirstValueToRight(const std::vector<std::optional<Car>> &array,
                          int currentIndex) {
  for (std::size_t i = currentIndex + 1; i < array.size(); i++) {
    if (array[i].has_value()) {
      return i;
    }
  }
  return -1;
}

void Road::step() {
  std::vector<std::optional<Car>> newCars =
      std::vector<std::optional<Car>>(this->getLen());

  for (int i = 0; i < this->getLen(); i++) {
    if (this->cars_[i].has_value()) {
      Car car = this->cars_[i].value();
      uint8_t newVelocity = car.getVelocity() + car.getAcceleration();
      if (newVelocity > car.getMaxVelocity()) {
        newVelocity = car.getMaxVelocity();
      }
      auto nextCarIndex = findFirstValueToRight(this->cars_, i);
      if (nextCarIndex != -1 && newVelocity > nextCarIndex - i) {
        newVelocity = nextCarIndex - i - 1;
      }
      car.setVelocity(newVelocity);
      newCars[(i + car.getVelocity()) % this->getLen()] = car;
    }
  }

  this->cars_ = newCars;
}

void Road::printRoad() {
  std::cout << "| ";
  for (auto car : this->cars_) {
    if (car.has_value()) {
      printf("%2d%2d%2d", car.value().getVelocity(),
             car.value().getAcceleration(), car.value().getLookahead());
    } else {
      printf("      ");
    }
    std::cout << " | ";
  }
  std::cout << std::endl;
}
