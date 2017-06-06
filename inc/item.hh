#ifndef ITEM_HH
#define ITEM_HH
#include <string>

class Item {
  private:
  // nazwa produktu
  std::string name;

  // cena produktu
  double weight;

  // zawartość alkoholu w mililitrach
  double value;

  public:
  Item();
  Item(std::string nName, double nWeight, double nValue);
  ~Item() {}

  std::string getName()const;
  void setName(std::string newName);

  double getWeight()const;
  void setWeight(double newWeight);

  double getValue()const;
  void setValue(double newValue);

  // przeciążenie potrzebne do sortowania
  inline bool operator < (const Item &rhs) const {
    return (value/weight) < (rhs.getValue()/rhs.getWeight());
  }
};

#endif
