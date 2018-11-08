#ifndef MSNOTE_H
#define MSNOTE_H
#include <QtWidgets>
class MsNote : public QWidget
{
public:
    int x, y, w, h, end_x, end_y;
    bool UpDown,LongTail;
    float NoteValue;
    void draw_note(QPainter *painter/*, int x, int y, int w, int h*/);
//    QWidget *p;
    MsNote(/*QWidget *parent,*/ int X, int Y, int W, int H, float note_value, bool up_down, bool long_tail) :
        x(X), y(Y), w(W), h(H), NoteValue(note_value), UpDown(up_down), LongTail(long_tail) {}
    void paintEvent(QPaintEvent *);
};

#endif // MSNOTE_H
