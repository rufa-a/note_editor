#ifndef MSNOTE_H
#define MSNOTE_H
#include <QtWidgets>
//class NewNotes;
//static int note_sign;
extern int note_sign;
class MsNote : public QWidget
{
public:
//    friend NewNotes;
    int x, y, w, h,//геометрия и координаты ноты самого виджета
    end_x, end_y,//конец хвоста ноты
    NoteSign = 3,//по умолчанию 3 - нет знака альтерации
    NotePauseTakt, TaktType,
    x_pos, y_pos,//координаты лэйбла на самом NoteArea
    MsNumber = 0;
    bool UpDown, LongTail;
    float NoteValue;
    void draw_note(QPainter *painter/*, int x, int y, int w, int h*/);
    MsNote(int note_pause, int takt_type,  float note_value = 0, int X = 0, int Y = 0, int W = 0, int H = 0, bool up_down = false,
           bool long_tail = false) :
        NotePauseTakt(note_pause), TaktType(takt_type), NoteValue(note_value), x(X), y(Y), w(W), h(H), UpDown(up_down), LongTail(long_tail)/*, NoteSign(note_sign)*/ {}
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
};

#endif // MSNOTE_H
