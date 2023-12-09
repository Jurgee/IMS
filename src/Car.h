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
   * @param startVelocity initial velocity in cells per second
   * @param a acceleration in cells per second squared
   * @param V_max maximum velocity in cells per second
   * @param agr aggressiveness of the driver
   */
  Car(int startVelocity, int a, int V_max, int agr, int chanceToSlowDown)
      : V_max(V_max), a(a), velocity(startVelocity), agr(agr),
        chanceToSlowDown(chanceToSlowDown) {}

  Car(const Car &other)
      : Car(other.velocity, other.a, other.V_max, other.agr,
            other.chanceToSlowDown) {}

  // maximum velocity in cells per second
  const int V_max;
  // acceleration in cells per second squared
  const int a;
  // additional security distance in cells
  int sg() const {
    int sg = std::ceil((2 * velocity) / 3 - agr);
    return sg > 0 ? sg : 0;
  }
  // current velocity in cells per second
  int velocity;
  // aggressiveness of the driver
  int agr;

  int chanceToSlowDown;

  void updateVelocity(int whereIam, int spaceInFront);

private:
};
