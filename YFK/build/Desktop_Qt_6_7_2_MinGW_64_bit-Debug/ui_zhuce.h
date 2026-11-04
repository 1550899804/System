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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Zhuce
{
public:
    QPushButton *pushButton_3;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QFrame *line;
    QPushButton *pushButton_2;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;

    void setupUi(QDialog *Zhuce)
    {
        if (Zhuce->objectName().isEmpty())
            Zhuce->setObjectName("Zhuce");
        Zhuce->resize(500, 300);
        pushButton_3 = new QPushButton(Zhuce);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(470, 0, 30, 30));
        label = new QLabel(Zhuce);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 80, 90, 90));
        widget = new QWidget(Zhuce);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(200, 230, 205, 34));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        QFont font;
        font.setPointSize(11);
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);

        line = new QFrame(widget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout->addWidget(line);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setFont(font);

        horizontalLayout->addWidget(pushButton_2);

        widget1 = new QWidget(Zhuce);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(200, 36, 202, 161));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_4 = new QLineEdit(widget1);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setMinimumSize(QSize(200, 30));
        lineEdit_4->setFont(font);

        verticalLayout->addWidget(lineEdit_4);

        lineEdit = new QLineEdit(widget1);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(200, 30));
        lineEdit->setFont(font);

        verticalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(widget1);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setMinimumSize(QSize(200, 30));
        lineEdit_2->setFont(font);

        verticalLayout->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(widget1);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setMinimumSize(QSize(200, 30));
        lineEdit_3->setFont(font);

        verticalLayout->addWidget(lineEdit_3);


        retranslateUi(Zhuce);

        QMetaObject::connectSlotsByName(Zhuce);
    } // setupUi

    void retranslateUi(QDialog *Zhuce)
    {
        Zhuce->setWindowTitle(QCoreApplication::translate("Zhuce", "Dialog", nullptr));
        pushButton_3->setText(QString());
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("Zhuce", "\346\263\250\345\206\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Zhuce", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Zhuce: public Ui_Zhuce {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZHUCE_H
