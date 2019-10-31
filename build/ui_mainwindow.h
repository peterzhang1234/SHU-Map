/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_6;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLCDNumber *lcdNumber;
    QLabel *label_7;
    QLabel *label_5;
    QLCDNumber *lcdNumber_2;
    QComboBox *comboBox_3;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label;
    QStatusBar *statusbar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(922, 613);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setEnabled(true);
        widget->setGeometry(QRect(750, 0, 171, 591));
        widget->setStyleSheet(QStringLiteral("background:rgb(232, 232, 232)"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 90, 51, 31));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 160, 41, 31));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, 410, 61, 31));
        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(30, 120, 121, 31));
        comboBox->setEditable(false);
        comboBox_2 = new QComboBox(widget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(30, 190, 121, 31));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 10, 71, 61));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 240, 81, 31));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(90, 240, 81, 31));
        lcdNumber = new QLCDNumber(widget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(70, 410, 61, 31));
        lcdNumber->setFrameShadow(QFrame::Raised);
        lcdNumber->setSmallDecimalPoint(true);
        lcdNumber->setDigitCount(4);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(140, 460, 31, 31));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 290, 111, 31));
        lcdNumber_2 = new QLCDNumber(widget);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(70, 460, 64, 31));
        lcdNumber_2->setSmallDecimalPoint(true);
        lcdNumber_2->setDigitCount(4);
        lcdNumber_2->setSegmentStyle(QLCDNumber::Flat);
        comboBox_3 = new QComboBox(widget);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(50, 320, 71, 31));
        comboBox_3->setEditable(false);
        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(0, 460, 61, 31));
        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(140, 410, 21, 21));
        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 360, 121, 41));
        label_11 = new QLabel(widget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(0, 530, 171, 41));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 751, 612));
        label->setContextMenuPolicy(Qt::DefaultContextMenu);
        MainWindow->setCentralWidget(centralwidget);
        label->raise();
        widget->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 922, 23));
        menuBar->setDefaultUp(false);
        menuBar->setNativeMenuBar(true);
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\350\265\267\347\202\271</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\347\273\210\347\202\271</span></p></body></html>", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:600;\">\345\205\250\347\250\213\347\272\246</span></p></body></html>", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\344\270\234\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\270\200\345\217\267\344\275\223\350\202\262\345\234\272\357\274\210K\345\214\272\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\237\263\344\271\220\345\255\246\351\231\242", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\275\223\350\202\262\351\246\206", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\350\256\255\347\273\203\351\246\206", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\270\270\346\263\263\351\246\206", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\271\220\344\271\216\346\226\260\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\350\256\255\347\273\203\345\234\272\357\274\210A\345\214\272\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\243\216\351\233\250\346\223\215\345\234\272\357\274\210C\345\214\272\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\257\256\347\220\203\345\234\272\357\274\210B\345\214\272\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\214\227\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\240\241\345\214\273\351\231\242", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\207\272\347\211\210\347\244\276", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\216\204\351\231\265\347\275\221\347\220\203\351\246\206", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\275\221\347\220\203\345\234\272\357\274\210E\345\214\272\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\257\256\347\220\203\345\234\272/\346\216\222\347\220\203\345\234\272\357\274\210F\345\214\272\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\257\256\347\220\203\345\234\272\357\274\210G\345\214\272\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\260\224\347\276\216\351\243\237\345\240\202", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\261\261\346\230\216\351\243\237\345\240\202", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\233\212\346\226\260\351\243\237\345\240\202", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1\345\217\267\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\274\237\351\225\277\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "G\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "GJ", Q_NULLPTR)
         << QApplication::translate("MainWindow", "F\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "FJ", Q_NULLPTR)
         << QApplication::translate("MainWindow", "E\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "EJ", Q_NULLPTR)
         << QApplication::translate("MainWindow", "J\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\260\264\347\247\200\351\243\237\345\240\202", Q_NULLPTR)
         << QApplication::translate("MainWindow", "D\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "DJ", Q_NULLPTR)
         << QApplication::translate("MainWindow", "C\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "CJ", Q_NULLPTR)
         << QApplication::translate("MainWindow", "B\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "BJ", Q_NULLPTR)
         << QApplication::translate("MainWindow", "A\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "AJ", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\350\241\214\346\224\277\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\272\257\345\233\255", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\276\216\346\234\257\345\255\246\351\231\242", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\215\227\346\255\243\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\233\276\344\271\246\351\246\206/\345\233\276\346\212\245\345\216\205", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\257\256\347\220\203\345\234\272\357\274\210H\345\214\272\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\350\266\263\347\220\203\345\234\272\357\274\210J\345\214\272\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\257\256\347\220\203\345\234\272\357\274\210I\345\214\272\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\262\231\346\273\251/\351\253\230\345\260\224\345\244\253\347\220\203\345\234\272/\346\216\222\347\220\203\345\234\272\357\274\210L\345\214\272\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\220\216\345\213\244\345\237\272\345\273\272\345\244\247\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\215\227\344\272\214\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\272\224\351\246\250\351\243\237\345\240\202", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\226\260\344\270\226\347\272\252", Q_NULLPTR)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\344\270\234\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\270\200\345\217\267\344\275\223\350\202\262\345\234\272\357\274\210K\345\214\272\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\237\263\344\271\220\345\255\246\351\231\242", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\275\223\350\202\262\351\246\206", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\350\256\255\347\273\203\351\246\206", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\270\270\346\263\263\351\246\206", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\271\220\344\271\216\346\226\260\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\350\256\255\347\273\203\345\234\272\357\274\210A\345\214\272\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\243\216\351\233\250\346\223\215\345\234\272\357\274\210C\345\214\272\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\257\256\347\220\203\345\234\272\357\274\210B\345\214\272\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\214\227\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\240\241\345\214\273\351\231\242", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\207\272\347\211\210\347\244\276", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\216\204\351\231\265\347\275\221\347\220\203\351\246\206", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\275\221\347\220\203\345\234\272\357\274\210E\345\214\272\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\257\256\347\220\203\345\234\272/\346\216\222\347\220\203\345\234\272\357\274\210F\345\214\272\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\257\256\347\220\203\345\234\272\357\274\210G\345\214\272\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\260\224\347\276\216\351\243\237\345\240\202", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\261\261\346\230\216\351\243\237\345\240\202", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\233\212\346\226\260\351\243\237\345\240\202", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1\345\217\267\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\274\237\351\225\277\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "G\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "GJ", Q_NULLPTR)
         << QApplication::translate("MainWindow", "F\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "FJ", Q_NULLPTR)
         << QApplication::translate("MainWindow", "E\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "EJ", Q_NULLPTR)
         << QApplication::translate("MainWindow", "J\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\260\264\347\247\200\351\243\237\345\240\202", Q_NULLPTR)
         << QApplication::translate("MainWindow", "D\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "DJ", Q_NULLPTR)
         << QApplication::translate("MainWindow", "C\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "CJ", Q_NULLPTR)
         << QApplication::translate("MainWindow", "B\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "BJ", Q_NULLPTR)
         << QApplication::translate("MainWindow", "A\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "AJ", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\350\241\214\346\224\277\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\272\257\345\233\255", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\276\216\346\234\257\345\255\246\351\231\242", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\215\227\346\255\243\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\233\276\344\271\246\351\246\206/\345\233\276\346\212\245\345\216\205", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\257\256\347\220\203\345\234\272\357\274\210H\345\214\272\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\350\266\263\347\220\203\345\234\272\357\274\210J\345\214\272\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\257\256\347\220\203\345\234\272\357\274\210I\345\214\272\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\262\231\346\273\251/\351\253\230\345\260\224\345\244\253\347\220\203\345\234\272/\346\216\222\347\220\203\345\234\272\357\274\210L\345\214\272\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\220\216\345\213\244\345\237\272\345\273\272\345\244\247\346\245\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\215\227\344\272\214\351\227\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\272\224\351\246\250\351\243\237\345\240\202", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\226\260\344\270\226\347\272\252", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; font-style:italic; color:#550000;\">\344\270\212\346\265\267\345\244\247\345\255\246</span></p><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; font-style:italic; color:#550000;\">\346\240\241\345\233\255\345\257\274\350\210\252</span></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\351\207\215\347\275\256", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">min</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\351\200\211\346\213\251\345\207\272\350\241\214\346\226\271\345\274\217</span></p></body></html>", Q_NULLPTR));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\252\221\350\241\214", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\255\245\350\241\214", Q_NULLPTR)
        );
        label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:600;\">\345\205\261\351\234\200\347\272\246</span></p></body></html>", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">m</span></p></body></html>", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><a href=\"https://caiyunapp.com/weather/\"><span style=\" text-decoration: underline; color:#0000ff;\">\347\202\271\346\210\221\346\237\245\347\234\213\345\244\251\346\260\224\346\203\205\345\206\265</span></a></p></body></html>", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:8pt;\">*\346\211\200\347\224\250\345\233\276\347\211\207\347\224\261\344\270\212\346\265\267\345\244\247\345\255\246\345\255\246\347\224\237\344\274\232\345\216\237\345\210\233</span></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
