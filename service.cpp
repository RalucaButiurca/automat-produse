#include "Service.h"

void Service::addProdusServ(int cod, const string &nume, int pret) {
    filerepo.addProdus(Produs(cod, nume, pret));
}

vector<Produs> Service::getAllServ() {
    return filerepo.getAll();
}

bool Service::updateProdusByCodServ(int cod, const string &nume, int pret) {
    Produs newProdus(cod, nume, pret);
    return filerepo.updateProdus(cod, newProdus);
}

void Service::deleteProdusServ(int cod) {
    filerepo.deleteProdus(cod);
}

int Service::getSizeServ() {
    return filerepo.getSize();
}

Produs Service::getProdusByCodServ(int cod) {
    return filerepo.getProdusByCod(cod);
}

bool Service::buyProdus(int cod, int sumInserted) {
    Produs prodToBuy = getProdusByCodServ(cod);

    int prodPrice = prodToBuy.getPret();
    int rest = sumInserted - prodPrice;
    if(!colectie.hasSufficientChange(rest)) {
        cout << "Nu se poate da rest" << endl;
        return false;
    }
    else {
        cout << "Produs cumparat cu succes. Rest: " << rest << endl;
        filerepo.deleteProdus(cod);
        return true;
    }
}

void Service::showColectie() {
    cout << colectie;
}