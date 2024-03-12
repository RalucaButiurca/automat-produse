#include "Repo.h"
#include "DublareException.h"

Repo::Repo() = default;

void Repo::addProdus(const Produs& prod) {
    /*for(auto &produss: produse) {
        if (produss.getCod() == prod.getCod()) {
            throw DublareException("Cod deja existent");
        }
    }*/
    produse.push_back(prod);
}

vector<Produs> Repo::getAll() {
    return this->produse;
}

void Repo::deleteProdus(int cod) {
    for(auto it = produse.begin(); it != produse.end();) {
        if (it->getCod() == cod)
            it = produse.erase(it);
        else
            ++it;
    }
}

bool Repo::updateProdus(int cod, const Produs& newProdus) {
    for(auto& p : produse) {
        if(p.getCod() == cod) {
            p.setNume(newProdus.getNume());
            p.setPret(newProdus.getPret());
            return true;
        }
    }
    return false;
}

int Repo::getSize() {
    return this->produse.size();
}

Produs Repo::getProdusByCod(int cod) {
    for(const auto& p : produse) {
        if(p.getCod() == cod)
            return p;
    }
    return Produs(-1, "", -1);
}