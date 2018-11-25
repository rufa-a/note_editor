#include "MsNote.h"
//extern int note_sign = 3;
//MsNote::MsNote(int note_pause, int takt_type, float note_value, int X, int Y, int W, int H, bool up_down, bool long_tail){
//    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotCustomMenuRequested(QPoint)));
//}

void MsNote::draw_note(QPainter *painter/*, int x, int y, int w, int h*/){
//    painter->setPen(QPen(Qt::black));
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
                painter->drawLine(x - 1, y + h/2, x - 1, y + 40); //x-1 с учетом толщины ноты
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
    if (NotePauseTakt == 1){
        QPainter painter(this);
    //    painter.setBrush(Qt::black);
        painter.setPen(QPen(Qt::black, 2));

        if (NoteValue < 0.5)
            painter.setBrush(Qt::black);
    //    QPainterPath tail();
        draw_note(&painter);

        QPainter sign_painter(this);
        sign_painter.setPen(QPen(Qt::black, 2));
        if (NoteSign == 2/* || NoteSignHover == 2*/){
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
        if (NoteSign == 1/* || NoteSignHover == 1*/){
            sign_painter.drawLine(x - 9, y - 5, x - 9, y + 14);
            sign_painter.drawLine(x - 5, y - 7, x - 5, y + 12);
            sign_painter.drawLine(x - 11, y + 2, x - 3, y - 2);
            sign_painter.drawLine(x - 11, y + 11, x - 3, y + 7);
        }

        if (NoteSign == 3/* || NoteSignHover == 3*/){
            sign_painter.drawLine(x - 11, y - 7, x - 11, y + 10);
            sign_painter.drawLine(x - 5, y - 1, x - 5, y + 16);
            sign_painter.drawLine(x - 11, y + 1, x - 5, y - 1);
            sign_painter.drawLine(x - 11, y + 12, x - 5, y + 10);
        }
        if (NoteSign == -1/* || NoteSignHover == -1*/){
            QPainterPath half_heart;
            half_heart.moveTo(x - 10, y);
            half_heart.cubicTo(x + 5, y - 5, x - 9, y + 12, x - 10, y + 12);

            sign_painter.drawPath(half_heart);
            sign_painter.drawLine(x - 10, y - 12, x - 10, y + 12);
        }
        if (NoteSign == -2/* || NoteSignHover == -2*/){
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
    else if (NotePauseTakt == 0){//рисуем тактовую линию
        if (TaktType == 1){
            QPainter painter(this);
            painter.setPen(QPen(Qt::black));
            painter.drawLine(8, 40, 8, 80);
        }
        if (TaktType == 0){//end takt
            QPainter painter(this);
            painter.setPen(QPen(Qt::black));
            painter.drawLine(5, 40, 5, 80);
            painter.setPen(QPen(Qt::black, 3));
            painter.drawLine(11, 41, 11, 79);
        }
        if (TaktType == -2){
            QPainter painter(this);
            painter.setPen(QPen(Qt::black));
            painter.drawLine(6, 40, 6, 80);
            painter.setPen(QPen(Qt::black, 3));

            painter.drawLine(10, 41, 10, 79);
            painter.setPen(QPen(Qt::black, 1));
            painter.setBrush(Qt::black);
//            painter.drawEllipse(1, 54, 3, 3);
//            painter.drawEllipse(1, 64, 3, 3);
            painter.drawEllipse(QPoint(4, 55), 1, 1);
            painter.drawEllipse(QPoint(4, 65), 1, 1);
        }
        if (TaktType == 2){
            QPainter painter(this);
            painter.setPen(QPen(Qt::black, 3));
            painter.drawLine(4, 41, 4, 79);

            painter.setPen(QPen(Qt::black));
            painter.drawLine(8, 41, 8, 79);

            painter.setPen(QPen(Qt::black, 1));
            painter.setBrush(Qt::black);
            painter.drawEllipse(QPoint(10, 55), 1, 1);
            painter.drawEllipse(QPoint(10, 65), 1, 1);
        }
        if (TaktType == 3){
            QPainter painter(this);
            painter.setPen(QPen(Qt::black));
            painter.drawLine(4, 40, 4, 80);
            painter.drawLine(12, 41, 12, 79);
            painter.setPen(QPen(Qt::black, 3));

            painter.drawLine(8, 41, 8, 79);


            painter.setPen(QPen(Qt::black, 1));
            painter.setBrush(Qt::black);
            painter.drawEllipse(QPoint(2, 55), 1, 1);
            painter.drawEllipse(QPoint(2, 65), 1, 1);
            painter.drawEllipse(QPoint(14, 55), 1, 1);
            painter.drawEllipse(QPoint(14, 65), 1, 1);
        }
    }

}

void MsNote::enterEvent(QEvent *e){
//    this->setStyleSheet("background-color: rgba(255, 100, 255, 50);");
//    setStyleSheet(/*"QWidget{background: white;}"*/
//                                       "QWidget:hover{background: rgba(150, 90, 255, 50);}");
    if (NotePauseTakt == 1 /*&& NoteSignHover != 5 && NoteSignHover != 7*/){
//        if (NoteSign != 0){

////            int sign = NoteSign;
//            NoteSignHover = note_sign;

//            sign_hover = NoteSign;//запоминаем текущее значение знака
//            NoteSign = 0;
//        } else {
//            NoteSignHover = note_sign;
//        }
        if (!enter_sign)
            sign_hover = NoteSign;
//        NoteSignHover = note_sign;
        NoteSign = note_sign;
        this->update();
        enter_sign = true;
        leave_sign = false;
    }
    setCursor( QCursor( Qt::PointingHandCursor ));
}

void MsNote::leaveEvent(QEvent *e){//////////////////////////
//    setStyleSheet("background-color: rgba(0, 0, 0, 0);");
//    setStyleSheet(/*"QWidget{background: white;}"*/
//                                       "QWidget:hover{background: rgba(150, 90, 255, 50);}");
//    if (NoteSign == 3){
//        NoteSignHover = 3;
//    } else {

    //    note_sign = NoteSignHover;

    if (NotePauseTakt == 1 && !leave_sign/* && NoteSignHover != 10*/ /*&& (NoteSignHover != 6 && NoteSignHover != 7)*/){
//        note_sign = NoteSign;
        if  (NoteSignHover != note_sign)
            NoteSign = sign_hover;
        NoteSignHover = 6;
        this->update();
        enter_sign = false;
        leave_sign = true;
    }
//        sign_hover = NoteSignHover;
//        NoteSignHover = 0;
//        note_sign = sign;
//    }

}

void MsNote::mousePressEvent(QMouseEvent *e){
    if (e->button() == Qt::LeftButton){
        if (NotePauseTakt == 1){
//            setStyleSheet("{background: rgba(150, 120, 255, 50);}");
            setStyleSheet("background-color: rgba(60, 204, 255, 50);");


            NoteSign = note_sign;
            NoteSignHover = note_sign;
            this->update();
//            sign_hover = note_sign;
        }
    }

    if (e->button() == Qt::RightButton){
//        emit RightClick(e);
        emit RightClickNote(e, this);
    }
}
