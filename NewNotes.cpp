#include "NewNotes.h"

//#include <QSvgRenderer>
//#include <QtSvg>
//#include <QFont>
//#include <QTextCodec>
int note_sign;// = 3;
NewNotes::NewNotes(QWidget *parent): QMainWindow(parent)
{
    codec = QTextCodec::codecForName("UTF-8");
    this->setWindowTitle(codec->toUnicode("Обработка событий"));

    note_sign = 3;

//    ms_values =  new QToolBar(codec->toUnicode("Длительности"));
    ms_values = new QMenu("Длительности");
    ms_values->setTitle("Длительности нот/пауз");
    note1 = new QAction("Целая", ms_values);
    note1->setIcon(QIcon("C:/Users/User/qt_projects/try/try2/images/note_values/1note.svg.png"));
    note1->setToolTip("Целая");
    ms_values->addAction(note1);
    note2 = new QAction("Половинная", ms_values);
    note2->setIcon(QIcon("C:/Users/User/qt_projects/try/try2/images/note_values/1note.svg.png"));
    note2->setToolTip("Половинная");
    ms_values->addAction(note2);
    note4 = new QAction("Четвертная", ms_values);
    note4->setIcon(QIcon("C:/Users/User/qt_projects/try/try2/images/note_values/1note.svg.png"));
    note4->setToolTip("Четвертная");
    ms_values->addAction(note4);
    note8 = new QAction("Восьмая", ms_values);
    note8->setIcon(QIcon("C:/Users/User/qt_projects/try/try2/images/note_values/1note.svg.png"));
    note8->setToolTip("Восьмая");
    ms_values->addAction(note8);
    note16 = new QAction("Шестнадцатая", ms_values);
    note16->setIcon(QIcon("C:/Users/User/qt_projects/try/try2/images/note_values/1note.svg.png"));
    note16->setToolTip("Шестнадцатая");
    QString  menuStyle(
               "QMenu::item{"
               "background-color: rgb(0, 170, 0);"
               "color: rgb(255, 255, 255);"
               "}"
               "QMenu::item:selected{"
               "background-color: rgb(0, 85, 127);"
               "color: rgb(255, 255, 255);"
               "}"
            );
//    note16->setStyleSheet("QToolTip { color: black; background-color: lightblue; border: 1px solid white; }");
    ms_values->addAction(note16);
//    ms_values->setStyleSheet(menuStyle);
    note16->setObjectName("unique");
    setStyleSheet("QToolButton#unique{border: 3px solid #FF00FF;}");

//    QToolButton* toolButton = new QToolButton(this);//Выпадающий список
//      toolButton->setToolTip(tr("Добавить новый узел"));
////      toolButton->setIcon(QIcon(":/addNodeToolButton.png"));
//      toolButton->setMenu(ms_values);
//      toolButton->setPopupMode(QToolButton::InstantPopup);

//    tools->addAction()
//    note1 = new QToolButton(ms_values);
//    note1->setIcon(QIcon("C:/Users/User/qt_projects/try/try2/images/note_values/1note.svg.png"));
//    note1->setToolTip("Целая");
//    note2 = new QToolButton(ms_values);
//    note2->setIcon(QIcon("C:/Users/User/qt_projects/try/try2/images/note_values/2note.svg.png"));
//    note2->setToolTip("Половинная");
//    note4 = new QToolButton(ms_values);
//    note4->setIcon(QIcon("C:/Users/User/qt_projects/try/try2/images/note_values/4note.svg.png"));
//    note4->setToolTip("Четвертная");
//    note8 = new QToolButton(ms_values);
//    note8->setIcon(QIcon("C:/Users/User/qt_projects/try/try2/images/note_values/8note.svg.png"));
//    note8->setToolTip("Восьмая");
//    note16 = new QToolButton(ms_values);
//    note16->setIcon(QIcon("C:/Users/User/qt_projects/try/try2/images/note_values/16note.svg.png"));
//    note16->setToolTip("Шестнадцатая");
//    QAction *asdf = new QAction("asdf");
//    asdf->setEnabled();
//    ms_ms->add

//    ms_values->addWidget(note1);
//    ms_values->addWidget(note2);
//    ms_values->addWidget(note4);
//    ms_values->addWidget(note8);
//    ms_values->addWidget(note16);
    connect(note1, SIGNAL(triggered()), this, SLOT(set1Value()));
    connect(note2, SIGNAL(triggered()), this, SLOT(set2Value()));
    connect(note4, SIGNAL(triggered()), this, SLOT(set4Value()));
    connect(note8, SIGNAL(triggered()), this, SLOT(set8Value()));
    connect(note16, SIGNAL(triggered()), this, SLOT(set16Value()));
//    connect(note1, SIGNAL(clicked(bool)), this, SLOT(set1Value()));
//    connect(note2, SIGNAL(clicked(bool)), this, SLOT(set2Value()));
//    connect(note4, SIGNAL(clicked(bool)), this, SLOT(set4Value()));
//    connect(note8, SIGNAL(clicked(bool)), this, SLOT(set8Value()));
//    connect(note16, SIGNAL(clicked(bool)), this, SLOT(set16Value()));
//    ms_values->addAction(QPixmap("C:/Users/User/qt_projects/try/try2/images/note_values/1note.svg.png"), "Целая", this,SLOT(set1Value()));
//    ms_values->addAction(QPixmap("C:/Users/User/qt_projects/try/try2/images/note_values/2note.svg.png"), "Половинная", this,SLOT(set2Value()));
//    ms_values->addAction(QPixmap("C:/Users/User/qt_projects/try/try2/images/note_values/4note.svg.png"), "Четвертная", this, SLOT(set4Value()));
//    ms_values->addAction(QPixmap("C:/Users/User/qt_projects/try/try2/images/note_values/8note.svg.png"), "Восьмая", this, SLOT(set8Value()));
//    ms_values->addAction(QPixmap("C:/Users/User/qt_projects/try/try2/images/note_values/16note.svg.png"), "Шестнадцатая", this, SLOT(set16Value()));
//    tools->addФ

    note_pause = new QToolBar(codec->toUnicode("Ввод нот/пауз"), this);
    note_pause->addAction(QPixmap("C:/Users/User/qt_projects/try/try2/images/note_values/1note.svg.png"), "Ввод нот", this,SLOT(NoteInput()));
    note_pause->addSeparator();
    note_pause->addAction(QPixmap("C:/Users/User/qt_projects/try/try2/images/pause_values/pause_icon.svg"), "Ввод пауз", this,SLOT(PauseInput()));
    note_pause->addSeparator();
    note_pause->addAction(QPixmap("C:/Users/User/qt_projects/try/try2/images/pause_values/4rest.svg.png"), "Ввод случайных знаков", this,SLOT(PauseInput()));
//    QToolButton *note = new QToolButton(note_pause);
//    note->setIcon(QIcon("C:/Users/User/qt_projects/try/try2/images/note_values/8note.svg.png"));
////    note->setText("Ввод нот");
//    note_pause->addSeparator();
//    note_pause->addWidget(note);
//    note->setEnabled(false);
//    note->setToolTip("Нажмите для ввода нот");

    note_signs = new QToolBar("Случайные знаки");
    note_signs->addAction(QPixmap("C:/Users/User/qt_projects/try/try2/images/signs/2sharp.svg"), "Дубль-диез", this,SLOT(Add2Sharp()));
    note_signs->addAction(QPixmap("C:/Users/User/qt_projects/try/try2/images/signs/sharp.svg"), "Диез", this,SLOT(AddSharp()));
    note_signs->addAction(QPixmap("C:/Users/User/qt_projects/try/try2/images/signs/natural.svg"), "Бекар", this,SLOT(AddNatural()));
    note_signs->addAction(QPixmap("C:/Users/User/qt_projects/try/try2/images/signs/flat.svg"), "Бемоль", this,SLOT(AddFlat()));
    note_signs->addAction(QPixmap("C:/Users/User/qt_projects/try/try2/images/signs/2flat.svg"), "Дубль-бемоль", this,SLOT(Add2Flat()));



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
       scr->resize(1150, 500);
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
//    mainLayout->setMenuBar(note_pause);
    layout2->addWidget(scr);
    layout1->addWidget(note_pause);
//    layout1->addWidget(ms_ms);
    layout1->addWidget(ms_values);
    layout1->addWidget(note_signs);



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
//    lbl_clef.append(new QLabel(area));
//    for (int i=0; i<8; i++){
//        lbl_clef[i] = new QLabel(area);
//    }

    //ключевые знаки
//    lbl_signs.append(new QLabe/l(area));
//    for (int i=0; i<8; i++){
//        lbl_signs[i] = new QLabel(area);
//        lbl_signs[i]->setAttribute(Qt::WA_DeleteOnClose);
//    }
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
    fileMenu->addAction("Открыть...", this, SLOT(LoadFile()));
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


//        string_note_file = new QString();
//        scr->viewport();
        scr->setMouseTracking(true);
//        area->setMouseTracking(true);
}

