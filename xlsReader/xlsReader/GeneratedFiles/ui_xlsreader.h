/********************************************************************************
** Form generated from reading UI file 'xlsreader.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XLSREADER_H
#define UI_XLSREADER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_xlsReaderClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *xlsReaderClass)
    {
        if (xlsReaderClass->objectName().isEmpty())
            xlsReaderClass->setObjectName(QString::fromUtf8("xlsReaderClass"));
        xlsReaderClass->resize(600, 400);
        menuBar = new QMenuBar(xlsReaderClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        xlsReaderClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(xlsReaderClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        xlsReaderClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(xlsReaderClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        xlsReaderClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(xlsReaderClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        xlsReaderClass->setStatusBar(statusBar);

        retranslateUi(xlsReaderClass);

        QMetaObject::connectSlotsByName(xlsReaderClass);
    } // setupUi

    void retranslateUi(QMainWindow *xlsReaderClass)
    {
        xlsReaderClass->setWindowTitle(QApplication::translate("xlsReaderClass", "xlsReader", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class xlsReaderClass: public Ui_xlsReaderClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XLSREADER_H
