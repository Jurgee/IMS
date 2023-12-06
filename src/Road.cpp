#include "Road.h"

#define PROBABILITY_TO_SLOW_DOWN 0.5

Road::Road() {}

int findFirstValueToLeft(const std::vector<std::optional<Car>> &array,
                         int currentIndex)
{
  for (int i = currentIndex - 1; i >= 0; i--)
  {
    if (array[i].has_value())
    {
      return i;
    }
  }
  return -1;
}

int findFirstValueToRight(const std::vector<std::optional<Car>> &array,
                          int currentIndex)
{
  for (std::size_t i = currentIndex + 1;; i = (i + 1) % array.size())
  {
    if (array[i].has_value())
    {
      return i;
    }
  }
}

int countGap(const std::vector<std::optional<Car>> &array, int currentIndex)
{
  int gap = 0;
  for (std::size_t i = currentIndex + 1;; i = (i + 1) % array.size())
  {
    if (!array[i].has_value())
    {
      gap++;
    }
    else
    {
      return gap;
    }
  }
}

void Road::step()
{
  std::vector<std::optional<Car>> newCars =
      std::vector<std::optional<Car>>(this->getLen());

  for (int i = 0; i < this->getLen(); i++)
  {
    if (this->cars_[i].has_value())
    {
      Car car = this->cars_[i].value();

      // a/
      uint8_t newVelocity = car.getVelocity();
      if (car.getVelocity() < car.getMaxVelocity())
      {
        newVelocity = car.getVelocity() + car.getAcceleration();
      }

      // b/
      auto gap = countGap(this->cars_, i);
      if (newVelocity > gap)
      {
        newVelocity = gap;
      }

      // c/
      auto slowDown = std::rand() % 100 < PROBABILITY_TO_SLOW_DOWN * 100;
      if (slowDown && newVelocity > 0)
      {
        newVelocity--;
      }

      // d/
      car.setVelocity(newVelocity);
      newCars[(i + car.getVelocity()) % this->getLen()] = car;
    }
  }

  this->cars_ = newCars;
}

void Road::printRoad()
{
  for (auto car : this->cars_)
  {
    if (car.has_value())
    {
      printf("%1d", car.value().getVelocity());
      // printf("%2d%2d%2d", car.value().getVelocity(),
      //        car.value().getAcceleration(), car.value().getLookahead());
    }
    else
    {
      std::cout << " ";
      // printf("      ");
    }
  }
  std::cout << std::endl;
}
