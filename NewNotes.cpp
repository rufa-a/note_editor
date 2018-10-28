#include "NewNotes.h"

//#include <QSvgRenderer>
//#include <QtSvg>
//#include <QFont>
//#include <QTextCodec>

NewNotes::NewNotes()
{
    codec = QTextCodec::codecForName("UTF-8");
//    QTextCodec::setCodecForTr(codec);
    this->setWindowTitle(codec->toUnicode("Обработка событий"));

//    this->setStyleSheet("background-picture:");

//    setFont(QFont("Courier New", 18));



    QToolBar *tools =  new QToolBar(codec->toUnicode("Инструменты"));
    tools->addAction(QPixmap("C:/Users/User/qt_projects/try/try2/images/2b.png"), "1", this, SLOT(slotFunc()));
    tools->addAction(QPixmap("C:/Users/User/qt_projects/try/try2/images/2d.png"), "1", this, SLOT(slotFunc()));
//    tools->addФ




    scr = new QScrollArea(this);
    area = new NoteArea(scr);
    scr->setFixedSize(1150, 500);
    scr->setWidget(area);
    scr->setBackgroundRole(QPalette::Light);

    // = new QLabel(area);
    lblName = new QLabel(area);
    lblComp = new QLabel(area);
    lblName->setText("Name");
    lblName->setStyleSheet("font: 28pt 'Courier New' bond;");
    lblName->setGeometry(500, 5, lblName->width(), lblName->height());

    lblComp->setText("Composer");
    lblComp->setStyleSheet("font: 14pt 'Courier New';");
    lblComp->setGeometry(900, 25, lblComp->width(), lblComp->height());


    btn_exit = new QPushButton(codec->toUnicode("Завершить"),this );
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    QVBoxLayout *layout1 = new QVBoxLayout;
    QVBoxLayout *layout2 = new QVBoxLayout;
    mainLayout->addLayout(layout1);
    mainLayout->addLayout(layout2);
    layout2->addWidget(scr);
    layout2->addWidget(btn_exit);
    layout1->addWidget(tools);
    connect(btn_exit, SIGNAL(clicked(bool)),this,SLOT(close()));


//    lbl->setStyleSheet("font:  bold italic large 'FreeSerifMscore'");
//    uint a[] = {0x1d11e};///////////////////////////////////////////////////////////////////////////////////////////////////

//    QString s = QString::fromUcs4(a, 2);
//    s.toUtf8();
//    lbl->setFont(QFont("Courier New"));
//    lbl->setText(s);
//    lbl->setText(QString::fromUtf16(0x1d11e));///////////////////////////////////////////////////////////////////////////
//    lbl->setText(QChar(0x266a));

//    uint treble[] = {0x266a};

//    QString s = QString::fromUcs4(treble, 1);
//    lbl->setFont(QFont("Courier New"));
//    lbl->setText(s);

//    lbl->setText(QChar(0xd834dd1e));




//    QSvgRenderer rend(QString("C:/Users/User/qt_projects/try/try2/images/treble_clef.svg"));
//    QImage image(100, 100, QImage::Format_ARGB32);
//    image.fill(0xaaA08080);//partly transparent
//    QPainter p(&image);
//    rend.render(&p);
//    image.save("C:/Users/User/qt_projects/try/try2/images/treble_clef.png");

//    QSvgRenderer renderer(QString("C:/Users/User/qt_projects/try/try2/images/treble_clef.svg"));
//    QPixmap pm(100, 100);
//    pm.fill(0xaaA08080);
//    QPainter p(&pm);
//    renderer.render(&p, pm.rect());
//    lbl->setPixmap(pm/*.scaled(100, 100/*, Qt::KeepAspectRatio/)*/);

    ///////////////////////////
//    QPixmap px("C:/Users/User/qt_projects/try/try2/images/bass_clef.svg");

//    lbl->setPixmap(px.scaled(95, 95, Qt::KeepAspectRatio));///////////////////////////////////////////

//    lbl->setText(QString::fromUtf8("119072"));
//    QString str;
//    str[0] = QChar(0x0001d11e);
//    lbl->setText(str);

//    uint a[] = {0x1d11e};
//    QString s = "   " + QString::fromUcs4(a,0);
//    lbl->setText(s);
//    lbl->setText(QString::fromUtf8("0xF00x9D0x840x9E"));
//    lbl->setText(QChar::unicode(119070));
//    lbl->setStyleSheet("font: 50pt 'Courier New';");////////////////////////

//    lbl->setFont(QFont("CourierNew"));

//    uint cp = 0xD834DD1E;
//    lbl->setText(QString::fromUcs4(&cp, 1));


//    QPixmap px("C:/Users/User/qt_projects/try/try2/images/treble-clef-2400px.png");
////    lbl->setPixmap(px.scaled(95, 95, Qt::KeepAspectRatio));
//    int x1 = 5, x2 = 90, y1 = 108, y2 = 90;

    //ключи
    for (int i=0; i<8; i++){
        lbl_clef[i] = new QLabel(area);
    }

    //ключевые знаки
    for (int i=0; i<8; i++){
        lbl_signs[i] = new QLabel(area);
//        lbl_signs[i]->setAttribute(Qt::WA_DeleteOnClose);
    }
//    lbl_signs->setText(QChar(9839));

    fr_signature = new QFrame(area);//размер
    QVBoxLayout *v_signature = new QVBoxLayout();
    lbl_share = new QLabel;
    lbl_length = new QLabel;
    fr_signature->setLayout(v_signature);
//    fr_signature->setGeometry(40, 118, 54, 54);//4 пикселя : 3 пункта

//    v_signature->setGeometry(QRect(0, 0, 38, 52));
//    v_signature->setAlignment(Qt::AlignHCenter);
    v_signature->setContentsMargins(0, 0, 0, 10);
    lbl_share->setStyleSheet("font: 17pt 'Courier New' bond;");
    lbl_share->setAlignment(Qt::AlignCenter);
    lbl_share->setFixedSize(36, 23);
    lbl_length->setStyleSheet("font: 17pt 'Courier New' bond;");
    lbl_length->setAlignment(Qt::AlignCenter);
    lbl_length->setFixedSize(36, 23);
    v_signature->addWidget(lbl_share);
    v_signature->addWidget(lbl_length);
//    v_signature->setSpacing(0);
//    fr_signature->setStyleSheet("background-color: rgba(102, 204, 255, 50);");

    fr_tempo = new QFrame(area);
    lbl_note_tempo = new QLabel;
    str_temp = " = ";
    lbl_note_tempo->setStyleSheet("font: 14pt;");
    lbl_note_tempo->setText(QChar(0x2669));
    lbl_note_tempo->setAlignment(Qt::AlignRight);
    lbl_tempo = new QLabel;
    lbl_tempo->setStyleSheet("font: 11pt;");
    lbl_tempo->setText(str_temp);
    QHBoxLayout *h_temp = new QHBoxLayout(fr_tempo);
    h_temp->setMargin(0);
    h_temp->setSpacing(0);
    h_temp->addWidget(lbl_note_tempo);
    h_temp->addWidget(lbl_tempo);
    fr_tempo->setGeometry(20, 90, 70, 27);

//    new_note = new MsNote(5, 5, 12, 10);

//    note_scene =  new QGraphicsScene(this);
//    group_1 = new QGraphicsItemGroup();
//    note_scene->addItem(group_1);
//    note_scene->setSceneRect(0,0,50,50);
//    QPen penBlack(Qt::red); // Задаём чёрную кисть
//    group_1->addToGroup(note_scene->addLine(20,20, 100, 20, penBlack));

//////////////////////////////////////////////////////////////////////////////////////////////////
//    *lbl_note = new QLabel(scr); // на лэйбле рисуем ноту
//    for (int i = 0; i<3; i++){
//        lbl_note[i] = new QLabel(scr);
//    }

//    lbl_note[1] = new QLabel(area);
//    lbl_note[2] = new QLabel(area);
////    lbl_note->setStyleSheet("background-color: rgba(230, 204, 255, 50);");
//    new_note = new MsNote(0, 0, 11, 9);
//    QVBoxLayout *v_note = new QVBoxLayout(lbl_note);
//    lbl_note->setLayout(v_note);
//    v_note->addWidget(new_note);
//    v_note->setMargin(0);
//    lbl_note->setGeometry(0, 0, 50, 50);
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//    v_note->setMargin(0);
//    v_ex->setGeometry(QRect(0, 0, 50, 100));
//    lbl_note->setMouseTracking(true);

//    QWidget *w = new QWidget(area);
//    w->setStyleSheet("background-color: rgba(60, 204, 200, 50);");
//    w->setGeometry(150, 150, 50, 50);

//    emit clicked(area);
//     connect(area, SIGNAL(clicked()), this, SLOT(createNote(QMouseEvent *e)));//try to create a note
//    lbl_note = new QLabel *[100];
//    lbl_note = new QVector<QLabel>;
//    lbl_note.push_back(new QLabel);
//    QLabel *lbl = new QLabel;

//    *lbl_note = new QLabel(area);
////    lbl_note.append(new QLabel);
//    lbl_note[notes_amount]/*[notes_amount]*/->setStyleSheet("background-color: rgba(60, 204, 255, 50);");
//    new_note[notes_amount] = new MsNote(0, 0, 11, 9);
//    QVBoxLayout *v_note = new QVBoxLayout(lbl_note[notes_amount]);
//    lbl_note[notes_amount]/*[notes_amount]*/->setLayout(v_note);
//    v_note->addWidget(new_note[notes_amount]);
//    v_note->setMargin(0);

//    lbl_note << new QLabel(area);
}

