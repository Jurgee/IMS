#include "Road.h"

Road::Road(int len) : len_(len) {
  this->cars_ = std::vector<std::optional<Car>>(len);
}
