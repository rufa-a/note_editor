#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QtWidgets>
#define RUS(str) codec->toUnicode(str)
#include "NewScore.h"

class MainWindow : public QMainWindow//QWidget
{
    Q_OBJECT
    QPushButton *btnExit, *btnCreate, *btnLoad;

    NewScore wnNewScore;
//    NewNotes wnNewNotes;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void showNewScore();
//    void showNewNotes();

};

#endif // MAINWINDOW_H
