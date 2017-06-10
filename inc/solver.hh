#ifndef SOLVER_HH
#define SOLVER_HH
#include "shop.hh"
#include "item.hh"
#include "backpack.hh"

class Solver {
  private:
  Shop zabka;
  int maxWeight;

  int matrix[100][100];
  int picks[100][100];

  public:
  Solver() {
    maxWeight = 10;
  }
  Solver(unsigned int weight) {
    maxWeight = weight;
  }

  void preferences(bool beer, bool vine, bool hardLiquor);
  void approx();

  void dynamicAlgoythm();
  void setBackpack();
  
  int max(int val1, int val2);


};
#endif
