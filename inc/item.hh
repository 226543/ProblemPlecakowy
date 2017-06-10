#ifndef ITEM_HH
#define ITEM_HH
#include <string>

class Item {
  private:
  // nazwa produktu
  std::string name;

  // cena produktu
  int weight;

  // zawartość alkoholu w mililitrach
  double value;

  //l. produktów
  int order;

  public:
  Item();
  Item(std::string nName, double nWeight, double nValue);
  ~Item() {}

  std::string getName()const;
  void setName(std::string newName);

  int getWeight()const;
  void setWeight(double newWeight);

  double getValue()const;
  void setValue(double newValue);

  int getOrder() const;
  void setOrder(int newOrder);

  // przeciążenie potrzebne do sortowania
  inline bool operator < (const Item &rhs) const {
    return (value/weight) < (rhs.getValue()/rhs.getWeight());
  }
};

#endif
