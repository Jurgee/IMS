#include "Car.h"
#include "Road.h"

#include <cstdlib>
#include <ctime>
#include <memory>
#include <vector>

#define ITERATION_COUNT 30000
#define CAR_SPAWN_PROBABILITY 30

int main(int argc, char *argv[]) {
  std::srand(std::time(nullptr));

  std::vector<std::unique_ptr<Car>> lane =
      std::vector<std::unique_ptr<Car>>(100);

  int count = 0;
  for (std::size_t i = 0; i < lane.size(); i++) {
    if (std::rand() % 100 < 30) {
      lane[i] = std::make_unique<Car>();
      count++;
    }
  }

  printf("Number of cars: %d\n", count);

  Road road = Road(std::move(lane));

  for (int i = 0; i < ITERATION_COUNT; i++) {
    road.printRoad();
    road.step();
  }

  return 0;
}