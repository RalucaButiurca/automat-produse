#ifndef LAB9_REPO_H
#define LAB9_REPO_H

#include <iostream>
#include <vector>
#include "Produs.h"

class Repo {
protected:
    vector<Produs> produse;

public:
    Repo();
    ~Repo() = default;
    virtual void addProdus(const Produs& prod);
    virtual vector<Produs> getAll();
    virtual bool updateProdus(int cod, const Produs& newProdus);
    virtual void deleteProdus(int cod);
    virtual int getSize();
    virtual Produs getProdusByCod(int cod);
};

#endif //LAB9_REPO_H
