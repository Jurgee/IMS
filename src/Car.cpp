#include "Car.h"

void Car::updateVelocity(int whereIam, int spaceInFront) {
  this->velocity += this->a;
  if (this->velocity > this->V_max) {
    this->velocity = this->V_max;
  }
  if (this->velocity + sg() > spaceInFront) {
    this->velocity =
        std::min(this->velocity, (int)std::ceil(spaceInFront - sg() / 2));
  }
  if (this->velocity < 0) {
    this->velocity = 0;
  }
}