void NewNotes::slotFunc(){
    QMessageBox::information(0, "Message", "Not implemented");
}

void NewNotes::NoteInput(){
    note_pause_input = 1;
    area->appear_ex = true;
}

void NewNotes::PauseInput(){
    note_pause_input = -1;
    area->appear_ex = false;
}

void NewNotes::set1Value(){
    notes_value = 1.0;
    note_value = 1;

//    string_note_file = "C:/Users/User/qt_projects/try/try2/images/note_values/1note.svg.png";
}
void NewNotes::set2Value(){
    notes_value = 0.5;
    note_value = 2;
}
void NewNotes::set4Value(){
    notes_value = 0.25;
    note_value = 4;
}
void NewNotes::set8Value(){
    notes_value = 0.125;
    note_value = 8;
}
void NewNotes::set16Value(){
    notes_value = 0.0625;
    note_value = 16;
}

void NewNotes::Add2Sharp(){
    note_sign = 2;
}

void NewNotes::AddSharp(){
    note_sign = 1;
}

void NewNotes::AddNatural(){
    note_sign = 0;
}

void NewNotes::AddFlat(){
    note_sign = -1;
}

void NewNotes::Add2Flat(){
    note_sign = -2;
}

//void NewNotes::draw_note(QPainter *painter){
//    painter->drawEllipse(QRect((( area->ex->area_position.x()-3)/25*25+10), (( area->ex->area_position.y()-8)/5*5+5), 11, 9));
//}

