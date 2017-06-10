#ifndef SHOP_HH
#define SHOP_HH
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "item.hh"

class Shop {
  private:
  // tablica przechowująca przedmioty
  std::vector<Item> product;
  public:
  Shop() {}
  ~Shop() {}

  // dodawanie produktów do sklepu z plików
  void addItems(bool beer, bool vine, bool hardLiquor);

  // sortowanie elementów malejąco podwzględem opłacalności (dla algorytmu zachłannego)
  void sortProductsByProfit();

  // wyświetla dostępne elementy
  void dispay();
  int getSize();

  //nadaje indeksy kolejnym produktom
  void setOrderInShop();

  Item& operator[] (unsigned int index);
};

#endif
