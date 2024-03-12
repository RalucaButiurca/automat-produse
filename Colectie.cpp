#include "Colectie.h"

Colectie::Colectie() {
    add(10, 30);
    add(5, 20);
    add(1, 50);
}

void Colectie::add(int elem, int occElem) {
    int position = this->getAt(elem);

    if(position != -1) {
        int aparitii_elem = occurrences[position];
        aparitii_elem++;
        occurrences[position] = aparitii_elem;
    }
    else {
        elements.push_back(elem);
        occurrences.push_back(occElem);
    }
}

int Colectie::getAt(int elem) {
    int sizeElements = elements.size();
    for(int i = 0; i < sizeElements; i++)
        if(this->elements[i] == elem)
            return i;

    return -1;
}

vector<int> Colectie::getAllElements() {
    return this->elements;
}

vector<int> Colectie::getAllOccurrences() {
    return this->occurrences;
}

bool Colectie::hasSufficientChange(int change) {
    int copyChange = change;
    for(int i = 0; i < elements.size(); i++) {
        while(occurrences[i] > 0 && copyChange >= elements[i]) {
            occurrences[i]--;
            copyChange -= elements[i];
        }
    }
    return copyChange == 0;
}
