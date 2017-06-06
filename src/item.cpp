#include <item.hh>

Item::Item(std::string nName, double nWeight, double nValue) {
  name = nName;
  weight = nWeight;
  value = nValue;
}

std::string Item::getName()const {
  return name;
}

void Item::setName(std::string newName) {
  name = newName;
}

double Item::getWeight()const {
  return weight;
}

void Item::setWeight(double newWeight) {
  weight = newWeight;
}

double Item::getValue()const {
  return value;
}

void Item::setValue(double newValue) {
  value = newValue;
}
