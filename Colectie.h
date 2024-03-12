#ifndef LAB9_COLECTIE_H
#define LAB9_COLECTIE_H

#include <iostream>
#include <vector>
using namespace std;

class Colectie {
private:
    vector<int> elements;
    vector<int> occurrences;

public:
    Colectie();

    void add(int elem, int occElem);
    int getAt(int elem);
    vector<int> getAllElements();
    vector<int>getAllOccurrences();
    bool hasSufficientChange(int change);
    friend ostream& operator<<(ostream& os, Colectie& colectie) {
        for(int i = 0; i < colectie.elements.size(); i++)
            os << "mai sunt " << colectie.occurrences[i] << " bancnote de " << colectie.elements[i] << " lei" << endl;
        return os;
    }

};

#endif //LAB9_COLECTIE_H
