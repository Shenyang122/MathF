/********************************************************************************
** Form generated from reading UI file 'gateplaner.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GATEPLANER_H
#define UI_GATEPLANER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GatePlanerClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *tablePucks;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_2;
    QTreeWidget *tableTickets;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_3;
    QTreeWidget *tableGates;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GatePlanerClass)
    {
        if (GatePlanerClass->objectName().isEmpty())
            GatePlanerClass->setObjectName(QString::fromUtf8("GatePlanerClass"));
        GatePlanerClass->resize(682, 460);
        centralWidget = new QWidget(GatePlanerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_4 = new QHBoxLayout(centralWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMovable(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tablePucks = new QTreeWidget(tab);
        tablePucks->setObjectName(QString::fromUtf8("tablePucks"));

        horizontalLayout->addWidget(tablePucks);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_2 = new QHBoxLayout(tab_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tableTickets = new QTreeWidget(tab_2);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("\346\227\205\345\256\242\350\256\260\345\275\225\345\217\267"));
        tableTickets->setHeaderItem(__qtreewidgetitem);
        tableTickets->setObjectName(QString::fromUtf8("tableTickets"));

        horizontalLayout_2->addWidget(tableTickets);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        horizontalLayout_3 = new QHBoxLayout(tab_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        tableGates = new QTreeWidget(tab_3);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QString::fromUtf8("\347\231\273\346\234\272\345\217\243"));
        tableGates->setHeaderItem(__qtreewidgetitem1);
        tableGates->setObjectName(QString::fromUtf8("tableGates"));

        horizontalLayout_3->addWidget(tableGates);

        tabWidget->addTab(tab_3, QString());

        horizontalLayout_4->addWidget(tabWidget);

        GatePlanerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GatePlanerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 682, 23));
        GatePlanerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GatePlanerClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GatePlanerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GatePlanerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GatePlanerClass->setStatusBar(statusBar);

        retranslateUi(GatePlanerClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GatePlanerClass);
    } // setupUi

    void retranslateUi(QMainWindow *GatePlanerClass)
    {
        GatePlanerClass->setWindowTitle(QApplication::translate("GatePlanerClass", "GatePlaner", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = tablePucks->headerItem();
        ___qtreewidgetitem->setText(9, QApplication::translate("GatePlanerClass", "\345\207\272\345\217\221\347\261\273\345\236\213", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(8, QApplication::translate("GatePlanerClass", "\345\207\272\345\217\221\350\210\252\347\217\255", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(7, QApplication::translate("GatePlanerClass", "\345\207\272\345\217\221\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(6, QApplication::translate("GatePlanerClass", "\345\207\272\345\217\221\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(5, QApplication::translate("GatePlanerClass", "\351\243\236\346\234\272\345\236\213\345\217\267", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(4, QApplication::translate("GatePlanerClass", "\345\210\260\350\276\276\347\261\273\345\236\213", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(3, QApplication::translate("GatePlanerClass", "\345\210\260\350\276\276\350\210\252\347\217\255", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("GatePlanerClass", "\345\210\260\350\276\276\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("GatePlanerClass", "\345\210\260\350\276\276\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("GatePlanerClass", "\351\243\236\346\234\272\350\275\254\345\234\272\350\256\260\345\275\225\345\217\267", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("GatePlanerClass", "Pucks", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem1 = tableTickets->headerItem();
        ___qtreewidgetitem1->setText(5, QApplication::translate("GatePlanerClass", "\345\207\272\345\217\221\350\210\252\347\217\255", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(4, QApplication::translate("GatePlanerClass", "\345\207\272\345\217\221\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(3, QApplication::translate("GatePlanerClass", "\345\210\260\350\276\276\350\210\252\347\217\255", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(2, QApplication::translate("GatePlanerClass", "\345\210\260\350\276\276\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(1, QApplication::translate("GatePlanerClass", "\344\271\230\345\256\242\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("GatePlanerClass", "Tickets", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem2 = tableGates->headerItem();
        ___qtreewidgetitem2->setText(5, QApplication::translate("GatePlanerClass", "\346\234\272\344\275\223\347\261\273\345\210\253", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem2->setText(4, QApplication::translate("GatePlanerClass", "\345\207\272\345\217\221\347\261\273\345\236\213", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem2->setText(3, QApplication::translate("GatePlanerClass", "\345\210\260\350\276\276\347\261\273\345\236\213", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem2->setText(2, QApplication::translate("GatePlanerClass", "\345\214\272\345\237\237", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem2->setText(1, QApplication::translate("GatePlanerClass", "\347\273\210\347\253\257\345\216\205", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("GatePlanerClass", "Gates", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GatePlanerClass: public Ui_GatePlanerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GATEPLANER_H
