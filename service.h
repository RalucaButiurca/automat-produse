#ifndef LAB9_SERVICE_H
#define LAB9_SERVICE_H

#include "Repo.h"
#include "FileRepo.h"
#include "Colectie.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Service {
private:
    FileRepo& filerepo;
    Colectie colectie;
public:
    Service(FileRepo& filerepo) : filerepo(filerepo){}

    void addProdusServ(int cod, const string& nume, int pret);
    vector<Produs> getAllServ();
    bool updateProdusByCodServ(int cod, const std::string& nume, int pret);
    void deleteProdusServ(int cod);
    int getSizeServ();
    Produs getProdusByCodServ(int cod);
    bool buyProdus(int cod, int sumInserted);
    void showColectie();
};


#endif //LAB9_SERVICE_H
