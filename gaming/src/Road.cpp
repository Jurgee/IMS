#include "Road.h"

// TODO
int gamma(int v, int v1, int v2, int v_fast);
int delta(int l_veh, int v, int v1, int v2, int v_fast, int g_add);
int tau(int v, int v1, int v2, int v_fast, int b, int t_safe);
int tau_l(int v, int v1, int v2, int v_fast, int b, int t_safe);

/**
 * @brief Count number of empty cells in front of the car
 *
 */
int countGap(const std::vector<std::shared_ptr<Car>> &array, int currentIndex) {
  int gap = 0;
  for (std::size_t i = (currentIndex + 1) % array.size();;
       i = (i + 1) % array.size()) {
    if (array[i] == nullptr) {
      gap++;
    } else {
      return gap;
    }
  }
}

void Road::step() {
  int length = cars.size();
  std::vector<std::shared_ptr<Car>> newCars(length);

  for (int i = 0; i < length; i++) {
    if (cars[i] != nullptr) {
      // get current and 3 other cars infront
      std::vector<std::shared_ptr<Car>> current(0);
      for (int j = i; current.size() < 4; j++) {
        if (cars[i] != nullptr) {
          current.push_back(cars[i]);
        }
      }
      auto curr = current[0];
      auto curr1 = current[1];
      auto curr2 = current[2];
      auto curr3 = current[3];
      // find pos of car infront
      int x1 = i + countGap(cars, i) + 1;
      // step 1
      int v_s = 0;
      for (int c = 0; c < curr.get()->v_max; c++) {
        int delt =
            delta(c, curr.get()->velocity, curr1.get()->velocity,
                  curr2.get()->velocity, curr.get()->v_fast, curr.get()->g_add);
        int ta = tau(c, curr1.get()->velocity, curr2.get()->velocity,
                     curr.get()->v_fast, curr.get()->b, curr.get()->t_safe);
        int sum = 0;
        for (int l = 0; l < ta; l++) {
          sum += c - curr.get()->b * l;
        }
        int left = i + delt + sum;

        int tal = tau_l(curr1.get()->velocity, curr2.get()->velocity,
                        curr3.get()->velocity, curr1.get()->v_fast,
                        curr1.get()->b, curr1.get()->t_safe);
        int suml = 0;
        for (int l = 0; l < tal; l++) {
          suml += curr1.get()->velocity - curr1.get()->b * l;
        }
        int right = x1 + suml;

        if (left <= right) {
          v_s = std::max(v_s, c);
        } // else v_s = v_s
      }
      std::cout << "v_s: " << v_s;

      // step 2
      auto p = std::max(curr.get()->p_d,
                        curr.get()->p_0 - (curr.get()->p_0 - curr.get()->p_d) *
                                              curr.get()->velocity /
                                              curr.get()->v_slow);
      std::cout << " p: " << p;

      // step 3
      auto v_vlnka = std::min(
          std::min(curr.get()->v_max, curr.get()->velocity + curr.get()->a),
          std::max(std::max(0, curr.get()->velocity - curr.get()->b), v_s));
      std::cout << " ~v: " << v_vlnka;

      // step 4
      int v_dash = 0;
      if (std::rand() % 100 < p) {
        v_dash = std::max(std::max(0, curr.get()->velocity - curr.get()->b),
                          v_vlnka - curr.get()->a);
      } else {
        v_dash = std::max(std::max(0, curr.get()->velocity - curr.get()->b),
                          v_vlnka);
      }
      std::cout << " v': " << v_dash;

      // step 5
      curr.get()->velocity = v_dash;
      int newPos = i + v_dash;
      std::cout << " x': " << newPos << std::endl;

      // move
      newCars[newPos] = cars[i];
    }
  }
  cars = std::move(newCars);
}

void Road::printRoad() {
  std::cout << "|";
  for (std::size_t i = 0; i < cars.size(); i++) {
    if (cars[i] == nullptr) {
      std::cout << " . |";
    } else {
      printf("%03d|", cars[i].get()->velocity);
    }
  }
  std::cout << std::endl;
}

int gamma(int v, int v1, int v2, int v_fast) {
  if ((v <= v1 && v1 <= v2) || v2 >= v_fast)
    return 0;
  else
    return 1;
}

int delta(int l_veh, int v, int v1, int v2, int v_fast, int g_add) {
  return l_veh +
         gamma(v, v1, v2, v_fast) * std::max(0, std::min(g_add, v - g_add));
}

int tau(int v, int v1, int v2, int v_fast, int b, int t_safe) {
  int gam = gamma(v, v1, v2, v_fast);
  return gam * v / b + (1 - gam) * std::max(0, std::min(v / b, t_safe) - 1);
}

int tau_l(int v, int v1, int v2, int v_fast, int b, int t_safe) {
  int gam = gamma(v, v1, v2, v_fast);
  return gam * v / b + (1 - gam) * std::min(v / b, t_safe);
}