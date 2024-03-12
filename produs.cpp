#include "produs.h"
#include <istream>

Produs::Produs(int cod, string nume, int pret): cod(cod), nume(nume), pret(pret) {}

int Produs::getCod() const {
    return cod;
}

void Produs::setCod(int cod) {
    Produs::cod = cod;
}

const string &Produs::getNume() const {
    return nume;
}

void Produs::setNume(const string &nume) {
    Produs::nume = nume;
}

int Produs::getPret() const {
    return pret;
}

void Produs::setPret(int pret) {
    Produs::pret = pret;
}