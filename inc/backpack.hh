#ifndef BACKPACK_HH
#define BACKPACK_HH
#include <iostream>
#include <vector>
#include "item.hh"

class Backpack {
  private:
  // tablica przechowująca przedmioty
  std::vector<Item> element;

  // pojemność plecaka
  int capacity;

  public:
  Backpack() {
    capacity = 15;
  }

  Backpack(unsigned int cap) {
    capacity = cap;
  }

  ~Backpack() {}

  int getCapacity();
  void add(Item newItem);
  void dispay();
  void cleanBackpack();
};

#endif
