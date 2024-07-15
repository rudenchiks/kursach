#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QStackedLayout>
#include "HashTable.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void pushButtonInsertClicked();
    void pushButtonDeleteClicked();
    void pushButtonFindClicked();
    void pushButtonInputClicked() const;
    void pushButtonOutputClicked() const;
    void pushButtonSetSizeClicked();

    void mainWindowActionClicked() const;
    void debugWindowActionClicked() const;
    void alterViewWindowActionClicked() const;

private:
    void confing_project();
    void config_menu();
    void load_layouts();
    void print_hash_table() const;
    void print() const;
    pair<bool, Data> readEdit();
    void addLog(QString log) const;

private:
    Ui::MainWindow *ui;
    HashTable *table;
    QStackedLayout *layouts{};
    QWidget *debug_widget{};
    QTableWidget *debug_table{};
    QWidget *view_hash_table_widget{};
    QPlainTextEdit *text_edit{};
};


#endif //MAINWINDOW_H