void NewNotes::mousePressEvent(QMouseEvent *e){ // Рисование ноты по нажатию ЛКМ

    /*if (e->button() == Qt::LeftButton && (e->pos().x() - scr->pos().x()) >= (area->x_ex) &&
                                            (e->pos().y() - scr->pos().y()) >= area->y_ex &&
                                            (e->pos().y() - scr->pos().y()) <= (area->y_ex + area->lbl_ex->height()) &&
                                            (e->pos().x() - scr->pos().x()) <= (area->x_ex + area->lbl_ex->width()))*/
    if (e->button() == Qt::LeftButton && area->mapFromParent(e->pos()).x() - scr->pos().x() >= (area->x_ex) &&
                                          area->mapFromParent(e->pos()).y() - scr->pos().y() >= (area->y_ex) &&
            area->mapFromParent(e->pos()).x() - scr->pos().x() <= (area->x_ex) + area->lbl_ex->width() &&
            area->mapFromParent(e->pos()).y() - scr->pos().y() <= (area->y_ex) + area->lbl_ex->height()){/*(area->ex->ex_note_position.x() + 20)*/


//        lbl_ms.append(new QLabel(area));
//        lbl_ms[notes_amount]/*[notes_amount]*/->setStyleSheet("background-color: rgba(60, 204, 255, 50);");


////        new_note.append(new MsNote(/*0,0,*/(area->ex->ex_note_position.x()-5)/25*25+9,
////                                   (area->ex->ex_note_position.y()-8)/5*5+5, 11,9, notes_value));
////        new_note[notes_amount] = new MsNote(0, 0, 11, 9);
//        QVBoxLayout *v_note/*[notes_amount]*/ = new QVBoxLayout(lbl_ms[notes_amount]);
//        lbl_ms[notes_amount]/*[notes_amount]*/->setLayout(v_note/*[notes_amount]*/);
////        lbl_note[notes_amount]->setPixmap(notes_value_image);
////        v_note/*[notes_amount]*/->addWidget(new_note[notes_amount]);
////        v_note/*[notes_amount]*/->setMargin(0);

////        lbl_note[notes_amount]/*[notes_amount]*/->setGeometry(((e->pos().x() - scr->pos().x()-5)/25*25+9), ((e->pos().y() - scr->pos().y()-8)/5*5+5), 30, 120/*12, 10*/);
//        lbl_ms[notes_amount]->setGeometry(area->x_ex, area->y_ex, 30, 120);

////        notes_value_image.append(new QPixmap(string_note_file));
////        notes_value_image[notes_amount] = string_note_file;
//        lbl_note.append(new QLabel(lbl_ms[notes_amount]));
////        v_note->addWidget(lbl_note[notes_amount]);
////        v_note->setMargin(0);
////        QTextStream(&str) << "C:/Users/User/qt_projects/try/try2/images/note_values/" << note_value << "note.svg.png";
//        lbl_note[notes_amount]->setPixmap(QPixmap(/*string_note_file*/"C:/Users/User/qt_projects/try/try2/images/note_values/" + QVariant(note_value).toString() + "_note.png").scaled(20, 30));
//        lbl_note[notes_amount]->setGeometry(area->ex->ex_note_position.x(), area->ex->ex_note_position.y(), 20, 30);
//        lbl_note[notes_amount]/*[notes_amount]*/->setStyleSheet("background-color: rgba(255, 60, 255, 50);");
//        lbl_ms[notes_amount]->setVisible(true);//иначе не отображается
//        lbl_note[notes_amount]->setVisible(true);




        lbl_note.append(new QLabel(area));
        lbl_note[ms_amount]/*[notes_amount]*/->setStyleSheet("background-color: rgba(60, 204, 255, 50);");

                int a1 = (area->ex->ex_note_position.y()-8)/5*5+5;
                int a2 = (area->ex->height()/* - 5*/) / 2;
        if (note_pause_input == 1){//если вводим ноты
            if (note_value != 1){
                if ((area->ex->ex_note_position.y()-8)/5*5+5 >= (area->ex->height()/* - 5*/) / 2)//в какую строну рисовать хвостик
                    up_down = true;
                 else up_down = false;
                if (up_down){
                    if ((area->ex->ex_note_position.y()-8)/5*5+2 - 40 > area->ex->height()/2)
                        long_tail = true;
                    else long_tail = false;
                }else{
                    if ((area->ex->ex_note_position.y()-8)/5*5+2 + 40 < area->ex->height()/2)
                        long_tail = true;
                    else long_tail = false;
                }
            }
            new_note.append(new MsNote(/*0,0,*/note_pause_input, 0, notes_value, (area->ex->ex_note_position.x()-5)/40*40+19,//*25*25+9*/,
                                       (area->ex->ex_note_position.y()-8)/5*5+6/*5*/, 11,9, up_down, long_tail/*, note_sign*/));
    //        new_note[notes_amount] = new MsNote(0, 0, 11, 9);
            QVBoxLayout *v_note/*[notes_amount]*/ = new QVBoxLayout(lbl_note[ms_amount]);
            lbl_note[ms_amount]/*[notes_amount]*/->setLayout(v_note/*[notes_amount]*/);
            v_note/*[notes_amount]*/->addWidget(new_note[notes_amount]);
            v_note/*[notes_amount]*/->setMargin(0);

        }else if (note_pause_input == -1){//если вводим паузы
            new_note.append(new MsNote(note_pause_input, 0, notes_value));//для записи
            lbl_note[ms_amount]->setPixmap(QPixmap(/*string_note_file*/"C:/Users/User/qt_projects/try/try2/images/pause_values/" +
                                                      QVariant(note_value).toString() + "_rest.svg.png").scaled(30/*40*/, 40));

        }
        new_note[ms_amount]->MsNumber = note_value;
        lbl_note[ms_amount]->setGeometry(area->x_ex, area->y_ex, /*30*/40, 120);
        lbl_note[ms_amount]->setVisible(true);
        new_note[ms_amount]->x_pos = area->x_ex;
        new_note[ms_amount]->y_pos = area->y_ex;
        area->x_ex += /*30*/lbl_note[ms_amount]->width();/////для переноса области вспомогательных линий
        ms_amount++;
        notes_amount++;

        takt_value += notes_value;


        if (fabs(takt_value - share_length) < 0.001){//рисуем тактовую линию
//            note_pause_input = 0;
            lbl_note.append(new QLabel(area));
            lbl_note[ms_amount]/*[notes_amount]*/->setStyleSheet("background-color: rgba(60, 204, 255, 50);");
            new_note.append(new MsNote(0, 1, 0));
            QVBoxLayout *v_note/*[notes_amount]*/ = new QVBoxLayout(lbl_note[ms_amount]);
            lbl_note[ms_amount]/*[notes_amount]*/->setLayout(v_note/*[notes_amount]*/);
            v_note/*[notes_amount]*/->addWidget(new_note[notes_amount]);
            v_note/*[notes_amount]*/->setMargin(0);
            lbl_note[ms_amount]->setGeometry(area->x_ex, area->y_ex, /*30*/10, 120);
            lbl_note[ms_amount]->setVisible(true);


            new_note[ms_amount]->x_pos = area->x_ex;
            new_note[ms_amount]->y_pos = area->y_ex;
            area->x_ex += /*30*/lbl_note[ms_amount]->width();
            ms_amount++;
            notes_amount++;
            takt_value = 0;
        }
        if (share_length < 1){
            note1->setEnabled(false);
            if (share_length < 0.5){
                note2->setEnabled(false);
                if (share_length < 0.25){
                    note4->setEnabled(false);
                    if (share_length < 0.125){
                        note8->setEnabled(false);
                        if (share_length < 0.0625){
                            note16->setEnabled(false);
                        }
                    }
                }
            }
        }
        else{
            note1->setEnabled(true);
            note2->setEnabled(true);
            note4->setEnabled(true);
            note8->setEnabled(true);
            note16->setEnabled(true);
        }

        if (fabs (share_length - takt_value) < 1){
            note1->setEnabled(false);
            if (fabs (share_length - takt_value) < 0.5){
                note2->setEnabled(false);
                if (fabs (share_length - takt_value) < 0.25){
                    note4->setEnabled(false);
                    if (fabs (share_length - takt_value) < 0.125){
                        note8->setEnabled(false);
                        if (fabs (share_length - takt_value) < 0.0625){
                            note16->setEnabled(false);
                        }
                        else note16->setEnabled(true);
                    }
                    else {
                        note8->setEnabled(true);
                        note16->setEnabled(true);
                    }
                }
                else {
                    note4->setEnabled(true);
                    note8->setEnabled(true);
                    note16->setEnabled(true);
                }
            }
            else {
                note2->setEnabled(true);
                note4->setEnabled(true);
                note8->setEnabled(true);
                note16->setEnabled(true);
            }
        }
        else {
            note1->setEnabled(true);
            note2->setEnabled(true);
            note4->setEnabled(true);
            note8->setEnabled(true);
            note16->setEnabled(true);
        }

        //        lbl_note[notes_amount]/*[notes_amount]*/->setGeometry(((e->pos().x() - scr->pos().x()-5)/25*25+9), ((e->pos().y() - scr->pos().y()-8)/5*5+5), 30, 120/*12, 10*/);


//                area->ex->setVisible(false);
        area->lbl_ex->setVisible(false);


//        qDebug() << "Value " << notes_amount << ": " << lbl_note[notes_amount];





        int pos_x_area = scr->pos().x();
        int width_area = area->width();
        int pos_x_ex = area->x_ex;
        if (area->x_ex + /*30*/40 > /*area->pos().x() + area->width()*/area->width()){
            area->y_ex += 140;//перенос области вспогательных линий на следующий нотоносец
            area->x_ex = area->first_x_ex;

            area->y += 90;//следующий нотоносец
            for (int i = 0; i < 5; i++){
                area->line.append(new MyLine(area->x1, area->y, area->x2, area->y));
                area->y += 10;
            }
            lbl_clef.append(new QLabel(area));//ключ
            lbl_clef[lbl_clef.size() - 1]->setPixmap(QPixmap(file_clef).scaled(w_clef, h_clef, Qt::KeepAspectRatio));
            lbl_clef[lbl_clef.size() - 1]->setGeometry(x_clef, y_clef, w_clef, h_clef);
            lbl_clef[lbl_clef.size() - 1]->setVisible(true);
            lbl_signs.append(new QLabel(area));//ключевые знаки
            lbl_signs[lbl_signs.size() - 1]->setPixmap(QPixmap(file_sign).scaled(w_sign, h_sign, Qt::KeepAspectRatio));
            lbl_signs[lbl_signs.size() - 1]->setGeometry(x_sign, y_sign, w_sign, h_sign);
            lbl_signs[lbl_signs.size() - 1]->setVisible(true);

            y_clef += 140;
            y_sign += 140;
            area->stave_amount += 1;
//            lbl_clef[0]->setGeometry(0,0,30,70);
        }
        int ra = area->y_ex;
        int asdf = area->ex->height();
        int qwer = area->height();
        if (area->y_ex + area->ex->height() > area->height()){//ляботает
//            area->resize((1115, (area->y + 140)));
//            area->y += 90;
//            area->line.append(new MyLine(20, area->y, 1110, area->y));
//            area->y += 140;
            area->resize(QSize(1115, area->height() + 150));
        }
    }
}

