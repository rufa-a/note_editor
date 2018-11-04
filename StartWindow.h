#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include <QtWidgets>
#define RUS(str) codec->toUnicode(str)
#include "NewScore.h"

class StartWindow : public QWidget/*QMainWindow*///QWidget
{
    Q_OBJECT
    QPushButton *btnExit, *btnCreate, *btnLoad;

    NewScore wnNewScore;
//    NewNotes wnNewNotes;

public:
    StartWindow(/*QWidget *parent = 0*/);
    ~StartWindow();
public slots:
    void showNewScore();
    void openDir();
//    void showNewNotes();

};

#endif // STARTWINDOW_H
