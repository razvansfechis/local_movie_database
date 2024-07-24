/********************************************************************************
** Form generated from reading UI file 'LocalMovieGUI.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCALMOVIEGUI_H
#define UI_LOCALMOVIEGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LocalMovieGUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LocalMovieGUIClass)
    {
        if (LocalMovieGUIClass->objectName().isEmpty())
            LocalMovieGUIClass->setObjectName("LocalMovieGUIClass");
        LocalMovieGUIClass->resize(600, 400);
        menuBar = new QMenuBar(LocalMovieGUIClass);
        menuBar->setObjectName("menuBar");
        LocalMovieGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LocalMovieGUIClass);
        mainToolBar->setObjectName("mainToolBar");
        LocalMovieGUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(LocalMovieGUIClass);
        centralWidget->setObjectName("centralWidget");
        LocalMovieGUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(LocalMovieGUIClass);
        statusBar->setObjectName("statusBar");
        LocalMovieGUIClass->setStatusBar(statusBar);

        retranslateUi(LocalMovieGUIClass);

        QMetaObject::connectSlotsByName(LocalMovieGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *LocalMovieGUIClass)
    {
        LocalMovieGUIClass->setWindowTitle(QCoreApplication::translate("LocalMovieGUIClass", "LocalMovieGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LocalMovieGUIClass: public Ui_LocalMovieGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCALMOVIEGUI_H
