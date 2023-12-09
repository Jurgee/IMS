#include "Car.h"
#include <iostream>

void Car::updateVelocity(int whereIam, int spaceInFront) {
  if (this->sg() >= spaceInFront) {
    this->velocity = std::ceil(spaceInFront / 2.0);
  } else {
    this->velocity += this->a;
  }
  this->velocity = this->velocity > this->V_max ? this->V_max : this->velocity;
  if (std::rand() % 100 < this->chanceToSlowDown) {
    this->velocity -= this->a;
  }
  this->velocity = this->velocity < 0 ? 0 : this->velocity;
}
