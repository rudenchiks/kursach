#include "Fio.h"
#include <utility>

Fio::Fio(QString _lastName, QString _firstName, QString _patronymic) : lastName(std::move(_lastName)),
                                                                    firstName(std::move(_firstName)), patronymic(std::move(_patronymic)) {}

QString Fio::getFIO() const {
    return lastName + " " + firstName + " " + patronymic;
}

void Fio::setFIO(QString _lastName, QString _firstName, QString _patronymic) {
    lastName = std::move(_lastName);
    firstName = std::move(_firstName);
    patronymic = std::move(_patronymic);
}

QString Fio::getLastname() const {
    return lastName;
}

QString Fio::getFirstname() const {
    return firstName;
}

QString Fio::getPatronymic() const {
    return patronymic;
}

bool Fio::operator<(const Fio &Fio) const {
    if (lastName < Fio.lastName)
        return true;
    if (lastName == Fio.lastName)
    {
        if (firstName < Fio.firstName)
            return true;
        if (firstName == Fio.firstName)
        {
            if (patronymic < Fio.patronymic)
                return true;
        }
    }
    return false;
}

bool Fio::operator==(const Fio &Fio) const {
    return (lastName == Fio.lastName) && (firstName == Fio.firstName) && (patronymic == Fio.patronymic);
}

bool Fio::operator>(const Fio &Fio) const {
    if (*this < Fio || *this == Fio)
        return false;
    return true;
}

bool Fio::operator!=(const Fio &Fio) const {
    return !(*this == Fio);
}

void Fio::operator=(const Fio &Fio) {
    lastName = Fio.lastName;
    firstName = Fio.firstName;
    patronymic = Fio.patronymic;
}