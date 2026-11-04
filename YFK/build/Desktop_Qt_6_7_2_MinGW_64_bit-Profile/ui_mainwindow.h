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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 400);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 601, 71));
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget\n"
"{\n"
"	\n"
"	background-color: rgb(0, 170, 255);\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_3 = new QSpacerItem(160, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label = new QLabel(widget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(14);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(159, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 282, 601, 36));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");
        QFont font1;
        font1.setPointSize(11);
        pushButton->setFont(font1);

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setFont(font1);

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setFont(font1);

        horizontalLayout->addWidget(pushButton_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(4, 140, 591, 71));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName("label_2");
        label_2->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEdit = new QLineEdit(layoutWidget1);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(200, 30));
        lineEdit->setFont(font1);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lineEdit_2 = new QLineEdit(layoutWidget1);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setMinimumSize(QSize(200, 30));
        lineEdit_2->setFont(font1);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);


        horizontalLayout_3->addLayout(formLayout);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 600, 25));
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
        label->setText(QCoreApplication::translate("MainWindow", "\346\254\242\350\277\216\344\275\277\347\224\250\346\231\272\350\203\275\347\211\251\346\265\201\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\206\214", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\350\264\246\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