void NewNotes::slotFunc(){
    QMessageBox::information(0, "Message", "Not implemented");
    QWidget *w = new QWidget(area);
    w->setStyleSheet("background-color: rgba(60, 204, 200, 50);");
    w->setGeometry(150, 150, 50, 50);
//    QPushButton *psh = new QPushButton("shiiiiiiiiit", area);
//    psh->setGeometry(0, 0, 50, 30);

}

//void NewNotes::draw_note(QPainter *painter){
//    painter->drawEllipse(QRect((( area->ex->area_position.x()-3)/25*25+10), (( area->ex->area_position.y()-8)/5*5+5), 11, 9));
//}

void NewNotes::mousePressEvent(QMouseEvent *e){ // Рисование ноты по нажатию ЛКМ
//    e->pos().x();
//    if (e->pos().x() >= area->ex->area_position.x() && e->button() == Qt::LeftButton){
//        QPainter note1(this);    //расположение ноты
//        note1.setPen(Qt::green);
//        note1.drawEllipse(QRect((( area->ex->area_position.x()-3)/25*25+10), (( area->ex->area_position.y()-8)/5*5+5), 11, 9));
//    }

    int px = area->ex->area_position.x();
    int ppx = area->lbl_ex->pos().x(); /////////////// позиция вспомогательной области
    int current_x = e->pos().x();

    int xx = e->pos().x() - scr->pos().x();//не то
    int xxx = area->lbl_ex->pos().x();//(area_position.x()-5)/25*25+9), ((area_position.y()-8)/5*5+5)
    if (e->button() == Qt::LeftButton && (e->pos().x() - scr->pos().x()) >= (area->lbl_ex->pos().x())/* + 20*/ &&
                                            (e->pos().y() - scr->pos().y()) >= area->lbl_ex->pos().y() &&
                                            (e->pos().y() - scr->pos().y()) <= (area->lbl_ex->pos().y() + area->lbl_ex->height())/*(area->ex->area_position.x() + 20)*/){
//        new_note = new MsNote(0, 0, 10, 8);
//        QVBoxLayout *v_note = new QVBoxLayout(lbl_note);
//        lbl_note->setLayout(v_note);
//        v_note->addWidget(new_note);

//        lbl_note[notes_amount] = new QLabel(area); // на лэйбле рисуем ноту
//    //    lbl_note->setStyleSheet("background-color: rgba(230, 204, 255, 50);");
//        new_note[notes_amount] = new MsNote(0, 0, 11, 9);
//        QVBoxLayout *v_note = new QVBoxLayout(lbl_note[notes_amount]);
//        lbl_note[notes_amount]->setLayout(v_note);
//        v_note->addWidget(new_note[notes_amount]);
//        v_note->setMargin(0);

        /*lbl_note[notes_amount] = new QLabel(area);*/ // на лэйбле рисуем ноту
    //    lbl_note->setStyleSheet("background-color: rgba(230, 204, 255, 50);");
//        lbl_note[notes_amount] = new QLabel(area);

//        *lbl_note = new QLabel(scr);

//        for (int i = 0; i<3; i++){
//            lbl_note[i] = new QLabel(scr);
//        }


//        lbl_note[notes_amount] = new QLabel(area);
//        lbl_note.append(new QLabel);
//        *lbl_note[notes_amount] = notes_amount;
//        lbl_note[notes_amount]/*[notes_amount]*/->setStyleSheet("background-color: rgba(60, 204, 255, 50);");
//        new_note[notes_amount] = new MsNote(0, 0, 11, 9);
//        QVBoxLayout *v_note = new QVBoxLayout(lbl_note[notes_amount]);
//        lbl_note[notes_amount]/*[notes_amount]*/->setLayout(v_note);
//        v_note->addWidget(new_note[notes_amount]);
//        v_note->setMargin(0);

//        QLabel *lbl = new QLabel(area);
//        lbl_note << new QLabel(area);
        lbl_note.append(new QLabel(area));

//        lbl_note.push_back(new QLabel);

//        lbl_note[notes_amount] = new QLabel(area);
        lbl_note[notes_amount]/*[notes_amount]*/->setStyleSheet("background-color: rgba(60, 204, 255, 50);");

        new_note.append(new MsNote(0,0,11,9));
//        new_note[notes_amount] = new MsNote(0, 0, 11, 9);
        QVBoxLayout *v_note/*[notes_amount]*/ = new QVBoxLayout(lbl_note[notes_amount]);
        lbl_note[notes_amount]/*[notes_amount]*/->setLayout(v_note/*[notes_amount]*/);
        v_note/*[notes_amount]*/->addWidget(new_note[notes_amount]);
        v_note/*[notes_amount]*/->setMargin(0);

        lbl_note[notes_amount]/*[notes_amount]*/->setGeometry(((e->pos().x() - scr->pos().x()-5)/25*25+9), ((e->pos().y() - scr->pos().y()-8)/5*5+5), 12, 10);
        lbl_note[notes_amount]->setVisible(true);


//        QWidget *w = new QWidget(area);
//        w->setStyleSheet("background-color: rgba(60, 204, 200, 50);");
//        w->setGeometry(150, 150, 50, 50);
//        QVBoxLayout *v = new QVBoxLayout();
//        w->setLayout(v);
//        v->addWidget(lbl_note[notes_amount]);


        qDebug() << "Value " << notes_amount << ": " << lbl_note[notes_amount];

        notes_amount++;


//        QPainter painter(new_note);
//        new_note->draw_note(&painter, 5, 5, 10, 10);
//        painter.drawEllipse(0, 0, 10, 8);
//        new_note = new MsNote(/*area, */area->ex->area_position.x() + area->pos().x(), area->ex->area_position.y() + area->pos().y(), 11, 10);
//        new_note = new MsNote(/*area,*/ /*e->pos().x() + *//*area->pos().x(),*/ /*e->pos().y() + *//*area->pos().y(), 11, 10*/);
//        note_scene->addText("loooooser");
//        note_scene->setSceneRect(0,0,50,50);
//        QPen penBlack(Qt::black); // Задаём чёрную кисть
//        group_1->addToGroup(note_scene->addLine(20,20, 100, 20, penBlack));
//        note_scene->addWidget(new_note);
//        area->installEventFilter(this);
//        repaint();

    }
}

