#include <item.hh>

std::string Item::getName()const {
  return name;
}

void Item::setName(std::string newName) {
  name = newName;
}

float Item::getPrice()const {
  return price;
}

void Item::setPrice(float newPrice) {
  price = newPrice;
}

double Item::getStrength()const {
  return strength;
}

void Item::setStrength(double newStrength) {
  strength = newStrength;
}
