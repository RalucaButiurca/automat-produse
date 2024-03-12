#ifndef LAB12_DUBLAREEXCEPTION_H
#define LAB12_DUBLAREEXCEPTION_H

#include <string>

using namespace std;

class DublareException: public std::exception{
private:
    string message;
public:
    explicit DublareException(const char *msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif //LAB12_DUBLAREEXCEPTION_H
