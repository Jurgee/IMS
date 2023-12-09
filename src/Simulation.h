#pragma once

#include <cstdlib>
#include <ctime>
#include <memory>
#include <vector>

#include "Car.h"
#include "Road.h"

/**
 * @brief Simulation class represents a simulation of a road with cars
 *
 */
class Simulation {
public:
  enum Type {
    TRAFFIC_JAM,
    NORMAL_TRAFFIC
  };

  /**
   * @brief Simulation parameters
   *
   */
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

  /**
   * @brief Construct a new Simulation object
   *
   * @param params simulation parameters
   */
  Simulation(const SimulationParams &params) : parameters(params) {
    if (parameters.debug)
      std::srand(1);
    else
      std::srand(std::time(nullptr));
  }

  /**
   * @brief Run the simulation
   *
   */
  void run();

private:
  SimulationParams parameters;
};
