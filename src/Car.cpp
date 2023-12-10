#include "Car.h"
#include <iostream>

void Car::updateVelocity(int whereIam, int spaceInFront) {
  if(spaceInFront == 1)
  {
    this->velocity = 1;
    return;
  }
  // step 1/ acceleration
  this->velocity += this->a;
  if (this->velocity > this->V_max) {
    this->velocity = this->V_max;
  }
  // step 2/ validating space in front
  if (this->velocity + sg() > spaceInFront) {
    this->velocity =
        std::min(this->velocity, (int)std::ceil(spaceInFront / 2));
  }
  // step 3/ random slow down
  if (std::rand() % 100 < this->chanceToSlowDown) {
    this->velocity -= this->a;
  }
  // step 4/ ensuring non-negative velocity
  if (this->velocity < 0) {
    this->velocity = 0;
  }
  
}
