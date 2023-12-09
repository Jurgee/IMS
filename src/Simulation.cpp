#include "Simulation.h"

void Simulation::run() {
  // initialize the lane
  std::vector<std::shared_ptr<Car>> lane =
      std::vector<std::shared_ptr<Car>>(_parameters.roadLength);

  // initialize the cars in the lane
  // if there are more cars than the road can hold, the rest will be ignored
  int count = 0;
  for (int i = 0; count < _parameters.carCount && i < _parameters.roadLength;
       i++) {
    // the first fifth of the cars will start at max velocity and are scattered
    // evenly with save gaps
    if (count < _parameters.carCount / 5) {
      Car car(_parameters.carMaxVelocity, _parameters.acceleration,
              _parameters.carMaxVelocity, _parameters.levelOfAggressiveness,
              _parameters.chanceToSlowDown);
      lane[i] = std::make_shared<Car>(car);
      count++;
      i += car.velocity + car.sg();
    }
    // the rest will start as stuck at 0 in traffic jam
    else {
      Car car(0, _parameters.acceleration, _parameters.carMaxVelocity,
              _parameters.levelOfAggressiveness, _parameters.chanceToSlowDown);
      lane[i] = std::make_shared<Car>(car);
      count++;
    }
  }

  // initialize the road with the lane
  Road road = Road(std::move(lane));

  // run the simulation
  for (int i = 0; i < _parameters.iterationCount; i++) {
    road.printRoad();
    road.step();
  }
}
