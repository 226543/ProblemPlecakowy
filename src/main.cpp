#include <iostream>
#include "solver.hh"

using namespace std;

int main() {
  // inicjalizacja wielkością budżetu
  Solver problem(8);

  /* wybór trunków
  pierwszy argument - piwa
  drugi argument - wina
  trzeci argument - wysokoprocentowe
  */
  problem.preferences(true,true,true);

  // rozwiązanie problemu przy pomocy algorytmu zachałannego
  cout << "ALGORYTM ZACHŁANNY: \n\n";
  problem.approx();

  cout <<"\nPROGRAMOWANIE DYNAMICZNE: \n\n";
  problem.dynamicAlgoythm();

  //cout << "\n\nwart to: " << problem.dynamicAlgoythm() << endl << endl;

  return 0;
}
