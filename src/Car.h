#pragma once

#include <cstdint>
#include <cstdlib>

class Car {
public:
  /**
   * @brief Construct a new Car object
   *
   * @param startVelocity initial velocity in cells per second
   * @param a acceleration in cells per second squared
   * @param b deceleration in cells per second squared
   * @param V_max maximum velocity in cells per second
   * @param t_safe maximal time in which a car evaluates its safety to
   * optimistic state
   * @param g_add additional security distance in cells
   * @param p_0 probability to slow down when velocity is low (0)
   * @param p probability to slow down when car is moving
   * @param V_slow velocity slightly above 0 in cells per second
   */
  Car(int startVelocity, float a = 1, float b = 2, int V_max = 20,
      int t_safe = 3, int g_add = 4, float p_0 = 0.32, float p = 0.11,
      int V_slow = 5)
      : velocity(startVelocity), a(a), b(b), V_max(V_max), t_safe(t_safe),
        g_add(g_add), p_0(p_0), p(p), V_slow(V_slow) {}

  // maximum velocity in cells per second
  const int V_max;
  // acceleration in cells per second squared
  const float a;
  // deceleration in cells per second squared
  const float b;
  // velocitity slightly below the maximum velocity in cells per second
  const int V_fast = V_max - 1;
  // maximal time in which a car evaluates its safety to optimistic state
  const int t_safe;
  // additional security distance in cells
  const int g_add;
  // probability to slow down when velocity is low (0)
  const float p_0;
  // probability to slow down when car is moving
  const float p;
  // velocity slightly above 0 in cells per second
  const int V_slow;

  // current velocity in cells per second
  int velocity = 0;

  // step 5
  int calcNewPosition(int whereIam);

private:
  // step 1

  /**
   * @brief Determines the safe velocity for the current car
   *
   * @param whereIam current position of the car
   * @param l car in front of me
   * @param lPosition position of the car in front of me
   * @param lPlus1 car in front of the car l, needed for gamma
   * @param lPlus2 car infront of car lPlus1, needed for gamma
   *
   * @return int safe velocity in cells per second
   */
  int determineSafeVelocity(int whereIam, Car l, int lPosition, Car lPlus1,
                            Car lPlus2);

  // step 2
  /**
   * @brief Calculates the probability to slow down
   *
   * @return float probability to slow down
   */
  float calcRandomizationProbability();

  // step 3
  /**
   * @brief Updates the velocity of the car
   */
  void updateVelocity();

  // step 4
  /**
   * @brief Applies the randomization to the velocity
   */
  void applyRandomization();

  // utils
  int calcGamma(int v_l, int v_lPlus1);
  int calcDelta(Car carInFront);
  int calcTauForMe(Car carInFront);
};
