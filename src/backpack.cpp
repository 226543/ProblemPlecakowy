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

  for (const auto& i : element ){
    std::cout << i.getName() << " " << i.getWeight() << " "
              << i.getValue() << std::endl;
    backpackWeight += i.getWeight();
    backpackValue += i.getValue();
  }

  std::cout << std::endl << "Wydana kwota: " << backpackWeight << std::endl
            << "Ilość czystego alkoholu[ml]: " << backpackValue << std::endl;
}

void Backpack::cleanBackpack() {
  element.clear();
}
