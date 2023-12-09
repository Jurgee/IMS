#pragma once

#include <cstdlib>
#include <ctime>
#include <memory>
#include <vector>

#include "Car.h"
#include "Road.h"

class Simulation {
public:
  struct SimulationParams {
    int iterationCount;
    int carCount;
    int carMaxVelocity;
    int roadLength;
    int acceleration;
    int levelOfAggressiveness;
    int chanceToSlowDown;
    bool debug;
  };

  Simulation(const SimulationParams &params) : _parameters(params) {
    if (_parameters.debug)
      std::srand(0);
    else
      std::srand(std::time(nullptr));
  }

  void run();

private:
  SimulationParams _parameters;
};
