#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include <QtWidgets>
#define RUS(str) codec->toUnicode(str)
#include "NewScore.h"
class NewScore;
class NewNotes;
class StartWindow : public QWidget/*QMainWindow*///QWidget
{
//    class NewScore;
    Q_OBJECT
    QPushButton *btnExit, *btnCreate, *btnLoad;
    friend class NewScore;
    NewScore *wnNewScore;
    NewNotes *wnNewNotes;

public:
    StartWindow(/*QWidget *parent = 0*/);
    ~StartWindow();
public slots:
    void showNewScore();
    void openDir();
//    void showNewNotes();

};

extern StartWindow *w/* = new StartWindow*/;

#endif // STARTWINDOW_H
//extern StartWindow *w;
