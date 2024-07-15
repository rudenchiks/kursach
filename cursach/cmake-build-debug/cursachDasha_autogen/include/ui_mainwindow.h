/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QSpinBox *spinBoxSize;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *codeEdit;
    QLineEdit *disciplineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *fioLineEdit;
    QLineEdit *dateLine;
    QPushButton *pushButtonSetSize;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButtonInsert;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonFind;
    QPushButton *pushButtonReadFile;
    QPushButton *pushButtonWriteFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1107, 719);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        spinBoxSize = new QSpinBox(centralWidget);
        spinBoxSize->setObjectName(QString::fromUtf8("spinBoxSize"));
        spinBoxSize->setMaximum(1000000);

        verticalLayout->addWidget(spinBoxSize);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        codeEdit = new QLineEdit(centralWidget);
        codeEdit->setObjectName(QString::fromUtf8("codeEdit"));
        QFont font;
        font.setPointSize(11);
        codeEdit->setFont(font);

        horizontalLayout_4->addWidget(codeEdit);

        disciplineEdit = new QLineEdit(centralWidget);
        disciplineEdit->setObjectName(QString::fromUtf8("disciplineEdit"));

        horizontalLayout_4->addWidget(disciplineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        fioLineEdit = new QLineEdit(centralWidget);
        fioLineEdit->setObjectName(QString::fromUtf8("fioLineEdit"));
        fioLineEdit->setFont(font);

        horizontalLayout_6->addWidget(fioLineEdit);

        dateLine = new QLineEdit(centralWidget);
        dateLine->setObjectName(QString::fromUtf8("dateLine"));
        dateLine->setFont(font);

        horizontalLayout_6->addWidget(dateLine);


        verticalLayout->addLayout(horizontalLayout_6);

        pushButtonSetSize = new QPushButton(centralWidget);
        pushButtonSetSize->setObjectName(QString::fromUtf8("pushButtonSetSize"));

        verticalLayout->addWidget(pushButtonSetSize);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButtonInsert = new QPushButton(centralWidget);
        pushButtonInsert->setObjectName(QString::fromUtf8("pushButtonInsert"));

        verticalLayout_2->addWidget(pushButtonInsert);

        pushButtonDelete = new QPushButton(centralWidget);
        pushButtonDelete->setObjectName(QString::fromUtf8("pushButtonDelete"));

        verticalLayout_2->addWidget(pushButtonDelete);

        pushButtonFind = new QPushButton(centralWidget);
        pushButtonFind->setObjectName(QString::fromUtf8("pushButtonFind"));

        verticalLayout_2->addWidget(pushButtonFind);

        pushButtonReadFile = new QPushButton(centralWidget);
        pushButtonReadFile->setObjectName(QString::fromUtf8("pushButtonReadFile"));

        verticalLayout_2->addWidget(pushButtonReadFile);

        pushButtonWriteFile = new QPushButton(centralWidget);
        pushButtonWriteFile->setObjectName(QString::fromUtf8("pushButtonWriteFile"));

        verticalLayout_2->addWidget(pushButtonWriteFile);


        verticalLayout->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\232\321\203\321\200\321\201\320\276\320\262\320\260\321\217", nullptr));
        spinBoxSize->setPrefix(QCoreApplication::translate("MainWindow", "Size: ", nullptr));
        codeEdit->setInputMask(QCoreApplication::translate("MainWindow", "00.00.00", nullptr));
        codeEdit->setText(QCoreApplication::translate("MainWindow", "09.03.04", nullptr));
        codeEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\264 \320\275\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217", nullptr));
        disciplineEdit->setText(QString());
        disciplineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265 \320\264\320\270\321\201\321\206\320\270\320\277\320\273\320\270\320\275\321\213", nullptr));
        fioLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\244\320\230\320\236", nullptr));
        dateLine->setInputMask(QCoreApplication::translate("MainWindow", "00.00.0000", nullptr));
        dateLine->setText(QCoreApplication::translate("MainWindow", "..", nullptr));
        dateLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260", nullptr));
        pushButtonSetSize->setText(QCoreApplication::translate("MainWindow", "Set size", nullptr));
        pushButtonInsert->setText(QCoreApplication::translate("MainWindow", "Insert", nullptr));
        pushButtonDelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        pushButtonFind->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
        pushButtonReadFile->setText(QCoreApplication::translate("MainWindow", "Read file", nullptr));
        pushButtonWriteFile->setText(QCoreApplication::translate("MainWindow", "Write file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
