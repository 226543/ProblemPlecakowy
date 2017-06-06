#include <iostream>
#include "solver.hh"

using namespace std;

int main() {
  // inicjalizacja wielkością budżetu
  Solver problem(6);

  /* wybór trunków
  pierwszy argument - piwa
  drugi argument - wina
  trzeci argument - wysokoprocentowe
  */
  problem.preferences(true,true,true);

  // rozwiązanie problemu przy pomocy algorytmu zachałannego
  problem.approx();

  return 0;
}
