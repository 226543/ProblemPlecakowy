#ifndef BACKPACK_HH
#define BACKPACK_HH
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "item.hh"


class Backpack {
  private:
  // tablica przechowująca przedmioty
  std::vector<Item> element;

  // pojemność plecaka
  int capacity;

  int size;

  public:
  Backpack() {
    capacity = 0;
  }

  ~Backpack() {}

  int getCapacity();
  void add(Item newItem);
  void dispay();
  void cleanBackpack();
  void sortProductsByProfit();
  void addItems(bool beer, bool vine, bool hardLiquor);
  Item& operator[] (unsigned int index);
};

#endif
