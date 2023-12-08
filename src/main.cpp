#include "Car.h"
#include "Road.h"

#include <cstdlib>
#include <ctime>
#include <memory>
#include <vector>

#define ITERATION_COUNT 20000
#define CAR_COUNT 30
#define CAR_MAX_VELOCITY 5
#define ROAD_LENGTH 130
#define ACCELERATION 1
#define LEVEL_OF_AGGRESSIVENESS 2

int main(int argc, char *argv[]) {
  std::srand(std::time(nullptr));

  std::vector<std::shared_ptr<Car>> lane =
      std::vector<std::shared_ptr<Car>>(ROAD_LENGTH);

  for (int i = 0; i < CAR_COUNT; i++) {
    if (i ) {
      lane[i] = std::make_shared<Car>(std::rand() % (CAR_MAX_VELOCITY - 2) + 3,
                                      ACCELERATION, CAR_MAX_VELOCITY,
                                      LEVEL_OF_AGGRESSIVENESS);
    }
  }

  int a = 1;
  int vm = CAR_MAX_VELOCITY;

  Road road = Road(std::move(lane));

  for (int i = 0; i < ITERATION_COUNT; i++) {
    printf("%6d |", i);

    road.printRoad();
    road.step();
  }

  return 0;
}