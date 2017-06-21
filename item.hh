#ifndef ITEM_HH
#define ITEM_HH
#include <string>
#include <QString>

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

  int id;

  QString path;

  public:
  Item(std::string nName, double nWeight, double nValue, int nID);
  ~Item() {}

  std::string getName()const;
  void setName(std::string newName);

  int getWeight()const;
  void setWeight(int newWeight);

  double getValue()const;
  void setValue(double newValue);

  int getOrder()const;
  void setOrder(int newOrder);

  int getID();

  // przeciążenie potrzebne do sortowania
  inline bool operator < (const Item &rhs) const {
    return (value/weight) < (rhs.getValue()/rhs.getWeight());
  }

  inline bool operator == (const Item &rhs) const {
    return name == rhs.getName();
  }

  QString getPath()const;
  void setPath(QString nPath);

  void setIcon();
};

#endif
