#ifndef FIO_H
#define FIO_H

#include <istream>
#include <QString>

using namespace std;

class Fio
{
public:
    Fio() = default;
    Fio(QString _lastName, QString _firstName, QString _patronymic);

    [[nodiscard]] QString getFIO() const;
    void setFIO(QString _lastName, QString _firstName, QString _patronymic);

    QString getLastname() const;
    QString getFirstname() const;
    QString getPatronymic() const;

    bool operator<(const Fio &Fio) const;
    bool operator==(const Fio &Fio) const;
    bool operator>(const Fio &Fio) const;
    bool operator!=(const Fio &Fio) const;
    void operator = (const Fio &Fio);

private:
    QString lastName;
    QString firstName;
    QString patronymic;
};

#endif //FIO_H
