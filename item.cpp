#include <item.hh>
#include <QMap>

Item::Item(std::string nName, double nWeight, double nValue, int nID) {
  name = nName;
  weight = nWeight;
  value = nValue;
  id = nID;
  setIcon();
}

std::string Item::getName()const {
  return name;
}

void Item::setName(std::string newName) {
  name = newName;
}

int Item::getWeight()const {
  return weight;
}

void Item::setWeight(int newWeight) {
  weight = newWeight;
}

double Item::getValue()const {
  return value;
}

void Item::setValue(double newValue) {
  value = newValue;
}

int Item::getOrder()const {
  return order;
}

void Item::setOrder(int newOrder) {
  order = newOrder;
}

int Item::getID() {
  return id;
}

QString Item::getPath()const {
  return path;
}

void Item::setPath(QString nPath) {
  path = nPath;
}

void Item::setIcon() {
    QMap<int,QString> map;
    QString temp;

    map[1] = ":/iresource/img/haras.jpg";
    map[2] = ":/iresource/img/perla.png";
    map[3] = ":/iresource/img/okocim.jpg";
    map[4] = ":/iresource/img/karpackie.jpg";
    map[5] = ":/iresource/img/brew.jpg";
    map[6] = ":/iresource/img/zywiec.png";
    map[7] = ":/iresource/img/namyslow.jpg";
    map[8] = ":/iresource/img/shandy.jpg";
    map[9] = ":/iresource/img/pinta.jpg";
    map[10] = ":/iresource/img/tescovalue.jpg";
    map[11] = ":/iresource/img/";
    map[12] = ":/iresource/img/";
    map[13] = ":/iresource/img/";
    map[14] = ":/iresource/img/";
    map[15] = ":/iresource/img/";
    map[16] = ":/iresource/img/";
    map[17] = ":/iresource/img/";
    map[18] = ":/iresource/img/";
    map[19] = ":/iresource/img/";
    map[20] = ":/iresource/img/";
    map[21] = ":/iresource/img/krupnik.jpg";
    map[22] = ":/iresource/img/soplicaSzlachetna.jpg";
    map[23] = ":/iresource/img/zubrowkaBiała.jpg";
    map[24] = ":/iresource/img/luksusowa.jpg";
    map[25] = ":/iresource/img/pantad.png";
    map[26] = ":/iresource/img/spiryt.jpg";
    map[27] = ":/iresource/img/bison.jpg";
    map[28] = ":/iresource/img/lubuska.jpg";
    map[29] = ":/iresource/img/smirnoff.jpg";
    map[30] = ":/iresource/img/zoladkowa.jpg";

    if(id <= 30) {
        setPath(map[getID()]);
    }
    else {
        setPath(":/iresource/img/brak.jpg");
    }

}
