#ifndef LAB9_FILEREPO_H
#define LAB9_FILEREPO_H

#pragma once
#include "Repo.h"
#include <fstream>

class FileRepo : public Repo {
private:
    std::string fileName;

public:
    void loadFromFile();
    void saveToFile();
    FileRepo(const std::string& filename);
    ~FileRepo();

    void addProdus(const Produs& prod) override;
    void deleteProdus(int cod) override;
    bool updateProdus(int cod, const Produs& newProdus) override;
    vector<Produs> getAll() override;
    Produs getProdusByCod(int cod) override;
};


#endif //LAB9_FILEREPO_H
