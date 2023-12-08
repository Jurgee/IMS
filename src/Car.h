#pragma once

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <math.h>

class Car {
public:
  /**
   * @brief Construct a new Car object
   *
   * @param startVelocity initial velocity in cells per second, default 0
   * @param a acceleration in cells per second squared, default 1
   * @param V_max maximum velocity in cells per second, default 20
   * @param agr aggressiveness of the driver, default 0
   */
  Car(int startVelocity = 0, float a = 1, int V_max = 9, float agr = 0)
      : V_max(V_max), a(a), velocity(startVelocity), agr(agr) {}

  // maximum velocity in cells per second
  const int V_max;
  // acceleration in cells per second squared
  const float a;
  // additional security distance in cells
  int sg() const { return std::ceil((2 * velocity) / 3 - agr); }
  // current velocity in cells per second
  int velocity;
  // aggressiveness of the driver
  float agr;

  const int id = std::rand() % 10;

  void updateVelocity(int whereIam, int spaceInFront);

private:
};
