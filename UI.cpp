#include "UI.h"
#include <string>
#include <vector>
#include "Validator.h"

using namespace std;

void UI::printMenu() {
    cout << "1. Adauga un produs" << endl;
    cout << "2. Updateaza un produs" << endl;
    cout << "3. Sterge un produs" << endl;
    cout << "4. Cumpara un produs" << endl;
    cout << "a. Afiseaza toate produsele" << endl;
    cout << "c. Afiseaza bancnotele" << endl;
    cout << "x. Iesire" << endl;
}

void UI::adaugareProdus() {
    try {
        string cod, pret, nume;
        cout << "Introduceti codul:";
        cin >> cod;
        cout << "Introduceti numele:";
        cin >> nume;
        cout << "Introduceti pretul:";
        cin >> pret;

        int cod_, pret_;

        cod_ = Validator::validateCod(cod);
        pret_ = Validator::validatePret(pret);

        service.addProdusServ(cod_, nume, pret_);
    }
    catch (CodException &e) {
        cerr << endl << "Cod sau pret introduse gresit: " << e.what() << endl;
    }
}

void UI::stergereProdus() {
    int cod;
    cout << "Dati codul produsului de sters:";
    cin >> cod;
    service.deleteProdusServ(cod);
}

void UI::updateProdus() {
    int cod, pret;
    string nume;

    cout << "Introduceti codul produsului de actualizat:";
    cin >> cod;

    cout << "Introduceti noul nume al produsului:";
    cin >> nume;

    cout << "Introduceti noul pret al produsului:";
    cin >> pret;

    bool result = service.updateProdusByCodServ(cod, nume, pret);

    if (result) {
        cout << "Produsul a fost actualizat cu succes!" << endl;
    }
    else {
        cout << "Actualizarea produsului a esuat!" << endl;
    }
}

void UI::afisareProduse() {
    if(service.getSizeServ()) {
        vector<Produs> prod = service.getAllServ();
        for(auto& p : prod)
            cout << "Cod: " << p.getCod() << " Nume: " << p.getNume() << " Pret: " << p.getPret() << endl;
    }
    else
        cout << "Nu exista produse" << endl;
}

void UI::cumparareProdus() {
    int cod, sumInserted;
    cout << "Alegeti codul produsului dorit:";
    cin >> cod;
    cout << "Introduceti suma:";
    cin >> sumInserted;
    service.buyProdus(cod, sumInserted);
}

void UI::afisareColectie() {
    service.showColectie();
}

void UI::start() {
    while(true) {
        try {
            printMenu();
            cout << "Alegeti optiunea:";
            char opt;
            cin >> opt;

            if(opt == '1')
                adaugareProdus();
            else if(opt == '2')
                updateProdus();
            else if(opt == '3')
                stergereProdus();
            else if(opt == '4')
                cumparareProdus();
            else if(opt == 'a')
                afisareProduse();
            else if(opt == 'c')
                afisareColectie();
            else if(opt == 'x')
                break;
            else
                cout << "Optiune gresita, reincearca" << endl;
        }
        catch (std::exception &e) {
            cout << e.what() << endl;
        }
    }
}
