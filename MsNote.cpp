#include "MsNote.h"
void MsNote::draw_note(QPainter *painter/*, int x, int y, int w, int h*/){
    painter->drawEllipse(x, y, w, h);
    //рисуем хвостик ноты
    painter->setPen(QPen(Qt::black, 1));
    if (NoteValue < 1){//если нота не целая
        if (!LongTail){
            if (UpDown){
                painter->drawLine(x + w, y + h/2, x + w, y - 30);//хвостик вверх
                end_x = x + w;
                end_y = y - 30;
            }else{
                painter->drawLine(x - 1, y + h/2, x - 1, y + 40); //x-1 с учетом толщины кружочка
                end_x = x - 1;
                end_y = y + 40;
            }
        }else{
            if (UpDown){
                painter->drawLine(x + w, y + h/2, x + w, 60);//хвостик вверх
                end_x = x + w;
                end_y = 60;
            }else{
                painter->drawLine(x - 1, y + h/2, x - 1, 60);
                end_x = x - 1;
                end_y = 60;
            }
        }
    }
    //рисуем дополнительные линии
    if (y < 30)
        painter->drawLine(x - 5, 30, x + 15, 30);
    if (y < 20)
        painter->drawLine(x - 5, 20, x + 15, 20);
    if (y < 10)
        painter->drawLine(x - 5, 10, x + 15, 10);
    if (y + h > 90)
        painter->drawLine(x - 5, 90, x + 15, 90);
    if (y + h > 100)
        painter->drawLine(x - 5, 100, x + 15, 100);
    if (y + h > 110)
        painter->drawLine(x - 5, 110, x + 15, 110);


    //рисуем хвостики

//    painter->drawPath(QPainterPath(QPointF(15, 5)));
//    painter->drawPath(QPainterPath(QPointF(20, 10)));

//    tail->moveTo(15, 5);
//    tail->arcTo(20, 10, 5, 5, 20, 10);
//    tail->closeSubpath();
//    QPainter *p = new QPainter;
//    p->drawLine(0, 0, 15, 15);
//
//
    if (NoteValue < 0.13 && NoteValue > 0.12){
        QPainterPath tail;
//    tail.quadTo(15, 5, 20, 10);

//    tail.moveTo(end_x/* + 9*/, end_y/* + 30*/);
//    tail.cubicTo(end_x + 9, end_y + 15, end_x + 8, end_y + 17, end_x + 7, end_y + 30);
//    painter->drawPath(tail);

//    painter->setBrush(Qt::transparent);
//    tail.moveTo(0,0);
//    tail.cubicTo(50, 40, 13, 80, 13, 80);
//    painter->drawPath(tail);
//    painter->setPen(QPen(Qt::red, 1));
//    painter->drawLine(50, 40, 13, 80);
//    painter->setPen(QPen(Qt::blue, 1));
//    painter->drawLine(0,0, 13, 80);
//    qDebug() << "end_x + 8 " << end_x + 8 << "end_y + 15 " << end_y + 15;
//    qDebug() << "end_x + 3 " << end_x + 3 << "end_y + 17 " << end_y + 17;
        painter->setPen(QPen(Qt::black, 2));
        painter->setBrush(Qt::transparent);

//        tail.cubicTo(end_x + 18, end_y + 15, end_x + 4, end_y + 30, end_x + 4, end_y + 30);
        if (UpDown){
            tail.moveTo(end_x + 1, end_y + 1);
            tail.cubicTo(end_x + 4, end_y + 15, end_x + 15, end_y + 15, end_x + 6, end_y + 30);
        }else{
            tail.moveTo(end_x + 1, end_y);
            tail.cubicTo(end_x + 4, end_y - 15, end_x + 15, end_y - 15, end_x + 9, end_y - 28);
        }
        painter->drawPath(tail);
    }

    if (NoteValue < 0.07){
        QPainterPath tail;
        painter->setPen(QPen(Qt::black, 2));
        painter->setBrush(Qt::transparent);

        if (UpDown){
            tail.moveTo(end_x + 1, end_y + 1);
            tail.cubicTo(end_x + 2, end_y + 8, end_x + 8, end_y + 8, end_x + 8, end_y + 17);
            tail.moveTo(end_x + 1, end_y + 8);
            tail.cubicTo(end_x + 3, end_y + 19, end_x + 14, end_y + 19, end_x + 5, end_y + 34);
        }else{
            tail.moveTo(end_x + 1, end_y);
            tail.cubicTo(end_x + 2, end_y - 7, end_x + 8, end_y - 7, end_x + 10, end_y - 19);
            tail.moveTo(end_x + 1, end_y - 6);
            tail.cubicTo(end_x + 4, end_y - 20, end_x + 14, end_y - 20, end_x + 9, end_y - 28);
        }
        painter->drawPath(tail);
    }
}

void MsNote::paintEvent(QPaintEvent *){
    QPainter painter(this);
//    painter.setBrush(Qt::black);
    painter.setPen(QPen(Qt::black, 2));

    if (NoteValue < 0.5)
        painter.setBrush(Qt::black);
//    QPainterPath tail();
    draw_note(&painter);

}
