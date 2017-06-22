#include "shop.hh"
#include <QFile>
#include <iostream>
#include <QString>
#include <QMap>

void Shop::addItems(bool beer, bool vine, bool hardLiquor) {
  std::string temp;
  std::string name;

  int price = 0;
  double volume = 0;          //objętość
  double alcoholByVolume = 0;    //procentowa zawartość alkoholu
  double amountOfAlcohol = 0;   // ilość alkoholu w mililitrach
  int id = 0;

  std::ifstream file;
  std::setlocale(LC_ALL, "C"); // ustawienia regionalne (kropka,przecinek)
  // qt ustawia jako separator dziesietny przecinek

  if (beer) {
    file.open("/home/tomasz/ProblemPlecakowy/piwa.csv");

    if(!file.is_open()) {
      std::cerr << "ERROR: File Open\n";
      exit(EXIT_FAILURE);
    }

    std::getline(file, temp,'\n');

    while(std::getline(file,temp,',')) {
      name = temp;

      std::getline(file,temp, ',');
      price = 100*std::stod(temp);

      std::getline(file, temp, ',');
      volume = std::stod(temp);

      std::getline(file, temp, ',');
      alcoholByVolume = std::stod(temp);
      amountOfAlcohol = 10*volume*alcoholByVolume;  // przeliczanie ilości alkoholu na mililitry

      std::getline(file, temp,'\n');
      id = std::stoi(temp);

      product.push_back( Item(name,price,amountOfAlcohol,id) );
    }
    file.close();
  }

  if (vine) {
    file.open("/home/tomasz/ProblemPlecakowy/wina.csv");

    //order =0;

    if(!file.is_open()) {
      std::cerr << "ERROR: File Open\n";
      exit(EXIT_FAILURE);
    }

    std::getline(file, temp,'\n');

    while(std::getline(file,temp,',')) {
        name = temp;

        std::getline(file,temp, ',');
        price = 100*std::stod(temp);

        std::getline(file, temp, ',');
        volume = std::stod(temp);

        std::getline(file, temp, ',');
        alcoholByVolume = std::stod(temp);
        amountOfAlcohol = 10*volume*alcoholByVolume;  // przeliczanie ilości alkoholu na mililitry

        std::getline(file, temp,'\n');
        id = std::stoi(temp);

        product.push_back( Item(name,price,amountOfAlcohol,id) );
      }
      file.close();
  }

  if (hardLiquor) {
    file.open("/home/tomasz/ProblemPlecakowy/wysokoprocentowe.csv");


    if(!file.is_open()) {
      std::cerr << "ERROR: File Open\n";
      exit(EXIT_FAILURE);
    }

    std::getline(file, temp,'\n');

    while(std::getline(file,temp,',')) {
        name = temp;

        std::getline(file,temp, ',');
        price = 100*std::stod(temp);

        std::getline(file, temp, ',');
        volume = std::stod(temp);

        std::getline(file, temp, ',');
        alcoholByVolume = std::stod(temp);
        amountOfAlcohol = 10*volume*alcoholByVolume;  // przeliczanie ilości alkoholu na mililitry

        std::getline(file, temp,'\n');
        id = std::stoi(temp);

        product.push_back( Item(name,price,amountOfAlcohol,id) );
      }
      file.close();
  }
}

int Shop::getSize() {
  return product.size();
}

Item& Shop::operator[](unsigned int index) {
  if(index < product.size()) {
    return product[index];
  }
  else {
      std::cerr << "Wykroczono poza zakres!" << std::endl;
      exit(EXIT_FAILURE);
    }
}

void Shop::sortProductsByProfit() {
  std::sort(product.begin(), product.end());
  std::reverse(product.begin(), product.end());
}

void Shop::dispay() {
  std::cout << "Nazwa produktu  Cena  Zawartość alkoholu [ml]" << std::endl;

  for (const auto& i : product ){
    std::cout << i.getName() << " " << i.getWeight()/100.0 << " "
              << i.getValue() << std::endl;
  }
}

void Shop::setOrderInShop()
{
  int tmp = 1;
  for ( auto& i : product ){
    i.setOrder(tmp);
    ++tmp;
  }
}


