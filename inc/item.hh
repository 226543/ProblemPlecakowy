#ifndef ITEM_HH
#define ITEM_HH
#include <string>

class Item {
  private:
  // nazwa produktu
  std::string name;

  // cena produktu
  float price;

  // zawartość alkoholu w mililitrach
  double strength;

  public:
  Item();
  ~Item();

  std::string getName()const;
  void setName(std::string newName);

  float getPrice()const;
  void setPrice(float newPrice);

  double getStrength()const;
  void setStrength(double newStrength);
};

#endif
