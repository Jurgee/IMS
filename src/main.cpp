#include "Car.h"
#include "Road.h"
#include <cstdlib>
#include <ctime>
#include <optional>
#include <vector>

#define MAX_VELOCITY 5

int main(int argc, char *argv[]) {
  std::srand(std::time(nullptr));

  std::vector<std::optional<Car>> lane = std::vector<std::optional<Car>>(100);

  for (int i = 0; i < lane.size(); i++) {
    if (std::rand() % 2 == 0) {
      auto carsMaxVel = std::rand() % (MAX_VELOCITY - 2) + 3;
      lane[i] = Car(std::rand() % carsMaxVel, 2, carsMaxVel);
    }
  }

  Road road;
  road.setCars(lane);

  for (int i = 0; i < 30000; i++) {
    road.printRoad();
    road.step();
  }

  return 0;
}