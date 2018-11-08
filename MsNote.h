#ifndef MSNOTE_H
#define MSNOTE_H
#include <QtWidgets>
//class NewNotes;
extern int note_sign/* = 3*/;
class MsNote : public QWidget
{
public:
//    friend NewNotes;
    int x, y, w, h, end_x, end_y,
    NoteSign = 3;//по умолчанию 3 - нет знака альтерации
    bool UpDown,LongTail;
    float NoteValue;
    void draw_note(QPainter *painter/*, int x, int y, int w, int h*/);
//    QWidget *p;
    MsNote(/*QWidget *parent,*/ int X, int Y, int W, int H, float note_value, bool up_down, bool long_tail/*, int note_sign*/) :
        x(X), y(Y), w(W), h(H), NoteValue(note_value), UpDown(up_down), LongTail(long_tail)/*, NoteSign(note_sign)*/ {}
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
};

#endif // MSNOTE_H
