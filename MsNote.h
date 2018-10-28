#ifndef MSNOTE_H
#define MSNOTE_H
#include <QtWidgets>
class MsNote : public QWidget
{
public:
    int x, y, w, h;
    void draw_note(QPainter *painter/*, int x, int y, int w, int h*/);
//    QWidget *p;
    MsNote(/*QWidget *parent,*/ int X, int Y, int W, int H) : /*p(parent),*/ x(X), y(Y), w(W), h(H) {}
    void paintEvent(QPaintEvent *);
};

#endif // MSNOTE_H