//void NewNotes::createNote(QMouseEvent *e){
//    if (e->button() == Qt::LeftButton && (e->pos().x() - scr->pos().x()) >= (area->lbl_ex->pos().x())/* + 20*/ &&
//                                                (e->pos().y() - scr->pos().y()) >= area->lbl_ex->pos().y() &&
//                                                (e->pos().y() - scr->pos().y()) <= (area->lbl_ex->pos().y() + area->lbl_ex->height())){
//        lbl_note[notes_amount] = new QLabel();
//        lbl_note[notes_amount]->setStyleSheet("background-color: rgba(60, 204, 255, 50);");
//        new_note[notes_amount] = new MsNote(0, 0, 11, 9);
//        QVBoxLayout *v_note = new QVBoxLayout(lbl_note[notes_amount]);
//        lbl_note[notes_amount]->setLayout(v_note);
//        v_note->addWidget(new_note[notes_amount]);
//        v_note->setMargin(0);



//        lbl_note[notes_amount]->setGeometry(((e->pos().x() - scr->pos().x()-5)/25*25+9), ((e->pos().y() - scr->pos().y()-8)/5*5+5), 12, 10);

//        notes_amount++;
//    }
//}

//void NewNotes::paintEvent(QPaintEvent *){
//    QPainter *painter = new QPainter(new_note);
////    new_note->draw_note(painter, 0, 0, 10, 11);
//    painter->drawEllipse(0, 0, 10, 8);
////    note_scene->setSceneRect(0,0,50,50);
////    QPen penBlack(Qt::black); // Задаём чёрную кисть
////    group_1->addToGroup(note_scene->addLine(20,20, 100, 20, penBlack));
//}

//bool NewNotes::eventFilter(QObject *watched, QEvent *event){
//    QEvent::Type t = event->type();
//    if ((watched->objectName() == new_note->objectName()) && (event->type() == QEvent::Paint)) {
////        repaint();
//        QPainter painter(area);//(/*area/*this*/); // создаем контент рисования на Холсте
////        painter.begin(area);
//    //    if (e->pos().x() >= area->ex->area_position.x()){
//    //        update();
//            painter.setPen(Qt::blue);
//            new_note->draw_note(&painter);
//            return true;
//    }
//    return false;
//}

NewNotes::~NewNotes()
{

    delete lbl_length;
    delete lbl_share;
    delete fr_signature;


//    delete[] lbl_signs;
    for (int i=0; i<8; i++){
        delete lbl_signs[i];
    }
    delete area;
    delete scr;
//    qDeleteAll(lbl_note);
}
