#ifndef LAB12_VALIDATOR_H
#define LAB12_VALIDATOR_H

#include <string>
#include <stdexcept>
#include <iostream>
#include "CodException.h"

class Validator {
public:
    static int validateCod(const std::string &cod) {
        if (!isdigit(cod[0]))
            throw CodException("Codul introdus nu este un numar.");
        else
            return stoi(cod);
    }
    static int validatePret(const std::string &cod) {
        if (!isdigit(cod[0]))
            throw CodException("Pretul introdus nu este un numar.");
        else
            return stoi(cod);
    }
};

#endif //LAB12_VALIDATOR_H
