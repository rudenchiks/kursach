#include "mainwindow.h"
#include <fstream>
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QFileDialog>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    confing_project();
    table = nullptr;
    QRegularExpression regExp("^[A-Z][a-zA-Z\\ ]*$");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regExp, ui->disciplineEdit);
    ui->disciplineEdit->setValidator(validator);
    QRegularExpression regFio("^[A-Z][a-z]+ [A-Z][a-z]+ [A-Z][a-z]+");
    QRegularExpressionValidator *validatorFio = new QRegularExpressionValidator(regFio, ui->fioLineEdit);
    ui->fioLineEdit->setValidator(validatorFio);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::pushButtonInsertClicked() {
    if(table == nullptr) {
        addLog("Размер хэш-таблицы не задан");
        return;
    }

    auto data = readEdit();
    if(!data.first) {
        addLog("Неверные данные");
        return;
    }

    auto record = data.second;
    if(table->insert(record)) {
        addLog("Запись добавлена");
        print();
    }
    else
        addLog("Ошибка добавления");

}

void MainWindow::pushButtonDeleteClicked() {
    if(table == nullptr) {
        addLog("Размер хэш-таблицы не задан");
        return;
    }

    auto data = readEdit();
    if(!data.first) {
        addLog("Неверные данные");
        return;
    }

    auto record = data.second;
    if(table->remove(record)) {
        addLog("Запись удалена");
        print();
    }
    else
        addLog("Ошибка удаление");
}

void MainWindow::pushButtonFindClicked() {
    if(table == nullptr) {
        addLog("Размер хэш-таблицы не задан");
        return;
    }

    auto data = readEdit();
    if(!data.first) {
        addLog("Неверные данные");
        return;
    }

    auto record = data.second;
    int cntStep = table->find(record);
    if(cntStep != -1)
        addLog("Запись найдена. Кол-во шагов = " + QString::number(cntStep));
    else
        addLog("Записи нет");
}

void MainWindow::pushButtonInputClicked() const {
    if(table == nullptr) {
        addLog("Размер хэш-таблицы не задан");
        return;
    }

    auto path = QFileDialog::getOpenFileName().toStdString();
    ifstream file(path);
    if(file.is_open()) {
        string buf;
        while(getline(file,buf)) {
            QRegularExpression regex(R"(^(\d{2}\.\d{2}\.\d{2})\s+(.+)\s+(\d{2}\.\d{2}\.\d{4}))");
            QRegularExpressionMatch match = regex.match(QString::fromStdString(buf));
            if (match.hasMatch()) {
                QString passport = match.captured(1);
                QString modelAndFio = match.captured(2);
                string strDate = match.captured(3).toStdString();
                Data data;
                string model;
                QStringList list = modelAndFio.split(' ');
                QRegularExpression reg("^[a-zA-Z ]*$");
                match = reg.match(modelAndFio);
                if(list.size() < 4 || !(list.at(0)[0] >= 'A' && list.at(0)[0] <= 'Z') || !match.hasMatch()) {
                    addLog("Данные некорректны");
                }
                else {
                    auto size = list.size();
                    bool ok = true;
                    reg = QRegularExpression("^[a-z]*$");

                    for(int i=0; i < list.size()-3; i++) {
                        if(list.at(i).toStdString() == "" || (!reg.match(list.at(i)).hasMatch() && i != 0))
                            ok = false;
                        model += list.at(i).toStdString() + " ";
                    }
                    if(ok) {
                        model.pop_back();

                        data.code = Code(passport.mid(0,2).toShort(),passport.mid(3,2).toShort(), passport.mid(6).toInt());
                        data.nameDiscipline = model;
                        data.fio = Fio(list.at(size-3), list.at(size-2), list.at(size-1));
                        data.date = Date(strDate);
                        if(data.date.correctDate() && data.nameDiscipline.length() != 0) {
                            table->insert(data);
                            addLog("Запись добавлена");
                        }
                        else
                            addLog("Ошибка добавления");
                    }
                }
            }
            else {
                addLog("Ошибка добавления");
            }
        }
        addLog("Ошибка добавления");
        file.close();
        print();
    }
    else
        addLog("Ошибка добавления");
}

void MainWindow::pushButtonOutputClicked() const {
    if(table == nullptr) {
        addLog("Размер хэщ-таблицы не задан");
        return;
    }
    const auto path = QFileDialog::getSaveFileName();
    ofstream file(path.toStdString());
    if(file.is_open()) {
        table->write_file(file);
        file.close();
        addLog("Файл был записан");
    }
    else
        addLog("Файл не удалось записать");
}

