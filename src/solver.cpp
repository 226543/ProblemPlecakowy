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

int Solver::max(int val1, int val2)
{
  return (val1 > val2) ? val1 : val2;
}

void Solver::dynamicAlgoythm()
{
  zabka.setOrderInShop();

  int quantityOfItems = zabka.getSize();
  int weight = maxWeight;

  for(int i=1; i<=quantityOfItems; ++i)
  {
    for(int j=0; j<=weight; ++j)
    {
      if(zabka[i-1].getWeight() <= j)
      {
        matrix[i][j] = max(matrix[i-1][j],zabka[i-1].getValue() + matrix[i-1][j-zabka[i-1].getWeight()]);
        if(zabka[i-1].getValue()+matrix[i-1][j-zabka[i-1].getWeight()] > matrix[i-1][j])
        {
          picks[i][j] = 1;
        }
        else
        {
          picks[i][j] = -1;
        }
      }

      else {
        picks[i][j] = -1;
        matrix[i][j] = matrix[i-1][j];
      }
    }
  }
  setBackpack();
}

void Solver::setBackpack()
{
  Backpack tempBackpack(maxWeight);

  int quantityOfItems = zabka.getSize();
  int weight = maxWeight;

  while(quantityOfItems > 0)
  {
    if(picks[quantityOfItems][weight] == 1)
    {
      for(int i=1;i<=quantityOfItems;++i)
      {
        if(quantityOfItems == zabka[i-1].getOrder())
        {
          tempBackpack.add(zabka[i-1]);
        }
      }
      quantityOfItems--;
      weight -= zabka[quantityOfItems].getWeight();

    }
    else{
      quantityOfItems--;
    }
  }
  tempBackpack.dispay();
}
