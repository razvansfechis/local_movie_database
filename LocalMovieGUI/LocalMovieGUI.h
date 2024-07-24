#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_LocalMovieGUI.h"

class LocalMovieGUI : public QMainWindow
{
    Q_OBJECT

public:
    LocalMovieGUI(QWidget *parent = nullptr);
    ~LocalMovieGUI();

private:
    Ui::LocalMovieGUIClass ui;
};
