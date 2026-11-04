/********************************************************************************
** Form generated from reading UI file 'zhujiemian.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZHUJIEMIAN_H
#define UI_ZHUJIEMIAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Zhujiemian
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *timeLabel;
    QTreeWidget *treeWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_4;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_11;
    QWidget *page_1;
    QLabel *label_10;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_12;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QLabel *label_7;
    QLineEdit *lineEdit_5;
    QLabel *label_8;
    QLineEdit *lineEdit_6;
    QLabel *label_9;
    QLineEdit *lineEdit_7;
    QSpacerItem *horizontalSpacer_13;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *horizontalSpacer_16;
    QWidget *page_2;
    QTableWidget *tableWidget;
    QLabel *label_11;
    QPushButton *pushButton_9;
    QWidget *widget5;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QWidget *page_3;
    QWidget *page_4;
    QStackedWidget *stackedWidget_2;
    QWidget *page_9;
    QWidget *widget_2;
    QFrame *frame;
    QFrame *frame_2;
    QFrame *frame_3;
    QFrame *frame_4;
    QWidget *page_10;
    QWidget *widget_3;
    QWidget *page_11;
    QWidget *widget_4;
    QWidget *page_12;
    QWidget *widget_5;
    QWidget *page_5;
    QWidget *page_6;
    QWidget *page_7;
    QWidget *page_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Zhujiemian)
    {
        if (Zhujiemian->objectName().isEmpty())
            Zhujiemian->setObjectName("Zhujiemian");
        Zhujiemian->resize(1000, 600);
        centralwidget = new QWidget(Zhujiemian);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 1000, 50));
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget\n"
"{\n"
"	\n"
"	\n"
"	\n"
"	\n"
"	background-color: rgb(58, 105, 159);\n"
"}"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(173, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalSpacer_4 = new QSpacerItem(173, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        label = new QLabel(widget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(13);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(172, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalSpacer_3 = new QSpacerItem(124, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        timeLabel = new QLabel(widget);
        timeLabel->setObjectName("timeLabel");
        timeLabel->setMinimumSize(QSize(100, 0));
        QFont font1;
        font1.setPointSize(10);
        timeLabel->setFont(font1);

        horizontalLayout->addWidget(timeLabel);

        treeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setGeometry(QRect(0, 50, 200, 550));
        treeWidget->setStyleSheet(QString::fromUtf8("QTreeWidget#treeWidget\n"
"{\n"
"	background-color: rgb(30, 42, 60);\n"
"}\n"
"QTreeWidget {\n"
"    color: white;  /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
"    background-color: #2c3e50;  /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262\344\270\272\346\267\261\350\211\262 */\n"
"}\n"
"QTreeWidget::item:selected {\n"
"    background-color: #3498db;  /* \350\256\276\347\275\256\351\200\211\344\270\255\351\241\271\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white;  /* \350\256\276\347\275\256\351\200\211\344\270\255\351\241\271\347\232\204\345\255\227\344\275\223\351\242\234\350\211\262 */\n"
"}"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(200, 50, 800, 550));
        stackedWidget->setMinimumSize(QSize(0, 30));
        QFont font2;
        font2.setPointSize(11);
        stackedWidget->setFont(font2);
        page = new QWidget();
        page->setObjectName("page");
        label_4 = new QLabel(page);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(320, 290, 162, 23));
        label_4->setFont(font2);
        widget1 = new QWidget(page);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(0, 110, 801, 108));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_2 = new QLabel(widget1);
        label_2->setObjectName("label_2");
        label_2->setFont(font2);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEdit = new QLineEdit(widget1);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(200, 30));
        lineEdit->setFont(font2);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_3 = new QLabel(widget1);
        label_3->setObjectName("label_3");
        label_3->setFont(font2);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lineEdit_2 = new QLineEdit(widget1);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setMinimumSize(QSize(200, 30));
        lineEdit_2->setFont(font2);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_5 = new QLabel(widget1);
        label_5->setObjectName("label_5");
        label_5->setFont(font2);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        lineEdit_3 = new QLineEdit(widget1);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setMinimumSize(QSize(200, 30));
        lineEdit_3->setFont(font2);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_3);


        horizontalLayout_2->addLayout(formLayout);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        widget2 = new QWidget(page);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(0, 380, 801, 34));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        pushButton = new QPushButton(widget2);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(50, 30));
        pushButton->setFont(font2);

        horizontalLayout_3->addWidget(pushButton);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        pushButton_2 = new QPushButton(widget2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(50, 30));
        pushButton_2->setFont(font2);

        horizontalLayout_3->addWidget(pushButton_2);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_10);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_11);

        stackedWidget->addWidget(page);
        page_1 = new QWidget();
        page_1->setObjectName("page_1");
        label_10 = new QLabel(page_1);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(350, 300, 91, 19));
        widget3 = new QWidget(page_1);
        widget3->setObjectName("widget3");
        widget3->setGeometry(QRect(0, 100, 801, 145));
        horizontalLayout_4 = new QHBoxLayout(widget3);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_12);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_6 = new QLabel(widget3);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        lineEdit_4 = new QLineEdit(widget3);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setMinimumSize(QSize(200, 30));

        gridLayout->addWidget(lineEdit_4, 0, 1, 1, 1);

        label_7 = new QLabel(widget3);
        label_7->setObjectName("label_7");
        label_7->setFont(font2);

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        lineEdit_5 = new QLineEdit(widget3);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setMinimumSize(QSize(200, 30));

        gridLayout->addWidget(lineEdit_5, 1, 1, 1, 1);

        label_8 = new QLabel(widget3);
        label_8->setObjectName("label_8");

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        lineEdit_6 = new QLineEdit(widget3);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setMinimumSize(QSize(200, 30));

        gridLayout->addWidget(lineEdit_6, 2, 1, 1, 1);

        label_9 = new QLabel(widget3);
        label_9->setObjectName("label_9");
        label_9->setFont(font2);

        gridLayout->addWidget(label_9, 3, 0, 1, 1);

        lineEdit_7 = new QLineEdit(widget3);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setMinimumSize(QSize(200, 30));

        gridLayout->addWidget(lineEdit_7, 3, 1, 1, 1);


        horizontalLayout_4->addLayout(gridLayout);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_13);

        widget4 = new QWidget(page_1);
        widget4->setObjectName("widget4");
        widget4->setGeometry(QRect(0, 390, 801, 34));
        horizontalLayout_5 = new QHBoxLayout(widget4);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_17);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_14);

        pushButton_3 = new QPushButton(widget4);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(50, 30));

        horizontalLayout_5->addWidget(pushButton_3);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_15);

        pushButton_4 = new QPushButton(widget4);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMinimumSize(QSize(50, 30));

        horizontalLayout_5->addWidget(pushButton_4);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_18);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_16);

        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        tableWidget = new QTableWidget(page_2);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(50, 0, 550, 550));
        label_11 = new QLabel(page_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(620, 20, 151, 211));
        pushButton_9 = new QPushButton(page_2);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(650, 90, 93, 71));
        widget5 = new QWidget(page_2);
        widget5->setObjectName("widget5");
        widget5->setGeometry(QRect(650, 290, 95, 201));
        verticalLayout = new QVBoxLayout(widget5);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_7 = new QPushButton(widget5);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setMaximumSize(QSize(93, 32));

        verticalLayout->addWidget(pushButton_7);

        pushButton_5 = new QPushButton(widget5);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setMinimumSize(QSize(93, 32));
        pushButton_5->setMaximumSize(QSize(93, 32));

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(widget5);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setMinimumSize(QSize(93, 32));
        pushButton_6->setMaximumSize(QSize(93, 32));

        verticalLayout->addWidget(pushButton_6);

        pushButton_8 = new QPushButton(widget5);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setMinimumSize(QSize(93, 32));
        pushButton_8->setMaximumSize(QSize(93, 32));

        verticalLayout->addWidget(pushButton_8);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        stackedWidget_2 = new QStackedWidget(page_4);
        stackedWidget_2->setObjectName("stackedWidget_2");
        stackedWidget_2->setGeometry(QRect(0, 0, 800, 550));
        page_9 = new QWidget();
        page_9->setObjectName("page_9");
        widget_2 = new QWidget(page_9);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 2, 800, 550));
        frame = new QFrame(widget_2);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(40, 27, 151, 96));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        frame_2 = new QFrame(widget_2);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(198, 27, 151, 96));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        frame_3 = new QFrame(widget_2);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(40, 130, 151, 96));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        frame_4 = new QFrame(widget_2);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(198, 130, 151, 96));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        stackedWidget_2->addWidget(page_9);
        page_10 = new QWidget();
        page_10->setObjectName("page_10");
        widget_3 = new QWidget(page_10);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(0, 0, 800, 550));
        stackedWidget_2->addWidget(page_10);
        page_11 = new QWidget();
        page_11->setObjectName("page_11");
        widget_4 = new QWidget(page_11);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(0, 0, 800, 550));
        stackedWidget_2->addWidget(page_11);
        page_12 = new QWidget();
        page_12->setObjectName("page_12");
        widget_5 = new QWidget(page_12);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(0, 0, 800, 550));
        stackedWidget_2->addWidget(page_12);
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        stackedWidget->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        stackedWidget->addWidget(page_8);
        Zhujiemian->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Zhujiemian);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 25));
        Zhujiemian->setMenuBar(menubar);
        statusbar = new QStatusBar(Zhujiemian);
        statusbar->setObjectName("statusbar");
        Zhujiemian->setStatusBar(statusbar);

        retranslateUi(Zhujiemian);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(Zhujiemian);
    } // setupUi

    void retranslateUi(QMainWindow *Zhujiemian)
    {
        Zhujiemian->setWindowTitle(QCoreApplication::translate("Zhujiemian", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("Zhujiemian", "\351\253\230\346\226\260\350\245\277\345\214\272\347\211\251\346\265\201\346\270\257", nullptr));
        timeLabel->setText(QString());
        label_4->setText(QCoreApplication::translate("Zhujiemian", "\350\257\267\344\273\224\347\273\206\346\240\270\345\257\271\350\264\246\345\217\267\345\257\206\347\240\201", nullptr));
        label_2->setText(QCoreApplication::translate("Zhujiemian", "\350\257\267\350\276\223\345\205\245\344\277\256\346\224\271\350\264\246\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("Zhujiemian", "\350\257\267\350\276\223\345\205\245\344\277\256\346\224\271\345\211\215\345\257\206\347\240\201", nullptr));
        label_5->setText(QCoreApplication::translate("Zhujiemian", "\350\257\267\350\276\223\345\205\245\344\277\256\346\224\271\345\220\216\345\257\206\347\240\201", nullptr));
        pushButton->setText(QCoreApplication::translate("Zhujiemian", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Zhujiemian", "\351\207\215\346\226\260\347\231\273\345\275\225", nullptr));
        label_10->setText(QCoreApplication::translate("Zhujiemian", "\350\257\267\350\260\250\346\205\216\346\223\215\344\275\234", nullptr));
        label_6->setText(QCoreApplication::translate("Zhujiemian", "\350\257\267\350\276\223\345\205\245\345\210\240\351\231\244\350\264\246\345\217\267", nullptr));
        label_7->setText(QCoreApplication::translate("Zhujiemian", "\350\257\267\350\276\223\345\205\245\346\255\244\350\264\246\345\217\267\345\257\206\347\240\201", nullptr));
        label_8->setText(QCoreApplication::translate("Zhujiemian", "\350\257\267\350\276\223\345\205\245\346\223\215\344\275\234\350\200\205\345\247\223\345\220\215", nullptr));
        label_9->setText(QCoreApplication::translate("Zhujiemian", "\350\257\267\350\276\223\345\205\245\346\223\215\344\275\234\350\200\205\345\257\206\347\240\201", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Zhujiemian", "\347\241\256\350\256\244\345\210\240\351\231\244", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Zhujiemian", "\351\207\215\346\226\260\347\231\273\345\275\225", nullptr));
        label_11->setText(QString());
        pushButton_9->setText(QString());
        pushButton_7->setText(QCoreApplication::translate("Zhujiemian", "\346\226\260\345\242\236\344\277\241\346\201\257", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Zhujiemian", "\344\277\256\346\224\271\344\277\241\346\201\257", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Zhujiemian", "\345\210\240\351\231\244\344\277\241\346\201\257", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Zhujiemian", "\345\210\267\346\226\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Zhujiemian: public Ui_Zhujiemian {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZHUJIEMIAN_H
