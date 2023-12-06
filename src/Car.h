#pragma once

#include <cstdint>

class Car {
public:
  Car(uint8_t velocity, uint8_t acceleration)
      : velocity_(velocity), acceleration_(acceleration) {}

  uint8_t getVelocity() const { return velocity_; };
  uint8_t getLookahead() const { return calculateLookahead(); };
  uint8_t getAcceleration() const { return acceleration_; };
  uint8_t getMaxVelocity() const { return MAX_VELOCITY; };

  void setVelocity(uint8_t velocity) { velocity_ = velocity; };
  void setAcceleration(uint8_t acceleration) { acceleration_ = acceleration; };

private:
  uint8_t velocity_;
  uint8_t acceleration_;
  uint8_t MAX_VELOCITY = 5;

  uint8_t calculateLookahead() const {
    uint8_t lookahead = 0;
    for (int i = 1; i <= velocity_; i++) {
      lookahead += i;
    }
    return lookahead + 1;
  };
};
