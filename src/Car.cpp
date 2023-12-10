#include "Car.h"
#include <iostream>

void Car::updateVelocity(int whereIam, int spaceInFront) {
  // step 1/ acceleration
  this->velocity = std::min(this->velocity + this->a, this->V_max);
  // step 2/ deceleration
  this->velocity = std::min(this->velocity, spaceInFront);
  // step 3/ randomization
  if (rand() % 100 < this->chanceToSlowDown) {
    this->velocity = std::max(this->velocity - 1, 0);
  }
}
