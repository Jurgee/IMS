#include "Car.h"
#include "Road.h"

#include <cstdlib>
#include <ctime>
#include <memory>
#include <vector>

#define ITERATION_COUNT 300
#define CAR_SPAWN_PROBABILITY 30
#define CAR_MAX_VELOCITY 4
#define ROAD_LENGTH 10

int main(int argc, char *argv[]) {
  std::srand(std::time(nullptr));

  std::vector<std::unique_ptr<Car>> lane =
      std::vector<std::unique_ptr<Car>>(ROAD_LENGTH);
  for (std::size_t i = 0; i < lane.size(); i++) {
    lane[i] = nullptr;
  }

  int count = 0;
  // for (std::size_t i = 0; i < lane.size(); i++) {
  //   if (std::rand() % 100 < CAR_SPAWN_PROBABILITY) {
  //     lane[i] = std::make_unique<Car>(std::rand() % CAR_MAX_VELOCITY);
  //     count++;
  //   }
  // }

  printf("Number of cars: %d\n", count);
  int a = 1;
  int vm = CAR_MAX_VELOCITY;

  lane[0] = std::make_unique<Car>(0, a, vm);
  // lane[2] = std::make_unique<Car>(1, a, vm);
  // lane[4] = std::make_unique<Car>(0, a, vm);
  // lane[5] = std::make_unique<Car>(1, a, vm);
  lane[9] = std::make_unique<Car>(2, a, vm);
  // lane[18] = std::make_unique<Car>(0, a, vm);

  // lane.emplace(lane.begin(), 5, a, vm);
  // lane.emplace(lane.begin() + 5, 4, a, vm);
  // lane.emplace(lane.begin() + 7, 3, a, vm);
  // lane.emplace(lane.begin() + 10, 2, a, vm);
  // lane.emplace(lane.begin() + 14, 4, a, vm);
  // lane.emplace(lane.begin() + 18, 3, a, vm);

  // lane.emplace(lane.begin(), 5, a, vm);
  // lane.emplace(lane.begin() + 5, 4, a, vm);
  // lane.emplace(lane.begin() + 7, 3, a, vm);
  // lane.emplace(lane.begin() + 10, 2, a, vm);
  // lane.emplace(lane.begin() + 14, 4, a, vm);
  // lane.emplace(lane.begin() + 18, 3, a, vm);

  Road road = Road(std::move(lane));


  for (int i = 0; i < ITERATION_COUNT; i++) {
    printf("%6d |", i);

    road.printRoad();
    road.step();
  }

  return 0;
}