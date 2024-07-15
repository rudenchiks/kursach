#include "Code.h"

Code::Code(short firstNum, short secondNum, short thridNum) {
    this->firstNum = firstNum;
    this->secondNum = secondNum;
    this->thridNum = thridNum;
}

std::string Code::get_string() const {
    string res = "";
    if(firstNum >= 10)
        res += to_string(firstNum) + ".";
    else
        res += "0" + to_string(firstNum)+".";

    if(secondNum >= 10)
        res += to_string(secondNum) + ".";
    else
        res += "0" + to_string(secondNum) + ".";

    if(thridNum >= 10)
        res += to_string(thridNum);
    else
        res += "0" + to_string(thridNum);
    return res;
}
