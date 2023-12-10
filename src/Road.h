/*
* Project: IMS 2023/2024 CA in traffic
* Authors: Jiří Štípek (xstipe02) and Štefan Pekník (xpekni01)
*/

#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "Car.h"

/**
 * @brief Road class represents a road with cars
 *
 */
class Road {
public:
  Road(std::vector<std::shared_ptr<Car>> initRoadState)
      : cars(std::move(initRoadState)) {}

  void step();

  void printRoad();

private:
  std::vector<std::shared_ptr<Car>> cars;
};
