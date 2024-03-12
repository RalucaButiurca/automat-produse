#ifndef LAB9_PRODUS_H
#define LAB9_PRODUS_H

#include <iostream>
using namespace std;

class Produs {
private:
    int cod;
    string nume;
    int pret;

public:
    Produs() = default;
    Produs(int cod, string nume, int pret);

    ~Produs() = default;

    int getCod() const;
    void setCod(int cod);
    const string &getNume() const;
    void setNume(const string &nume);
    int getPret() const;
    void setPret(int pret);

};

#endif //LAB9_PRODUS_H
