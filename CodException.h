#ifndef LAB12_CODEXCEPTION_H
#define LAB12_CODEXCEPTION_H

#include <exception>
#include <string>

class CodException: public std::exception{
private:
    std::string message;
public:
    explicit CodException(const char *msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif //LAB12_CODEXCEPTION_H
