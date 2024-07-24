/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *titleLineEdit;
    QLineEdit *genreLineEdit;
    QLineEdit *releaseYearLineEdit;
    QLineEdit *likesLineEdit;
    QLineEdit *trailerLineEdit;
    QPushButton *addMovieButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 300);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        titleLineEdit = new QLineEdit(centralwidget);
        titleLineEdit->setObjectName("titleLineEdit");

        verticalLayout->addWidget(titleLineEdit);

        genreLineEdit = new QLineEdit(centralwidget);
        genreLineEdit->setObjectName("genreLineEdit");

        verticalLayout->addWidget(genreLineEdit);

        releaseYearLineEdit = new QLineEdit(centralwidget);
        releaseYearLineEdit->setObjectName("releaseYearLineEdit");

        verticalLayout->addWidget(releaseYearLineEdit);

        likesLineEdit = new QLineEdit(centralwidget);
        likesLineEdit->setObjectName("likesLineEdit");

        verticalLayout->addWidget(likesLineEdit);

        trailerLineEdit = new QLineEdit(centralwidget);
        trailerLineEdit->setObjectName("trailerLineEdit");

        verticalLayout->addWidget(trailerLineEdit);

        addMovieButton = new QPushButton(centralwidget);
        addMovieButton->setObjectName("addMovieButton");

        verticalLayout->addWidget(addMovieButton);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        titleLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Title", nullptr));
        genreLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Genre", nullptr));
        releaseYearLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Release Year", nullptr));
        likesLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Number of Likes", nullptr));
        trailerLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Trailer URL", nullptr));
        addMovieButton->setText(QCoreApplication::translate("MainWindow", "Add Movie", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
