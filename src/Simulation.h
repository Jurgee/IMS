/**
* Project: IMS 2023/2024 CA in traffic
* Authors: Jiří Štípek (xstipe02) and Štefan Pekník (xpekni01)
*/

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
      std::srand(0);
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
