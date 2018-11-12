#include "NoteArea.h"
//extern static QPoint area_position;
//void MyLabel::mouseMoveEvent(QMouseEvent *e){
//    update();
//}

void MyLine::draw(QPainter *Painter)
{
    Painter->drawLine(x1,y1, x2, y2);
}

ExLines::ExLines(){
    setStyleSheet("background-color: rgba(102, 204, 255, 50);");//фон+прозрачность
    int x1 = 0, x2 = 40, y = 10;
    for (int i=0; i<11/*15*/; i++){
        lines[i]=new MyLine(x1,y, x2, y);// создаем объект Линия
        y += 10;
    }
    this->resize(40, 120);
    setMouseTracking(true);
}

void ExLines::paintEvent(QPaintEvent *){    //рисование дополнительных мигающих линий
    QPainter painter(this);    // создаем контент рисования на Холсте
    painter.setPen(Qt::blue);      // задаем голубое Перо
    for (int i=0; i<11/*15*/; i++){
        lines[i]->draw(&painter);         // рисуем доп линию
    }
    QPainter note(this);    //расположение ноты
    note.setPen(Qt::red);
    note.drawEllipse(QRect(((ex_note_position.x()-5)/40*40+/*9*/19), ((ex_note_position.y()-8)/5*5+5), 11, 9));//рисуем кружочек в области дополнительных линий
    //x - серединка линии(области разделяются по 25), y - между линиями
    //    note.drawEllipse(QRect(ex_note_position.x(), /*((ex_note_position.y()-3)/5*5+3)*/ex_note_position.y(), 10, 7));
}

//void ExLines::mouseMoveEvent(QMoveEvent *event){
////    setVisible(false);
//    //    QPoint p = lbl_ex->pos();
//        QPoint position = event->pos();    //где расположена мышь на экране в целом
////       area_position = position - lbl_ex->pos();   //координаты мыши относительно (в) notearea
//        if ((position.x() >= 0) && (position.x() <= /*(x_ex + 10)*/500) && (position.y() >= 0) && (position.y() <= 500)){//для рисования кружочка в области доп линий
//    //
////            lbl_ex->setGeometry(QRect(x_ex, y_ex - 50, 500, 170));
////            lbl_ex->setVisible(true);
//            setVisible(true);
//        }
//        else{
////            lbl_ex->setVisible(false);
//            setVisible(false);
//        }
////        lbl_ex->update();
//        update();



//    //    delete ex;

//}

NoteArea::NoteArea(QWidget *parent)
{
//    setFixedSize(QSize(1115,1250)); // фиксируем размер Холста
    resize(QSize(1115, 970/*1250*/));
//    this->setStyleSheet("color: white");
//    int x1 = 20, x2 = 1110, y = 130;

//    for (int j=0; j<6/*8*/; j++){
//        for (int i=0; i<5/*30*/; i++){
////            if (i % 5 == 0)
////                y += 90;//следующий нотоносец
////            line[j][i]=new MyLine(x1,y, x2, y);// создаем линии нотоносца
//            line.append(new MyLine(x1, y, x2, y));
//            y += 10;

//        }
//        connectLine[j] = new MyLine(x2, y-50, x2, y-10);//убрать

//    }
    setMouseTracking(true);

    ex = new ExLines();
    lbl_ex = new QLabel(this);
    lbl_ex->setStyleSheet("background-color: rgba(60, 204, 255, 50);");
    QVBoxLayout *v_ex = new QVBoxLayout(lbl_ex);
    lbl_ex->setLayout(v_ex);
    v_ex->addWidget(ex);
    v_ex->setMargin(0);
//    v_ex->setGeometry(QRect(0, 0, 50, 100));
    lbl_ex->setMouseTracking(true);
    lbl_ex->setVisible(false);

//    lbl_ex->setStyleSheet("background-color: rgba(50, 204, 255, 50);");
//    lbl_ex->setVisible(false);


}

//void Area::showEvent(QShowEvent *)
//{
//    myTimer=startTimer(50);      // включаем таймер(мб вариант для проигрывания)
//}
void NoteArea::paintEvent(QPaintEvent *)    //рисование 6(8) нотоносцев
{
    update();
    QPainter painter(this);
    painter.setPen(Qt::black);
//    line1[0]->draw(&painter);
//    for (int j=0; j<6/*8*/; j++){
        for (int i=0; i<5*stave_amount; i++){
//            if (i % 5 == 0)
//                y += 90;//следующий нотоносец
            line/*[j]*/[i]->draw(&painter);         // рисуем Линию
        }
//        connectLine[j]->draw(&painter);
//    }
}


void NoteArea::mouseMoveEvent(QMouseEvent *event){//появление области вспомогательных линий
//    ex->update();
//    position = event->pos();    //где расположена мышь на экране в целом
//    ex->area_position = position - ex->pos();   //координаты мыши относительно (в) notearea
//    if ((position.x() >= /*x_ex*/0) && (position.x() <= /*(x_ex + 10)*/500) && (position.y() >= /*y_ex*/0) && (position.y() <= 500)){//для рисования кружочка в области доп линий
//        ex->setVisible(true);
//    }
//    else{
//        ex->setVisible(false);
//    }



//
//v_ex->update();

//lbl_ex->update();

//ex->setVisible(false);
//    QPoint p = lbl_ex->pos();
    ex->update();
    position = event->pos();    //где расположена мышь на экране в целом
    ex->ex_note_position = position - lbl_ex->pos();   //координаты мыши в области доп линий

    if ((position.x() >= (x_ex)) && (position.x() < (x_ex + 40)) && (position.y() >= y_ex) &&
            (position.y() <= (y_ex+120)) /*&& appear_ex*/){//для рисования кружочка в области доп линий
        lbl_ex->setGeometry(QRect(x_ex, y_ex, 40, 120/*160*/));
        if (!appear_ex){
            ex->setVisible(false);
            lbl_ex->setVisible(true);
        }else{

            lbl_ex->setVisible(true);
            ex->setVisible(true);
        }
    }
    else{
        lbl_ex->setVisible(false);
        ex->setVisible(false);
    }
//    lbl_ex->update();
//    ex->update();
//    delete ex;
}

//void NoteArea::mousePressEvent(QMouseEvent *e){

//}

//NoteArea::~NoteArea()
//{
//    delete line;
//}

//ExLines::~ExLines(){
//    delete lines;
//}