void MainWindow::pushButtonSetSizeClicked() {
    if(ui->spinBoxSize->value() != 0 && table == nullptr) {
        table = new HashTable(ui->spinBoxSize->value());
        addLog("Размер хэш-таблицы: " + QString::number(ui->spinBoxSize->value()));
        return;
    }
    addLog("Вы уже задавали размер хэш-таблицы");
}

void MainWindow::mainWindowActionClicked() const {
    layouts->setCurrentIndex(0);
}

void MainWindow::debugWindowActionClicked() const {
    layouts->setCurrentIndex(1);
}

void MainWindow::alterViewWindowActionClicked() const {
    layouts->setCurrentIndex(2);
    text_edit->clear();
    print_hash_table();
}

void MainWindow::load_layouts() {
    debug_widget = new QWidget();
    debug_table = new QTableWidget();
    const auto debugLayout = new QVBoxLayout();
    debugLayout->addWidget(debug_table);
    debug_widget->setLayout(debugLayout);

    view_hash_table_widget = new QWidget();
    text_edit = new QPlainTextEdit();
    text_edit->setReadOnly(true);
    const auto view_ht_Layout = new QVBoxLayout();
    view_ht_Layout->addWidget(text_edit);
    view_hash_table_widget->setLayout(view_ht_Layout);

    const auto mainWidget = new QWidget(this);
    layouts = new QStackedLayout(mainWidget);
    layouts->addWidget(ui->centralWidget);
    layouts->addWidget(debug_widget);
    layouts->addWidget(view_hash_table_widget);
    setCentralWidget(mainWidget);
}

void MainWindow::print_hash_table() const {
    if(table == nullptr)
        return;
    table->print(text_edit);
}

void MainWindow::print() const {
    const auto table = ui->tableWidget;
    table->setRowCount(0);
    const auto datas = this->table->print();
    for(const auto& data : datas) {
        const auto row = table->rowCount();
        table->insertRow(row);
        table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(data.code.get_string())));
        table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(data.nameDiscipline)));
        table->setItem(row, 2, new QTableWidgetItem(data.fio.getFIO()));
        table->setItem(row, 3, new QTableWidgetItem(data.date.toQString()));
    }
}

pair<bool, Data> MainWindow::readEdit() {
    Data data;
    if(ui->codeEdit->text().length() < 8 || ui->dateLine->text().length() < 7)
        return make_pair(false, data);

    int f,s,t;
    f = ui->codeEdit->text().mid(0,2).toShort();
    s = ui->codeEdit->text().mid(3,2).toShort();
    t = ui->codeEdit->text().mid(6).toShort();
    data.code= Code(f,s,t);

    data.nameDiscipline = ui->disciplineEdit->text().toStdString();
    QStringList list = ui->fioLineEdit->text().split(' ');
    if(list.size() != 3) {
        return make_pair(false, data);
    }
    data.fio = Fio(list.at(0), list.at(1), list.at(2));
    data.date = Date(ui->dateLine->text().toStdString());
    if(!data.date.correctDate())
        return make_pair(false, data);
    return make_pair(true, data);
}

void MainWindow::addLog(QString log) const {
    const auto row = debug_table->rowCount();
    debug_table->insertRow(row);
    debug_table->setItem(row, 0, new QTableWidgetItem(log));
}

void MainWindow::confing_project() {
    connect(ui->pushButtonInsert, &QPushButton::clicked, this, &MainWindow::pushButtonInsertClicked);
    connect(ui->pushButtonDelete, &QPushButton::clicked, this, &MainWindow::pushButtonDeleteClicked);
    connect(ui->pushButtonFind, &QPushButton::clicked, this, &MainWindow::pushButtonFindClicked);
    connect(ui->pushButtonReadFile, &QPushButton::clicked, this, &MainWindow::pushButtonInputClicked);
    connect(ui->pushButtonWriteFile, &QPushButton::clicked, this, &MainWindow::pushButtonOutputClicked);
    connect(ui->pushButtonSetSize, &QPushButton::clicked, this, &MainWindow::pushButtonSetSizeClicked);
    load_layouts();
    config_menu();

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"Code", "Dicipline", "FIO", "Date"});
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    debug_table->setColumnCount(1);
    debug_table->setHorizontalHeaderLabels({"Log"});
    debug_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    debug_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::config_menu() {
    const auto menu = this->menuBar();
    const auto windows = menu->addMenu("Окна");
    const auto actionMainWindow = windows->addAction("Основное");
    const auto actionDebugWindow = windows->addAction("Отладка");
    const auto actionAlterViewWindow = windows->addAction("Печать структуры");

    connect(actionMainWindow, &QAction::triggered, this, &MainWindow::mainWindowActionClicked);
    connect(actionDebugWindow, &QAction::triggered, this, &MainWindow::debugWindowActionClicked);
    connect(actionAlterViewWindow, &QAction::triggered, this, &MainWindow::alterViewWindowActionClicked);
}
