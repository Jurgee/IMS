#include "Car.h"
#include "Road.h"

#include <cstdlib>
#include <ctime>
#include <optional>
#include <vector>

#define ITERATION_COUNT 30000
#define CAR_SPAWN_PROBABILITY 30

int main(int argc, char *argv[]) {
  std::srand(std::time(nullptr));

  std::vector<std::optional<Car>> lane = std::vector<std::optional<Car>>(20);

  // for (std::size_t i = 0; i < lane.size(); i++) {
  //   if (std::rand() % 100 < 30) {
  //     lane[i] = std::make_unique<Car>();
  //     count++;
  //   }
  // }

  int a = 1;
  int vm = 5;

  lane.emplace(lane.begin(), 5, a, vm);
  lane.emplace(lane.begin() + 5, 4, a, vm);
  lane.emplace(lane.begin() + 7, 3, a, vm);
  lane.emplace(lane.begin() + 10, 2, a, vm);
  lane.emplace(lane.begin() + 14, 4, a, vm);
  lane.emplace(lane.begin() + 18, 3, a, vm);

  Road road = Road(lane);

  for (int i = 0; i < ITERATION_COUNT; i++) {
    road.printRoad();
    road.step();
  }

  return 0;
}