void NewNotes::SaveFile(){
    QString filename = QFileDialog::getSaveFileName(
                        this,
                        "Сохранить файл",
                        QDir::currentPath(),
                        "Документы (*.msnote)");
    if( !filename.isNull()){
        qDebug(filename.toUtf8() );

        QFile new_file(filename);
        if (!new_file.open(QIODevice::WriteOnly)) {
            // error message
        } else {
            QTextStream data_stream(&new_file);
            data_stream << lblName->text() << "\r\n" << lblComp->text() << "\r\n" << lbl_tempo->text() << "\r\n" <<
                           area->stave_amount << "\r\n" << ms_amount << "\r\n" <<
                           file_clef << "\r\n" << x_clef<< "\r\n" << y_clef << "\r\n" << w_clef << "\r\n" << h_clef
                           << "\r\n" << file_sign << "\r\n" << x_sign << "\r\n" << y_sign << "\r\n" << w_sign << "\r\n" << h_sign
                           << "\r\n" << lbl_share->text().toInt() << "\r\n" << lbl_length->text().toInt() << "\r\n" ;
            for (int i = 0; i < ms_amount; i++){
                data_stream << new_note[i]->NotePauseTakt << "\r\n" << new_note[i]->TaktType << "\r\n"  << new_note[i]->NoteValue << "\r\n"
                            << new_note[i]->x << "\r\n"  << new_note[i]->y << "\r\n"  << new_note[i]->w << "\r\n"
                            << new_note[i]->h << "\r\n"  << new_note[i]->UpDown << "\r\n"  << new_note[i]->LongTail << "\r\n"  <<
                               new_note[i]->end_x << "\r\n"  << new_note[i]->end_y << "\r\n"  << new_note[i]->NoteSign << "\r\n"
                            << new_note[i]->x_pos << "\r\n"  << new_note[i]->y_pos << "\r\n"  <<
                               new_note[i]->MsNumber  << "\r\n" ;
            }
            data_stream.flush();
            new_file.close();
        }

    }
    this->close();
}



