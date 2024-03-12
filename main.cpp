#include <iostream>
#include "Teste.h"
#include "FileRepo.h"
#include "Service.h"
#include "UI.h"

using namespace std;

int main() {

    FileRepo filerepo("C:\\Users\\butiu\\CLionProjects\\lab12\\produse.txt");
    Service serv(filerepo);
    UI ui(serv);

    ui.start();

    return 0;
}
