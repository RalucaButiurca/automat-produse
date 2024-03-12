#include "FileRepo.h"
#include "service.h"
#include "teste.h"
#include <cassert>

void test_fileRepo() {
    FileRepo filerepo("produse.txt");
    Produs p1(1, "Snickers", 3);
    Produs p2(2, "Mars", 4);
    Produs p3(3, "Bounty", 5);

    filerepo.addProdus(p1);
    filerepo.addProdus(p2);
    filerepo.addProdus(p3);

    Produs newP3(3, "bounty", 6);
    filerepo.updateProdus(3, newP3);

    filerepo.deleteProdus(1);

    vector<Produs> prod = filerepo.getAll();
    assert(prod.size() == 2);
    assert(prod[1].getNume() == "bounty");
    assert(prod[0].getNume() == "Mars");

}

void test_service() {
    FileRepo filerepo("produse.txt");
    Service serv(filerepo);

    serv.addProdusServ(1, "Snickers", 3);
    serv.addProdusServ(2, "Mars", 3);
    serv.addProdusServ(3, "Bounty", 3);

    serv.deleteProdusServ(1);
    serv.updateProdusByCodServ(2, "mars", 5);

    vector<Produs> prod = serv.getAllServ();

    assert(prod.size() == 2);
    assert(prod[0].getNume() == "mars");
    assert(prod[1].getNume() == "Bounty");

}