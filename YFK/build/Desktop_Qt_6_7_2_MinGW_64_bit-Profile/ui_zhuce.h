/********************************************************************************
** Form generated from reading UI file 'zhuce.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZHUCE_H
#define UI_ZHUCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Zhuce
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_4;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_3;
    QLabel *label_2;

    void setupUi(QDialog *Zhuce)
    {
        if (Zhuce->objectName().isEmpty())
            Zhuce->setObjectName("Zhuce");
        Zhuce->resize(550, 350);
        widget = new QWidget(Zhuce);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(170, 209, 197, 141));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(17, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        QFont font;
        font.setPointSize(11);
        pushButton->setFont(font);

        gridLayout_2->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setFont(font);

        gridLayout_2->addWidget(pushButton_2, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        widget1 = new QWidget(Zhuce);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(90, 0, 355, 211));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(12);
        lineEdit_4 = new QLineEdit(widget1);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setMinimumSize(QSize(200, 30));
        lineEdit_4->setFont(font);

        gridLayout->addWidget(lineEdit_4, 0, 1, 1, 1);

        label = new QLabel(widget1);
        label->setObjectName("label");
        label->setFont(font);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_3 = new QLabel(widget1);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        lineEdit_2 = new QLineEdit(widget1);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setMinimumSize(QSize(200, 30));
        lineEdit_2->setFont(font);

        gridLayout->addWidget(lineEdit_2, 2, 1, 1, 1);

        label_4 = new QLabel(widget1);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget1);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(200, 30));
        lineEdit->setFont(font);

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        lineEdit_3 = new QLineEdit(widget1);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setMinimumSize(QSize(200, 30));
        lineEdit_3->setFont(font);

        gridLayout->addWidget(lineEdit_3, 3, 1, 1, 1);

        label_2 = new QLabel(widget1);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        retranslateUi(Zhuce);

        QMetaObject::connectSlotsByName(Zhuce);
    } // setupUi

    void retranslateUi(QDialog *Zhuce)
    {
        Zhuce->setWindowTitle(QCoreApplication::translate("Zhuce", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Zhuce", "\347\231\273\345\275\225", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Zhuce", "\346\263\250\345\206\214", nullptr));
        label->setText(QCoreApplication::translate("Zhuce", "\350\257\267\350\276\223\345\205\245\346\226\260\350\264\246\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("Zhuce", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201", nullptr));
        label_4->setText(QCoreApplication::translate("Zhuce", "\350\257\267\350\276\223\345\205\245\344\272\272\345\221\230\345\247\223\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("Zhuce", "\350\257\267\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Zhuce: public Ui_Zhuce {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZHUCE_H
