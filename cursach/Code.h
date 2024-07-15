#pragma once
#ifndef CODE_H
#define CODE_H
#include <string>
using namespace std;

class Code {
public:
    Code() = default;
    Code(short firstNum, short secondNum, short thridNum);

    std::string get_string() const;

    bool operator==(const Code & code) const {
        return firstNum == code.firstNum && secondNum == code.secondNum && thridNum == code.thridNum;
    }

    short firstNum;
    short secondNum;
    short thridNum;
};



#endif //CODE_H
