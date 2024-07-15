#ifndef DATA_H
#define DATA_H
#include "Code.h"
#include "Date.h"
#include "Fio.h"


class Data {
public:
    Data() = default;
    Data(Fio fio, Code code, string discipline, Date date);



    Fio fio;
    Code code;
    string nameDiscipline;
    Date date;
};



#endif //DATA_H
