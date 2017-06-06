#include <iostream>
#include "solver.hh"

void Solver::preferences(bool beer, bool vine, bool hardLiquor) {
  zabka.addItems(beer,vine,hardLiquor);
}

void Solver::approx() {
  double currentWeight;
  zabka.sortProductsByProfit();
  Backpack myBackpack(maxWeight);
  for(int i = 0; i < zabka.getSize(); ++i) {
    if (zabka[i].getWeight() + currentWeight <= maxWeight) {
      myBackpack.add( zabka[i] );
      currentWeight += zabka[i].getWeight();
    }
  }
  myBackpack.dispay();
}
