#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include "Service.h"
#include "UserService.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    QTableWidget* tableWidget;
    QLineEdit* titleInput;
    QLineEdit* genreInput;
    QLineEdit* yearInput;
    QLineEdit* likesInput;
    QLineEdit* trailerInput;
    Service* service;
    UserService* userService;

    void populateTable();

private slots:
    void onAddMovie();
    void onUpdateMovie();
    void onDeleteMovie();
    void onDisplayMovies();
};

#endif // MAINWINDOW_H
