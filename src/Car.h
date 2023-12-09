#pragma once

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <math.h>

/**
 * @brief Car class represents a car on the road
 *
 */
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

  /**
   * @brief Updates the velocity of the car
   *
   * @param whereIam position of the car on the road
   * @param spaceInFront space in front of the car in cells
   */
  void updateVelocity(int whereIam, int spaceInFront);

  /**
   * @brief Get the Velocity of the car
   *
   * @return int velocity
   */
  int getVelocity() const { return velocity; }

  /**
   * @brief Get the Acceleration of the car
   *
   * @return int acceleration
   */
  int getAcceleration() const { return a; }

  // additional security distance in cells
  /**
   * @brief Get the Safe Gap of the car:
   * safe gap = (2 * velocity) / 3  - aggressiveness
   *
   * @return int safe gap
   */
  int sg() const { // TODO agr
    int sg = std::ceil(2 * velocity - agr);
    return sg > 0 ? sg : 0;
  }

private:
  // maximum velocity in cells per second
  const int V_max;
  // acceleration in cells per second squared
  const int a;
  // current velocity in cells per second
  int velocity;
  // aggressiveness of the driver
  int agr;
  // chance to slow down in percent
  int chanceToSlowDown;
};
