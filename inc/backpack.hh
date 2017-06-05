#ifndef ITEM_HH
#define ITEM_HH
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
    capacity = 0;
  }

  ~Backpack();

  int getCapacity();
  void add(Item newItem);
  void dispay();
  void cleanBackpack();
}

#endif