void NewNotes::DeleteWidgets(){
    for (int i=0; i<notes_amount; i++)
        delete new_note[i];
//               qDeleteAll(new_note[i]);
    new_note.clear();
//           delete[] lbl_ms;
//           delete[] *lbl_note;
    for (int i=0; i<ms_amount; i++)
        delete lbl_note[i];
//               qDeleteAll(lbl_note[i]);
    lbl_note.clear();
    for (int i = 0; i < area->stave_amount; i++)
        delete lbl_clef[i];
    lbl_clef.clear();
    for (int i = 0; i < area->stave_amount; i++)
        delete lbl_signs[i];
    lbl_signs.clear();
    for (int i = 0; i < area->stave_amount*5; i++)
        delete area->line[i];
    area->line.clear();
    area->x1 = 20, area->x2 = 1110, area->y = 130;
    ms_amount = 0;
    notes_amount = 0;
    area->stave_amount = 1;
}

void NewNotes::LoadFile(){
//    DeleteWidgets();

    QString filename = QFileDialog::getOpenFileName(this, "Открыть файл", QDir::currentPath(), "Документы (*.msnote)");
    QFile load_file(filename);
    if (!load_file.open(QIODevice::ReadOnly)){
        //error message
    } else {

//        DeleteWidgets();
        close();

        QTextStream data_stream(&load_file);
//        qDebug(data_stream.readAll().toUtf8());
        QString name = data_stream.readLine();
        QString comp = data_stream.readLine();
        QString share, length;
        data_stream >> /*name >> comp >>*/ str_temp >> area->stave_amount >> ms_amount >>
                       file_clef >> x_clef >> y_clef >> w_clef >> h_clef >>
                       file_sign >> x_sign >> y_sign >> w_sign >> h_sign >>
                       share >> length;
//        QString adsfg = data_stream.readLine();
        lblName->setText(name);
        lblComp->setText(comp);
        this->show();

        //первый нотоносец


        y_clef -= 140*area->stave_amount;
        y_sign -= 140*area->stave_amount;
        if (w_sign == 0){
            lbl_signs.append(new QLabel(area));
            lbl_signs[0]->setVisible(false);
        }
        for (int i = 0; i < area->stave_amount; i++){
            for (int j =0; j < 5; j++){
                area->line.append(new MyLine(area->x1, area->y, area->x2, area->y));
                area->y += 10;
            }
            area->y += 90;


            lbl_clef.append(new QLabel(area));
        //    x_clef = 20, y_clef = 118, w_clef = 30, h_clef = 70;
    //        x_sign = 50, y_sign = 111;//координаты ключевых знаков
            lbl_clef[i]->setPixmap(QPixmap(file_clef).scaled(w_clef, h_clef, Qt::KeepAspectRatio));////////////крашится непонятно почему и когда
            lbl_clef[i]->setGeometry(x_clef, y_clef, w_clef, h_clef);//px.width(), px.height());///////////
            lbl_clef[i]->setVisible(true);
            y_clef += 140;

            if (w_sign != 0){
                lbl_signs.append(new QLabel(area));
                lbl_signs[i]->setVisible(true);
                lbl_signs[i]->setPixmap(QPixmap(file_sign).scaled(w_sign, h_sign, Qt::KeepAspectRatio));
                lbl_signs[i]->setGeometry(x_sign, y_sign, w_sign, h_sign);
                y_sign += 140;
            }

        }

        lbl_tempo->setText(str_temp);


        fr_signature->setGeometry(x_signature+w_sign, y_signature+10, 36, 44);
//        area->x_ex = area->first_x_ex = x_signature + w_sign + fr_signature->width() + 10;

//        area->y_ex = area->first_y_ex = y_signature - 28/*48*/;

        int takt_type;
        QString UpDown, LongTail;
        for (int i = 0; i<ms_amount; i++){
            data_stream >> note_pause_input >> takt_type >> notes_value;/* << new_note[i]->x <<
                           new_note[i]->y << new_note[i]->w << new_note[i]->h << new_note[i]->UpDown << new_note[i]->LongTail <<
                           new_note[i]->end_x << new_note[i]->end_y << new_note[i]->NoteSign << new_note[i]->x_pos << new_note[i]->y_pos;*/
//            if (note_pause_input == 0){
                new_note.append(new MsNote(note_pause_input, takt_value, notes_value));
                data_stream >> new_note[i]->x >> new_note[i]->y >> new_note[i]->w >> new_note[i]->h >> UpDown >>
                               LongTail >> new_note[i]->end_x >> new_note[i]->end_y >>new_note[i]->NoteSign >> new_note[i]->x_pos >> new_note[i]->y_pos >>
                               new_note[i]->MsNumber ;
//                data_stream.
                if (LongTail == "1")
                    new_note[i]->LongTail = true;
                else new_note[i]->LongTail = false;
                if (UpDown == "1")
                    new_note[i]->UpDown = true;
                else new_note[i]->UpDown = false;
//            }

            lbl_note.append(new QLabel(area));
            QVBoxLayout *v_note/*[notes_amount]*/ = new QVBoxLayout(lbl_note[i]);
            lbl_note[i]/*[notes_amount]*/->setLayout(v_note/*[notes_amount]*/);
            v_note/*[notes_amount]*/->addWidget(new_note[i]);
            v_note/*[notes_amount]*/->setMargin(0);
            if (note_pause_input == 0)
                lbl_note[i]->setGeometry(new_note[i]->x_pos, new_note[i]->y_pos, /*30*/10, 120);
            else lbl_note[i]->setGeometry(new_note[i]->x_pos, new_note[i]->y_pos, /*30*/40, 120);
            lbl_note[i]->setVisible(true);
            if (note_pause_input == -1){//if pause
                lbl_note[i]->setPixmap(QPixmap(/*string_note_file*/"C:/Users/User/qt_projects/try/try2/images/pause_values/" +
                                                QVariant(new_note[i]->MsNumber).toString() + "_rest.svg.png").scaled(30/*40*/, 40));
            }


//            data_stream >> new_note[i]
        }

        area->x_ex = new_note[ms_amount - 1]->x_pos + lbl_note[ms_amount - 1]->width();
        area->y_ex = new_note[ms_amount - 1]->y_pos/* + lbl_note[ms_amount]->width()*/;

        if (area->x_ex + /*30*/40 > /*area->pos().x() + area->width()*/area->width()){
            area->y_ex += 140;//перенос области вспогательных линий на следующий нотоносец
            area->x_ex = area->first_x_ex;

            area->y += 90;//следующий нотоносец
            for (int i = 0; i < 5; i++){
                area->line.append(new MyLine(area->x1, area->y, area->x2, area->y));
                area->y += 10;
            }
            lbl_clef.append(new QLabel(area));//ключ
            lbl_clef[lbl_clef.size() - 1]->setPixmap(QPixmap(file_clef).scaled(w_clef, h_clef, Qt::KeepAspectRatio));
            lbl_clef[lbl_clef.size() - 1]->setGeometry(x_clef, y_clef, w_clef, h_clef);
            lbl_clef[lbl_clef.size() - 1]->setVisible(true);
            lbl_signs.append(new QLabel(area));//ключевые знаки
            lbl_signs[lbl_signs.size() - 1]->setPixmap(QPixmap(file_sign).scaled(w_sign, h_sign, Qt::KeepAspectRatio));
            lbl_signs[lbl_signs.size() - 1]->setGeometry(x_sign, y_sign, w_sign, h_sign);
            lbl_signs[lbl_signs.size() - 1]->setVisible(true);

            y_clef += 140;
            y_sign += 140;
            area->stave_amount += 1;
//            lbl_clef[0]->setGeometry(0,0,30,70);
        }

        note1->setEnabled(true);
        note2->setEnabled(true);
        note4->setEnabled(true);
        note8->setEnabled(true);
        note16->setEnabled(true);

    }
}

void NewNotes::closeEvent(/*bool change_flag,*/ QCloseEvent *event){
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "NewNotes",
                                                                    ("Сохранить изменения?"),
                                                                    QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                    QMessageBox::Yes);
    if (resBtn == QMessageBox::Cancel) {
           event->ignore();
       } else {
        if (resBtn == QMessageBox::No){
           event->accept();

//           delete[] *new_note;
           DeleteWidgets();

//           delete[] lbl_ms;
//           delete
        }
        else{ //Вызвать
            QString filename = QFileDialog::getSaveFileName(
                                this,
                                "Сохранить",
                                QDir::currentPath(),
                                "Документы(*.msnote)" );
            if( !filename.isNull() ){
                qDebug(filename.toUtf8() );
                event->accept();

     //           delete[] *new_note;
                DeleteWidgets();

     //           delete[] lbl_ms;
     //           delete
            }
            else
                event->ignore();
        }

       }
}

NewNotes::~NewNotes()
{

    delete lbl_length;
    delete lbl_share;
    delete fr_signature;


//    delete[] lbl_signs;
//    for (int i=0; i<6/*8*/; i++){
//        delete lbl_signs[i];
//    }
    delete area;
    delete scr;
//    qDeleteAll(lbl_note);
}
