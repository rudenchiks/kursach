#ifndef LIST_H
#define LIST_H
#include "Data.h"
#include <QPlainTextEdit>


class Node {
public:
    Node() = default;
    Node(Data record) {
        this->record = record;
    }

    Node *prev;
    Node *next;
    Data record;
};


class LinkedList {
public:
    LinkedList() = default;
    LinkedList(Node *node) {
        head = node;
    }

    bool add(Data record) {
        if(head == nullptr) {
            head = new Node(record);
            head->next = nullptr;
            head->prev = nullptr;
            return true;
        }

        Node* curr = head;
        while (curr != nullptr) {
            if(curr->record.code == record.code && curr->record.date == record.date) {
                return false;
            }
            curr = curr->next;
        }

        Node* newNode = new Node(record);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        head->prev = nullptr;
        return true;
    }

    bool remove(Data record) {
        Node* curr = head;
        while (curr != nullptr) {
            if(curr->record.code == record.code && curr->record.date == record.date && curr->record.nameDiscipline == record.nameDiscipline
                && curr->record.fio == record.fio) {
                if(curr == head) {
                    head = head->next;
                    delete curr;
                }
                else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    delete curr;
                }
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    int find(Data record) {
        Node* curr = head;
        int cnt = 0;
        while (curr != nullptr) {
            cnt++;
            if(curr->record.code == record.code && curr->record.date == record.date && curr->record.nameDiscipline == record.nameDiscipline)
                return true;
            curr = curr->next;
        }
        return -1;
    }

    void print(vector<Data>&records) {
        Node *curr = head;
        while (curr != nullptr) {
            records.push_back(curr->record);
            curr = curr->next;
        }
    }

    void print(QPlainTextEdit *text_edit) {
        Node *curr = head;
        text_edit->insertPlainText("( ");
        while (curr != nullptr) {
            if(curr->next == nullptr)
                text_edit->insertPlainText(QString::fromStdString(curr->record.code.get_string()) + " " + QString::fromStdString(curr->record.nameDiscipline)+ " " + curr->record.fio.getFIO()+ " " + curr->record.date.toQString() + " ");
            else
                text_edit->insertPlainText(QString::fromStdString(curr->record.code.get_string()) + " " + QString::fromStdString(curr->record.nameDiscipline)+ " " + curr->record.fio.getFIO()+ " " + curr->record.date.toQString() + " -> ");
            curr = curr->next;
        }
        text_edit->insertPlainText(")\n");
    }

    Node *head;
};



#endif //LIST_H
