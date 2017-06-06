#include "shop.hh"

void Shop::addItems(bool beer, bool vine, bool hardLiquor) {
  std::string temp;
  std::string name;
  double price = 0;
  double volume = 0;          //objętość
  double alcoholByVolume = 0;    //procentowa zawartość alkoholu
  double amountOfAlcohol = 0;   // ilość alkoholu w mililitrach

  std::ifstream file;
  if (beer) {
    file.open("piwa.csv");

    if(!file.is_open()) {
      std::cerr << "ERROR: File Open\n";
      exit(EXIT_FAILURE);
    }
    // pobiera pierwszą linię z opisem kolumn
    std::getline(file, temp,'\n');

    while(std::getline(file,temp,',')) {
      name = temp;
      std::getline(file,temp, ',');
      price = std::stod(temp);
      std::getline(file, temp, ',');
      volume = std::stod(temp);
      std::getline(file, temp,'\n');
      alcoholByVolume = std::stod(temp);
      amountOfAlcohol = 10*volume*alcoholByVolume;  // przeliczanie ilości alkoholu na mililitry
		  product.push_back( Item(name,price,amountOfAlcohol) );
    }
    file.close();
  }

  if (vine) {
    file.open("wina.csv");

    if(!file.is_open()) {
      std::cerr << "ERROR: File Open\n";
      exit(EXIT_FAILURE);
    }

    std::getline(file, temp,'\n');

    while(std::getline(file,temp,',')) {
      name = temp;
      std::getline(file,temp, ',');
      price = std::stod(temp);
      std::getline(file, temp, ',');
      volume = std::stod(temp);
      std::getline(file, temp,'\n');
      alcoholByVolume = std::stod(temp);
      amountOfAlcohol = 10*volume*alcoholByVolume;
      product.push_back( Item(name,price,amountOfAlcohol) );
    }
    file.close();
  }

  if (hardLiquor) {
    file.open("wysokoprocentowe.csv");

    if(!file.is_open()) {
      std::cerr << "ERROR: File Open\n";
      exit(EXIT_FAILURE);
    }

    std::getline(file, temp,'\n');

    while(std::getline(file,temp,',')) {
      name = temp;
      std::getline(file,temp, ',');
      price = std::stod(temp);
      std::getline(file, temp, ',');
      volume = std::stod(temp);
      std::getline(file, temp,'\n');
      alcoholByVolume = std::stod(temp);
      amountOfAlcohol = 10*volume*alcoholByVolume;
      product.push_back( Item(name,price,amountOfAlcohol) );
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
    std::cout << i.getName() << " " << i.getWeight() << " "
              << i.getValue() << std::endl;
  }
}
