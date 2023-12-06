#include "Car.h"
#include "Road.h"
#include <optional>
#include <vector>

int main(int argc, char *argv[]) {
  Car carS(3, 1);
  Car car1(0, 1);
  Car car2(0, 1);
  Car car3(0, 1);
  Car car4(0, 1);

  std::vector<std::optional<Car>> lane = std::vector<std::optional<Car>>(20);

  lane[0] = carS;
  lane[10] = car1;
  lane[12] = car2;
  lane[13] = car3;
  lane[14] = car4;

  Road road;
  road.setCars(lane);

  for (int i = 0; i < 10; i++) {
    road.printRoad();
    road.step();
  }

  return 0;
}