#ifndef SOLVER_HH
#define SOLVER_HH
#include <vector>
#include "shop.hh"
#include "item.hh"
#include "backpack.hh"


class Solver {
  private:
  Shop zabka;
  double maxWeight;

  public:
  Solver() {
    maxWeight = 10;
  }
  Solver(double weight) {
    maxWeight = weight;
  }

  void preferences(bool beer, bool vine, bool hardLiquor);
  Backpack approx();

  Backpack DP();
  void dynamicAlgorithm(std::vector<std::vector<double>> &matrix,
                       std::vector<std::vector<double>> &picks);
  Backpack setBackpack(std::vector<std::vector<double>> &picks);

  double max(double val1, double val2);


};
#endif
