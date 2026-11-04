/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QRadioButton *radioButton;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QFrame *line;
    QLabel *label_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(350, 450);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(80, 281, 237, 23));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(80, 325, 200, 32));
        QFont font;
        font.setPointSize(11);
        pushButton->setFont(font);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(285, 0, 30, 30));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(320, 0, 30, 30));
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(160, 395, 20, 22));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(135, 90, 85, 85));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(90, 190, 177, 73));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(175, 32));
        lineEdit->setMaximumSize(QSize(150, 16777215));
        lineEdit->setFont(font);

        verticalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setMinimumSize(QSize(175, 32));
        lineEdit_2->setMaximumSize(QSize(150, 16777215));
        lineEdit_2->setFont(font);

        verticalLayout->addWidget(lineEdit_2);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(5, 40, 351, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        label = new QLabel(layoutWidget1);
        label->setObjectName("label");
        label->setMaximumSize(QSize(300, 16777215));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);

        horizontalLayout_4->addWidget(label);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(180, 390, 93, 32));
        pushButton_2->setFont(font);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(65, 390, 93, 32));
        pushButton_3->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 350, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "\345\267\262\351\230\205\350\257\273\345\271\266\345\220\214\346\204\217\347\256\241\347\220\206\347\263\273\347\273\237\346\234\215\345\212\241\345\215\217\350\256\256", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        label_2->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\346\254\242\350\277\216\344\275\277\347\224\250\346\231\272\350\203\275\347\211\251\346\265\201\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "  \346\233\264\345\244\232\345\212\237\350\203\275", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", " \346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
