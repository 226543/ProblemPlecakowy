#include <iostream>
#include <vector>
#include "solver.hh"

using namespace std;

void Solver::preferences(bool beer, bool vine, bool hardLiquor) {
  zabka.addItems(beer,vine,hardLiquor);
}

Backpack Solver::approx() {
  double currentWeight;
  zabka.sortProductsByProfit();
  Backpack myBackpack;
  for(int i = 0; i < zabka.getSize(); ++i) {
    if (zabka[i].getWeight() + currentWeight <= maxWeight) {
      myBackpack.add( zabka[i] );
      currentWeight += zabka[i].getWeight();
    }
  }
  return myBackpack;
}

double Solver::max(double val1, double val2)
{
  return (val1 > val2) ? val1 : val2;
}

void Solver::dynamicAlgorithm(std::vector<std::vector<double>> &matrix,
                             std::vector<std::vector<double>> &picks)
{
  zabka.setOrderInShop();

  int quantityOfItems = zabka.getSize();
  int weight = maxWeight;

  for(int i=1; i<=quantityOfItems; ++i) {
    for(int j=0; j<=weight; ++j) {
      if(zabka[i-1].getWeight() <= j) {
        matrix[i][j] = max(matrix[i-1][j],zabka[i-1].getValue() + matrix[i-1][j-zabka[i-1].getWeight()]);
        if(zabka[i-1].getValue()+matrix[i-1][j-zabka[i-1].getWeight()] > matrix[i-1][j]) {
          picks[i][j] = 1;
        }
        else {
          picks[i][j] = -1;
        }
      }
      else {
        picks[i][j] = -1;
        matrix[i][j] = matrix[i-1][j];
      }
    }
  }
}

Backpack Solver::setBackpack(std::vector<std::vector<double>> &picks)
{
  Backpack tempBackpack;

  int quantityOfItems = zabka.getSize();
  int weight = maxWeight;

  while(quantityOfItems > 0) {
    if(picks[quantityOfItems][weight] == 1) {
      for(int i=1;i<=quantityOfItems;++i) {
        if(quantityOfItems == zabka[i-1].getOrder()) {
          tempBackpack.add(zabka[i-1]);
        }
      }
      --quantityOfItems;
      weight -= zabka[quantityOfItems].getWeight();
    }
    else {
      quantityOfItems--;
    }
  }
  return tempBackpack;
}

Backpack Solver::DP() {
  Backpack result;
  int i = zabka.getSize();
  int j = maxWeight;

  std::vector<std::vector<double> > matrix(i+1, std::vector<double>(j));
  std::vector<std::vector<double>> picks (i+1, std::vector<double>(j));

  dynamicAlgorithm(matrix,picks);
  result = setBackpack(picks);
  result.sortProductsByProfit();
  return result;
}
