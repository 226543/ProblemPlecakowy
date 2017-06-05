#include <iostream>
#include "backpack.hh"

int Backpack::getCapacity() {
  return capacity;
}

void Backpack::add(Item newItem) {
  element.push_back(newItem);
  ++capacity;
}

void Backpack::dispay() {
  float backpackWeight = 0;
  double backpackValue = 0;

  std::cout << "Nazwa produktu  Cena  Zawartość alkoholu [ml]" << std::endl;

  for(auto i = element.begin(); i != element.end(); ++i) {
    std::cout << i->getName() << " " << i->getPrice() << " "
              << i->getStrength() << std::endl;
    backpackWeight += i->getPrice();
    backpackValue += i->getStrength();
  }

  std::cout << std::endl << "Wydana kwota: " << backpackWeight << std::endl
            << "Ilość czystego alkoholu[ml]: " << backpackValue << std::endl;
}

void Backpack::cleanBackpack() {
  element.erase();
}
