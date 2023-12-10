#include "Simulation.h"

void Simulation::run() {
  // initialize the lane
  std::vector<std::shared_ptr<Car>> lane =
      std::vector<std::shared_ptr<Car>>(parameters.roadLength);

  // initialize the cars in the lane
  // Calculate the step size between instances
  int stepSize = lane.size() / (parameters.carCount - 1);

  // Loop to distribute instances across the vector with the largest gap
  for (int i = 0; i < parameters.carCount; ++i) {
    int index = i * stepSize;
    lane[index] = std::make_shared<Car>(
        0, parameters.acceleration, 1, parameters.carMaxVelocity,
        parameters.levelOfAggressiveness, parameters.chanceToSlowDown);
  }

  // initialize the road with the lane
  Road road = Road(std::move(lane));

  // run the simulation
  for (int i = 0; i < parameters.iterationCount; i++) {
    road.printRoad();
    road.step();
  }
}
