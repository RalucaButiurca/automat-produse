#ifndef LAB12_FILEEXCEPTION_H
#define LAB12_FILEEXCEPTION_H

#include <iostream>

class FileException: public std::exception {

public:
    const char * what() const noexcept override {
        return "Could not open file!";
    }
};

#endif //LAB12_FILEEXCEPTION_H
