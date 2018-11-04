#include "NewNotes.h"

//#include <QSvgRenderer>
//#include <QtSvg>
//#include <QFont>
//#include <QTextCodec>

NewNotes::NewNotes(QWidget *parent): QMainWindow(parent)
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




//    /*note_window*/scr = new QMdiArea(this);/////////////////////
//    QVBoxLayout *scr_layout = new QVBoxLayout(/*note_window*/scr);
//    /*note_window*/scr->setLayout(scr_layout);
////    scr = new QScrollArea(/*note_window*/);//QScrollArea(this);


//    area = new NoteArea(/*note_window*/scr);
//    scr_layout->addWidget(area);
//    /*note_window*/scr->resize(1150, 500);
//    /*note_window*/scr->setMaximumWidth(1150);////////////////////////////////
//    /*note_window*/scr->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
//       /* note_window*/scr->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
//        setCentralWidget(/*note_window*/scr);

    scr = new QScrollArea(this);
       area = new NoteArea(scr);
       scr->setFixedSize(1150, 500);
       scr->setWidget(area);
       scr->setBackgroundRole(QPalette::Light);

//    scr->setWidget(area);


//    scr->setBackgroundRole(QPalette::Light);

    // = new QLabel(area);
    lblName = new QLineEdit(area);
    lblComp = new QLineEdit(area);
    lblName->setText("Name");
    lblName->setStyleSheet("font: 24pt 'Courier New' bond; border:  1px dashed");
    lblName->setGeometry(10, 5, 1100, 1.5*lblName->height());
    lblName->setAlignment(Qt::AlignCenter);
    lblName->setMaxLength(50);
//    lblName->setFrame(false);

    lblComp->setText("Composer");
    lblComp->setStyleSheet("font: 14pt 'Courier New';  border:  1px dashed");
    lblComp->setGeometry(10, 55, 1100, lblComp->height());
    lblComp->setAlignment(Qt::AlignRight);
    lblComp->setMaxLength(60);
//    lblComp->setFrame(false);



//    btn_exit = new QPushButton(codec->toUnicode("Завершить"),this );

    QWidget *w = new QWidget(this);

    QHBoxLayout *mainLayout = new QHBoxLayout(/*this*/);
    this->setCentralWidget(w);
    w->setLayout(mainLayout);


    QVBoxLayout *layout1 = new QVBoxLayout;
    QVBoxLayout *layout2 = new QVBoxLayout;
    mainLayout->addLayout(layout1);
    mainLayout->addLayout(layout2);
    layout2->addWidget(scr);
//    layout2->addWidget(btn_exit);
    layout1->addWidget(tools);
//    connect(btn_exit, SIGNAL(clicked(bool)),this,SLOT(SaveFile()));


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

//    QMenuBar *menu = new QMenuBar;
//    QMenu *file = new QMenu();
//    file->addMenu("&File");
//    menu->addMenu(file);

//    QSlider *s1 = new QSlider(Qt::Horizontal, w);
//    QSlider *s2 = new QSlider(Qt::Vertical, w);
//    QSpinBox *sb = new QSpinBox;

//    QHBoxLayout *L = new QHBoxLayout(w);
//    L->addWidget(s1);
//    L->addWidget(s2);
//    L->addWidget(sb);

        QMenu *fileMenu = new QMenu("&Файл");
        QMenu *editMenu = new QMenu("&Редактировать");
        QMenu *helpMenu = new QMenu("&Помощь");
        helpMenu->addAction("&AboutQt", this, SLOT(aboutQt()));

        fileMenu->addAction("Создать...", this, SLOT(create_note()));
        fileMenu->addAction("Открыть...", this, SLOT(create_note()));
        fileMenu->addAction("Сохранить", this, SLOT(SaveFile()));
        fileMenu->addAction("Сохранить как...", this, SLOT(SaveFile()));
        fileMenu->addAction("В&ыход", this, SLOT(close()));

//        QHBoxLayout *h = new QHBoxLayout;

        QMenuBar * mainMenu = new QMenuBar;
        mainMenu->addMenu(fileMenu);
        mainMenu->addMenu(helpMenu);
//        w->setLayout(layout);
//        QVBoxLayout * layout = new QVBoxLayout;

        mainLayout->setMenuBar(mainMenu);
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

    int px = area->ex->ex_note_position.x();
    int ppx = area->lbl_ex->pos().x(); /////////////// позиция вспомогательной области
    int current_x = e->pos().x();

    int xx = e->pos().x() - scr->pos().x();//не то
    int xxx = area->lbl_ex->pos().x();//(ex_note_position.x()-5)/25*25+9), ((ex_note_position.y()-8)/5*5+5)
    if (e->button() == Qt::LeftButton && (e->pos().x() - scr->pos().x()) >= (area->lbl_ex->pos().x())/* + 20*/ &&
                                            (e->pos().y() - scr->pos().y()) >= area->lbl_ex->pos().y() &&
                                            (e->pos().y() - scr->pos().y()) <= (area->lbl_ex->pos().y() + area->lbl_ex->height())/*(area->ex->ex_note_position.x() + 20)*/){

        lbl_note.append(new QLabel(area));
        lbl_note[notes_amount]/*[notes_amount]*/->setStyleSheet("background-color: rgba(60, 204, 255, 50);");


        new_note.append(new MsNote(/*0,0,*/(area->ex->ex_note_position.x()-5)/25*25+9,
                                   (area->ex->ex_note_position.y()-10)/5*5+5, 11,9));
//        new_note[notes_amount] = new MsNote(0, 0, 11, 9);
        QVBoxLayout *v_note/*[notes_amount]*/ = new QVBoxLayout(lbl_note[notes_amount]);
        lbl_note[notes_amount]/*[notes_amount]*/->setLayout(v_note/*[notes_amount]*/);
        v_note/*[notes_amount]*/->addWidget(new_note[notes_amount]);
        v_note/*[notes_amount]*/->setMargin(0);

//        lbl_note[notes_amount]/*[notes_amount]*/->setGeometry(((e->pos().x() - scr->pos().x()-5)/25*25+9), ((e->pos().y() - scr->pos().y()-8)/5*5+5), 30, 120/*12, 10*/);
        lbl_note[notes_amount]->setGeometry(area->x_ex, area->y_ex, 30, 120);
        lbl_note[notes_amount]->setVisible(true);

        qDebug() << "Value " << notes_amount << ": " << lbl_note[notes_amount];

        notes_amount++;
        area->x_ex += 30;/////
        int pos_x_area = scr->pos().x();
        int width_area = area->width();
        int pos_x_ex = area->x_ex;
        if (area->x_ex > /*area->pos().x() + area->width()*/area->width()){
            area->y_ex += 140;
            area->x_ex = area->first_x_ex;
        }


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

void NewNotes::SaveFile(){
    QString filename = QFileDialog::getSaveFileName(
                        this,
                        tr("Save Document"),
                        QDir::currentPath(),
                        tr("Documents (*.msnote)") );
    if( !filename.isNull()){
        qDebug(filename.toUtf8() );

        QFile new_file(filename);
        if (!new_file.open(QIODevice::WriteOnly)) {
            // error message
        } else {
            QTextStream data_stream(&new_file);
            data_stream << lblName->text();
            data_stream.flush();
            new_file.close();
        }

    }
}

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
