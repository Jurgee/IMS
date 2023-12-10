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
  Car(int startVelocity) : velocity(startVelocity) {}

  Car(const Car &other) : Car(other.velocity) {}

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

  // maximum velocity in cells per second
  const int v_max = 20;
  // acceleration in cells per second squared
  const int a = 1;
  // deceleration in cells per second squared
  const int b = 2;
  const int v_fast = 19;
  const int t_safe = 3;
  const int g_add = 4;
  const int p_0 = 32;
  const int p_d = 11;
  const int v_slow = 5;
  const int l_veh = 5;

  // current velocity in cells per second
  int velocity;

private:
};
