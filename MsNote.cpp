#include "MsNote.h"
void MsNote::draw_note(QPainter *painter/*, int x, int y, int w, int h*/){
//    painter->setPen(QColor::black());
    painter->drawEllipse(x, y, w, h);
}

void MsNote::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setPen(Qt::black);
    draw_note(&painter);
}
