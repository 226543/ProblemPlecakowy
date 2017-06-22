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
    std::cout << i.getName() << " " << i.getWeight()/100.0 << " "
              << i.getValue() << std::endl;
    backpackWeight += i.getWeight();
    backpackValue += i.getValue();
  }

  std::cout << std::endl << "Wydana kwota: " << backpackWeight/100.0 << std::endl
            << "Ilość czystego alkoholu[ml]: " << backpackValue << std::endl;
}

Item& Backpack::operator[](unsigned int index) {
  if(index < element.size()) {
    return element[index];
  }
  else {
    std::cerr << "Wykroczono poza zakres!" << std::endl;
    exit(EXIT_FAILURE);
  }
}


void Backpack::cleanBackpack() {
  element.clear();
}

void Backpack::sortProductsByProfit() {
  std::sort(element.begin(), element.end());
  std::reverse(element.begin(), element.end());
}

void Backpack::addItems(bool beer, bool vine, bool hardLiquor) {
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

      add( Item(name,price,amountOfAlcohol,id) );
    }
    file.close();
  }

  if (vine) {
    file.open("/home/tomasz/ProblemPlecakowy/wina.csv");


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

       add( Item(name,price,amountOfAlcohol,id) );
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

      add( Item(name,price,amountOfAlcohol,id) );
    }
    file.close();
  }
}
