#include "Simulation.h"

void Simulation::run() {
  // initialize the lane
  std::vector<std::shared_ptr<Car>> lane =
      std::vector<std::shared_ptr<Car>>(parameters.roadLength);

  // initialize the cars
  for (int i = 0; i < parameters.carCount; i++) {
    Car car(0, parameters.acceleration, parameters.carMaxVelocity,
            parameters.levelOfAggressiveness, parameters.chanceToSlowDown);
    lane[i] = std::make_shared<Car>(car);
  }

  // initialize the road with the lane
  Road road = Road(std::move(lane));

  // run the simulation
  for (int i = 0; i < parameters.iterationCount; i++) {
    road.printRoad();
    road.step();
  }
}
