/********************************************************************************
** Form generated from reading UI file 'linechartwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINECHARTWIDGET_H
#define UI_LINECHARTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LineChartWidget
{
public:

    void setupUi(QWidget *LineChartWidget)
    {
        if (LineChartWidget->objectName().isEmpty())
            LineChartWidget->setObjectName("LineChartWidget");
        LineChartWidget->resize(400, 300);

        retranslateUi(LineChartWidget);

        QMetaObject::connectSlotsByName(LineChartWidget);
    } // setupUi

    void retranslateUi(QWidget *LineChartWidget)
    {
        LineChartWidget->setWindowTitle(QCoreApplication::translate("LineChartWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LineChartWidget: public Ui_LineChartWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINECHARTWIDGET_H
