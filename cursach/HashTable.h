#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Data.h"
#include "LinkedList.h"
#include <QPlainTextEdit>


class HashTable {
public:
    HashTable() = default;
    HashTable(int size);

    bool insert(Data record);
    bool remove(Data record);
    int find(Data record);

    unsigned hash_function(Data record);

    vector<Data> print() const;
    void print(QPlainTextEdit *text_edit) const;
    void write_file(ofstream &file) const;

private:
    vector<LinkedList*>table;
};



#endif //HASHTABLE_H
