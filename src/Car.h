#pragma once

#include <cstdint>

class Car {
public:
  Car(uint8_t velocity, uint8_t lookahead)
      : velocity_(velocity), lookahead_(lookahead){};

  uint8_t getVelocity() const { return velocity_; };
  uint8_t getLookahead() const { return lookahead_; };

private:
  uint8_t velocity_;
  uint8_t lookahead_;
};
