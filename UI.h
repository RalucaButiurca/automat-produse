#ifndef LAB9_UI_H
#define LAB9_UI_H

#include "Service.h"

class UI {
private:
    Service service;

    void printMenu();
    void adaugareProdus();
    void stergereProdus();
    void updateProdus();
    void afisareProduse();
    void cumparareProdus();
    void afisareColectie();

public:
    UI(Service& service) : service(service){
        //
    }

    void start();
};

#endif //LAB9_UI_H
