#include "FileRepo.h"
#include <fstream>
#include "Validator.h"
#include "FileException.h"

FileRepo::FileRepo(const string& fileName) : fileName(fileName) {
    loadFromFile();
}

void FileRepo::addProdus(const Produs& prod) {
    Repo::addProdus(prod);
    saveToFile();
}

bool FileRepo::updateProdus(int cod, const Produs& newProdus) {
    bool updated = Repo::updateProdus(cod, newProdus);
    if (updated) {
        saveToFile();
    }
    return updated;
}

void FileRepo::deleteProdus(int cod) {
    Repo::deleteProdus(cod);
    saveToFile();
}

void FileRepo::loadFromFile() {
    ifstream fileStream(fileName);
    if (!fileStream.is_open()) {
        throw FileException();
    }
    produse.clear();
    while (!fileStream.eof()) {
        int cod;
        string nume;
        int pret;

        while(fileStream >> cod >> nume >> pret) {
            try {
                Produs prod(cod, nume, pret);
                produse.push_back(prod);
            }
            catch(CodException &e) {
                cout << "Cod introdus gresit " << e.what() << "\n";
            }
        }
    }
    fileStream.close();
}

void FileRepo::saveToFile() {
    ofstream fileStream(fileName);
    for (const auto& prod : Repo::getAll()) {
        fileStream << prod.getCod() << " " << prod.getNume() << " " << prod.getPret() << endl;
    }
    fileStream.close();
}

vector<Produs> FileRepo::getAll() {
    loadFromFile();
    return produse;
}

FileRepo::~FileRepo() {
    saveToFile();
}

Produs FileRepo::getProdusByCod(int cod) {
    return Repo::getProdusByCod(cod);
}
