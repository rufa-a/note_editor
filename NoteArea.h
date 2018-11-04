#ifndef NOTEAREA_H
#define NOTEAREA_H
#include <QtWidgets>

//static QPoint area_position;
//class MyLabel : public QLabel
//{
//public:
//    QWidget *parent;
//    MyLabel(QWidget *Parent = 0) : parent(Parent) {}
//    void mouseMoveEvent(QMouseEvent *e);
//};

class MyLine : public QWidget
{
public: int x1, y1, x2, y2;
    void draw(QPainter *Painter);
public: MyLine(int X1, int Y1, int X2, int Y2) : x1(X1), y1(Y1), x2(X2), y2(Y2) {}
};

//extern static QPoint area_position;

class NoteArea;
class NewNotes;
class NewScore;

class ExLines : public QWidget
{

//public:
//    int x, y;
    ExLines(/*QPoint &area_position*/);//: x(X), y(Y) {}
    QPoint ex_note_position;
    friend NoteArea;
    friend NewNotes;
//    QLabel *lbl_ex;

//     QPainter *note;

//    ~ExLines();

    MyLine *lines[11/*15*/];

protected:
    void paintEvent(QPaintEvent *event);
//    void mouseMoveEvent(QMoveEvent *event);
};



class NoteArea:public QWidget
{
//public:
    QString file_clef;
    QPixmap *px_clef;
    int x_ex, y_ex, first_x_ex, first_y_ex;
//    QLabel *lbl[8];
    /*My*/QLabel *lbl_ex;
//    QVBoxLayout *v_ex;

private:
    NoteArea(QWidget *parent = 0);

//    friend ExLines;
    QPoint position;

    friend NewNotes;
    friend NewScore;
//    QVBoxLayout *v_ex;
//    ~NoteArea();
    MyLine *line[8][5], *connectLine[8];

    ExLines *ex;

//    QPainter *note;
protected:
        //	обработчики событий
    void paintEvent(QPaintEvent *event);
//    void showEvent(QShowEvent *event);
//    void hideEvent(QHideEvent *event);

//    void mouse_event(DWORD dwFlags, DWORD dx, DWORD dy, DWORD dwData, ULONG_PTR dwExtraInfo);
    void mouseMoveEvent(QMouseEvent *);
//    void moveMouse(QMouseEvent *event);
};



#endif // NOTEAREA_H
