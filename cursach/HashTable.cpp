#include "HashTable.h"
#include <fstream>

HashTable::HashTable(int size) {
    table = vector<LinkedList*>(size);
    for(int i=0; i < size; i++)
        table[i] = new LinkedList();
}

bool HashTable::insert(Data record) {
    unsigned hash = hash_function(record);
    return table[hash]->add(record);
}

bool HashTable::remove(Data record) {
    unsigned hash = hash_function(record);
    return table[hash]->remove(record);
}

int HashTable::find(Data record) {
    unsigned hash = hash_function(record);
    return table[hash]->find(record);
}

unsigned HashTable::hash_function(Data record) {
    size_t hash1 = hash<string>{}(record.code.get_string());
    size_t hash2 = hash<string>{}(record.date.toQString().toStdString());
    return (hash1 ^ hash2) % table.size();
}

vector<Data> HashTable::print() const {
    vector<Data> records;
    for(int i=0; i < table.size(); i++) {
        if(table[i]->head != nullptr) {
            table[i]->print(records);
        }
    }
    return records;
}

void HashTable::print(QPlainTextEdit *text_edit) const {
    for(int i=0; i < table.size(); i++) {
        text_edit->insertPlainText(QString::number(i) + ": ");
        if(table[i]->head != nullptr) {
            table[i]->print(text_edit);
            text_edit->insertPlainText("\n");
        }
        else
            text_edit->insertPlainText("NULL\n\n");
    }

}

void HashTable::write_file(ofstream &file) const {
    for(int i=0; i < table.size(); i++) {
        if(table[i]->head != nullptr) {
            Node* curr = table[i]->head;
            while (curr != nullptr) {
                file << curr->record.code.get_string() << " " << curr->record.nameDiscipline << " "
                << curr->record.fio.getFIO().toStdString() << " " << curr->record.date.toQString().toStdString() << endl;
                curr = curr->next;
            }
        }
    }
}
