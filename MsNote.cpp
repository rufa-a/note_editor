#include "MsNote.h"
//extern int note_sign = 3;
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
    qDebug() << "end_x: " << end_x << "y: " << end_y;
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

    if (NoteValue < 0.13 && NoteValue > 0.12){
        QPainterPath tail;

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

    QPainter sign_painter(this);
    sign_painter.setPen(QPen(Qt::black, 2));
    if (NoteSign == 2){
        sign_painter.setPen(QPen(Qt::black, 1));
        sign_painter.drawLine(x - 13, y, x - 4, y + 9);
        sign_painter.drawLine(x - 4, y + 1, x - 13, y + 9);

//        sign_painter.drawLine(x - 11, y - 2, x - 4, y + 9);
//        sign_painter.drawLine(x - 4, y + 1, x - 11, y + 7);


        sign_painter.setBrush(Qt::black);
        sign_painter.drawRect(x - 13, y, 3, 3);
        sign_painter.drawRect(x - 7, y, 3, 3);
        sign_painter.drawRect(x - 13, y + 6, 3, 3);
        sign_painter.drawRect(x - 7, y + 6, 3, 3);

    }
    if (NoteSign == 1){
        sign_painter.drawLine(x - 9, y - 5, x - 9, y + 14);
        sign_painter.drawLine(x - 5, y - 7, x - 5, y + 12);
        sign_painter.drawLine(x - 11, y + 2, x - 3, y - 2);
        sign_painter.drawLine(x - 11, y + 11, x - 3, y + 7);
    }

    if (NoteSign == 0){
        sign_painter.drawLine(x - 11, y - 7, x - 11, y + 10);
        sign_painter.drawLine(x - 5, y - 1, x - 5, y + 16);
        sign_painter.drawLine(x - 11, y + 1, x - 5, y - 1);
        sign_painter.drawLine(x - 11, y + 12, x - 5, y + 10);
    }
    if (NoteSign == -1){
        QPainterPath half_heart;
        half_heart.moveTo(x - 10, y);
        half_heart.cubicTo(x + 5, y - 5, x - 9, y + 12, x - 10, y + 12);

        sign_painter.drawPath(half_heart);
        sign_painter.drawLine(x - 10, y - 12, x - 10, y + 12);
    }
    if (NoteSign == -2){
        QPainterPath half_heart;
        half_heart.moveTo(x - 10, y);
        half_heart.cubicTo(x + 5, y - 5, x - 9, y + 12, x - 10, y + 12);

        half_heart.moveTo(x - 16, y);
        half_heart.cubicTo(x - 1, y - 5, x - 15, y + 12, x - 16, y + 12);

        sign_painter.drawPath(half_heart);
        sign_painter.drawLine(x - 10, y - 12, x - 10, y + 12);
        sign_painter.drawLine(x - 16, y - 12, x - 16, y + 12);
    }

}

void MsNote::mousePressEvent(QMouseEvent *e){
    this->update();
//    NoteSign = 1;//ляботает
    NoteSign = note_sign;
    qDebug() << "end_x: " << end_x << "y: " << end_y;
//    if (e->button() == Qt::LeftButton && NoteSign != 3){
//        if (NoteSign == 1){
////            QPainter *sign_painter = new QPainter(this);
////            sign_painter->drawLine(0,0,5,5);


//        }
//    }
}
