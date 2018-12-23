#include "StartWindow.h"
//extern StartWindow *w;
StartWindow::StartWindow()/*(QWidget *parent): QMainWindow(parent)*///QWidget(parent)
{
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    this->setWindowTitle(RUS("Редактор партитур - Стартовое окно"));
    wnNewScore = new NewScore(/*this*/);
//    setWindowIcon(QIcon("C:/Users/User/qt_projects/try/try2/images/ms_note.png"));
    setWindowIcon(QIcon(":/images/ms_note.png"));
//    QDir dir;
//    qDebug() << dir.cd(QDir::currentPath());
//    qDebug() << QDir::cd(QDir::currentPath());
//    wnNewScore->setParent(this);
//    setWindowModified(true);
//    wnNewNotes = new NewNotes();

//    QMenu *fileMenu = new QMenu("&Файл");
//    QMenu *helpMenu = new QMenu("&Помощь");
//    helpMenu->addAction("&AboutQt", this, SLOT(aboutQt()));
//    fileMenu->addAction("В&ыход", this, SLOT(close()));

//    QHBoxLayout *h = new QHBoxLayout;

//    QMenuBar * mainMenu = new QMenuBar;
//    mainMenu->addMenu(fileMenu);
//    mainMenu->addMenu(helpMenu);
//    QVBoxLayout * layout = new QVBoxLayout;
//    layout->setMenuBar(mainMenu);



//    QWidget *w = new QWidget(this);
    QVBoxLayout *vl = new QVBoxLayout;//////////////

////    w->setBackgroundRole(QPalette::Light);
////    w->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
//    this->setCentralWidget(w);
    this/*w*/->setLayout(vl);
//    w->setLayout(layout);

//    QMenuBar *menu = new QMenuBar;
//    QMenu *file = new QMenu();
//    file->addMenu("&File");
//    menu->addMenu(file);

//    QSlider *s1 = new QSlider(Qt::Horizontal, w);
//        QSlider *s2 = new QSlider(Qt::Vertical, w);
//        QSpinBox *sb = new QSpinBox;

//        QHBoxLayout *L = new QHBoxLayout(w);
//            L->addWidget(s1);
//            L->addWidget(s2);
//            L->addWidget(sb);



    btnCreate = new QPushButton(RUS("Создать новую партитуру"), this);
    btnLoad = new QPushButton(RUS("Загрузить партитуру"), this);
    btnExit = new QPushButton(RUS("Выход"), this);

    //компоновщик

//    QVBoxLayout *vl = new QVBoxLayout(this);/
////    this->addLayout(v1);
//    this->setLayout(vl);
//    this->setCentralWidget(btnCreate);
    vl->addWidget(btnCreate);
    vl->addWidget(btnLoad);
    vl->addWidget(btnExit);

//    QPixmap px("C:/Users/User/qt_projects/try/try2/images/flower.jpg");
//    qDebug() << QDir(currentPath()).cdUp();
//    QPixmap px(QDir().cd(QDir::currentPath())  + "/try2/images/flower.jpg");
//    QLabel *lbl_treble = new QLabel(/*w*/);
//    lbl_treble->setPixmap(px.scaled(100, 100, Qt::KeepAspectRatio));

//    vl->addWidget(lbl_treble);///////////////////////

//    lbl_treble->setPixmap(px.scaled(100,100,Qt::KeepAspectRatio,Qt::SmoothTransformation));

    vl->addStretch();//пружина

    QPixmap bckgnd(":/images/ms_note_fone.jpg");////фон
    bckgnd = bckgnd.scaled(this->size(), Qt::KeepAspectRatio);
    this->setFixedSize(bckgnd.size());
    QPalette palette;
    palette.setBrush(QPalette::Background, bckgnd);
    this->setPalette(palette);

//    resize(300, 200);
    connect(btnCreate, SIGNAL(clicked(bool)), this, SLOT(showNewScore()));
//    connect(btnLoad, SIGNAL(clicked(bool)), this, SLOT(openDir()));
//    connect(btnLoad, SIGNAL(clicked(bool)), this, SLOT(wnNewNotes.LoadFile()));
    connect(btnLoad, /*SIGNAL(clicked(bool))*/&QPushButton::clicked, [this/*, wnNewNotes*/](){
        wnNewNotes = new NewNotes();
        wnNewNotes->from_start = true;

        wnNewNotes->LoadFile();
//        wnNewNotes->scr->setVisible(true);

//        if wnNewNotes->
        if (wnNewNotes->opened_win)
            close();
//            hide();
    });
    connect(btnExit, SIGNAL(clicked(bool)), this, SLOT(close()));
}

StartWindow::~StartWindow()
{
    delete btnExit;
    delete btnCreate;
    delete btnLoad;
}

void StartWindow::showNewScore()
{
    QString save_temp_file = "temp_file.msnote";
    if(QFile(save_temp_file).exists()){
        QMessageBox::StandardButton resBtn = QMessageBox::question( this, "NewNotes",
                                                                    ("Приложение было некорректно завершено.\nВосстановить данные?"),
                                                                    QMessageBox::No | QMessageBox::Yes | QMessageBox::Cancel,
                                                                    QMessageBox::Yes);
//        if (resBtn != QMessageBox::Cancel)

            if (resBtn == QMessageBox::Yes){
                wnNewNotes = new NewNotes();
                wnNewNotes->load_file_func(/*load_file*/save_temp_file);
                if (wnNewNotes->opened_win)
                    close();
            }
            if (resBtn == QMessageBox::No)
                wnNewScore->show();
//            else {
//                save_file_name = QFileDialog::getOpenFileName(this, "Открыть файл", QDir::currentPath(), "Документы (*.msnote)");
//                if (QFile(save_file_name).open(QIODevice::ReadOnly))
//                    load_file_func(/*load_file*/save_file_name);
//            }
    } else wnNewScore->show();
//    wnNewScore.setFocus();
//    wnNewScore.open();
//    if (wnNewScore.wnNewNotes->opened_win)
//        close();
}

void StartWindow::openDir(){
////    QString dirname = QFileDialog::getExistingDirectory(
////                       this,
////                       tr("Select a Directory"),
////                       QDir::currentPath() );
////    if( !dirname.isNull() )
////    {
////       qDebug(dirname.toUtf8());
////    }


//    QString filename = QFileDialog::getSaveFileName(
//                        this,
//                        tr("Save Document"),
//                        QDir::currentPath(),
//                        tr("Documents (*.txt)") );
//    if( !filename.isNull() )
//        qDebug(filename.toUtf8() );


    //    DeleteWidgets();

//        /*QString */wnNewNotes.save_file_name = QFileDialog::getOpenFileName(this, "Открыть файл", QDir::currentPath(), "Документы (*.msnote)");
//        QFile load_file(wnNewNotes.save_file_name);
//        if (!load_file.open(QIODevice::ReadOnly)){
//            //error message
//        } else {

//    //        DeleteWidgets();
//            close();

//            QTextStream data_stream(&load_file);
//    //        qDebug(data_stream.readAll().toUtf8());
//            QString name = data_stream.readLine();
//            QString comp = data_stream.readLine();
//            QString share, length;
//            data_stream >> /*name >> comp >>*/ wnNewNotes.str_temp >> wnNewNotes.area->stave_amount >> wnNewNotes.ms_amount >>
//                           wnNewNotes.file_clef >> wnNewNotes.x_clef >> wnNewNotes.y_clef >> wnNewNotes.w_clef >> wnNewNotes.h_clef >>
//                           wnNewNotes.file_sign >> wnNewNotes.x_sign >> wnNewNotes.y_sign >> wnNewNotes.w_sign >> wnNewNotes.h_sign >>
//                           wnNewNotes.share >> wnNewNotes.length;
//    //        QString adsfg = data_stream.readLine();
//            wnNewNotes.lblName->setText(name);
//            wnNewNotes.lblComp->setText(comp);
//            wnNewNotes.share_length = share.toFloat() / length.toFloat();//размер
//            wnNewNotes.show();

//            //первый нотоносец


//            wnNewNotes.y_clef -= 140*wnNewNotes.area->stave_amount;
//            wnNewNotes.y_sign -= 140*wnNewNotes.area->stave_amount;
//            if (wnNewNotes.w_sign == 0){
//                wnNewNotes.lbl_signs.append(new QLabel(wnNewNotes.area));
//                wnNewNotes.lbl_signs[0]->setVisible(false);
//            }
//            for (int i = 0; i < wnNewNotes.area->stave_amount; i++){
//                for (int j =0; j < 5; j++){
//                    wnNewNotes.area->line.append(new MyLine(area->x1, area->y, area->x2, area->y));
//                    wnNewNotes.area->y += 10;
//                }
//                wnNewNotes.area->y += 90;


//                wnNewNotes.lbl_clef.append(new QLabel(area));
//            //    x_clef = 20, y_clef = 118, w_clef = 30, h_clef = 70;
//        //        x_sign = 50, y_sign = 111;//координаты ключевых знаков
//                wnNewNotes.lbl_clef[i]->setPixmap(QPixmap(wnNewNotes.file_clef).scaled(wnNewNotes.w_clef, wnNewNotes.h_clef, Qt::KeepAspectRatio));
//                wnNewNotes.lbl_clef[i]->setGeometry(wnNewNotes.x_clef, wnNewNotes.y_clef, wnNewNotes.w_clef, wnNewNotes.h_clef);//px.width(), px.height());///////////
//                wnNewNotes.lbl_clef[i]->setVisible(true);
//                y_clef += 140;

//                if (wnNewNotes.w_sign != 0){
//                    wnNewNotes.lbl_signs.append(new QLabel(wnNewNotes.area));
//                    wnNewNotes.lbl_signs[i]->setVisible(true);
//                    wnNewNotes.lbl_signs[i]->setPixmap(QPixmap(wnNewNotes.file_sign).scaled(wnNewNotes.w_sign,
//                                                                                            wnNewNotes.h_sign, Qt::KeepAspectRatio));
//                    wnNewNotes.lbl_signs[i]->setGeometry(wnNewNotes.x_sign, wnNewNotes.y_sign, wnNewNotes.w_sign, wnNewNotes.h_sign);
//                    wnNewNotes.y_sign += 140;
//                }

//            }
//            wnNewNotes.area->y -= 90;

//            wnNewNotes.lbl_tempo->setText(str_temp);


//            wnNewNotes.fr_signature->setGeometry(wnNewNotes.x_signature+wnNewNotes.w_sign, wnNewNotes.y_signature+10, 36, 44);
//    //        area->x_ex = area->first_x_ex = x_signature + w_sign + fr_signature->width() + 10;

//    //        area->y_ex = area->first_y_ex = y_signature - 28/*48*/;

//            int takt_type;
//            wnNewNotes.takt_value = 0;
//            QString UpDown, LongTail;
//            for (int i = 0; i<ms_amount; i++){
//                data_stream >> wnNewNotes.note_pause_input >> wnNewNotes.takt_type >> wnNewNotes.notes_value;/* << new_note[i]->x <<
//                               new_note[i]->y << new_note[i]->w << new_note[i]->h << new_note[i]->UpDown << new_note[i]->LongTail <<
//                               new_note[i]->end_x << new_note[i]->end_y << new_note[i]->NoteSign << new_note[i]->x_pos << new_note[i]->y_pos;*/
//    //            if (note_pause_input == 0){
//                    wnNewNotes.new_note.append(new MsNote(wnNewNotes.note_pause_input, wnNewNotes.takt_type, wnNewNotes.notes_value));
//                    data_stream >> wnNewNotes.new_note[i]->x >> wnNewNotes.new_note[i]->y >> wnNewNotes.new_note[i]->w >> wnNewNotes.new_note[i]->h >> UpDown >>
//                                   LongTail >> wnNewNotes.new_note[i]->end_x >> wnNewNotes.new_note[i]->end_y >>wnNewNotes.new_note[i]->NoteSign >>wnNewNotes.new_note[i]->NoteSignHover >> wnNewNotes.new_note[i]->x_pos >> wnNewNotes.new_note[i]->y_pos >>
//                                   wnNewNotes.new_note[i]->MsNumber >> wnNewNotes.new_note[i]->NoteNumber ;
//    //                data_stream.
//                    if (LongTail == "1")
//                        wnNewNotes.new_note[i]->LongTail = true;
//                    else wnNewNotes.new_note[i]->LongTail = false;
//                    if (UpDown == "1")
//                        wnNewNotes.new_note[i]->UpDown = true;
//                    else wnNewNotes.new_note[i]->UpDown = false;

//                    if (wnNewNotes.new_note[i]->NotePauseTakt == 0)//если тактовая черта
//                        wnNewNotes.takt_value = 0;
//                    else wnNewNotes.takt_value += wnNewNotes.new_note[i]->NoteValue;

//    //            }

//                wnNewNotes.lbl_note.append(new QLabel(wnNewNotes.area));
//                QVBoxLayout *v_note/*[notes_amount]*/ = new QVBoxLayout(wnNewNotes.lbl_note[i]);
//                wnNewNotes.lbl_note[i]/*[notes_amount]*/->setLayout(v_note/*[notes_amount]*/);
//                v_note/*[notes_amount]*/->addWidget(wnNewNotes.new_note[i]);
//                v_note/*[notes_amount]*/->setMargin(0);
//                if (wnNewNotes.note_pause_input == 0)
//                    wnNewNotes.lbl_note[i]->setGeometry(wnNewNotes.new_note[i]->x_pos, wnNewNotes.new_note[i]->y_pos, /*30*/10, 120);
//                else wnNewNotes.lbl_note[i]->setGeometry(wnNewNotes.new_note[i]->x_pos, wnNewNotes.new_note[i]->y_pos, /*30*/40, 120);
//                wnNewNotes.lbl_note[i]->setVisible(true);
//                if (wnNewNotes.note_pause_input == -1){//if pause
//                    wnNewNotes.lbl_note[i]->setPixmap(QPixmap(/*string_note_file*/"C:/Users/User/qt_projects/try/try2/images/pause_values/" +
//                                                    QVariant(wnNewNotes.new_note[i]->MsNumber).toString() + "_rest.svg.png").scaled(30/*40*/, 40));
//                }


//    //            data_stream >> new_note[i]
//            }

//            wnNewNotes.area->x_ex = wnNewNotes.new_note[wnNewNotes.ms_amount - 1]->x_pos + wnNewNotes.lbl_note[ms_amount - 1]->width();
//            wnNewNotes.area->y_ex = wnNewNotes.new_note[wnNewNotes.ms_amount - 1]->y_pos/* + lbl_note[ms_amount]->width()*/;

//            if (wnNewNotes.area->x_ex + /*30*/40 > /*area->pos().x() + area->width()*/wnNewNotes.area->width()){
//                wnNewNotes.area->y_ex += 140;//перенос области вспогательных линий на следующий нотоносец
//                wnNewNotes.area->x_ex = wnNewNotes.area->first_x_ex;

//                wnNewNotes.area->y += 90;//следующий нотоносец
//                for (int i = 0; i < 5; i++){
//                    wnNewNotes.area->line.append(new MyLine(wnNewNotes.area->x1, wnNewNotes.area->y, wnNewNotes.area->x2, wnNewNotes.area->y));
//                    wnNewNotes.area->y += 10;
//                }
//                wnNewNotes.lbl_clef.append(new QLabel(wnNewNotes.area));//ключ
//                wnNewNotes.lbl_clef[wnNewNotes.lbl_clef.size() - 1]->setPixmap(QPixmap(wnNewNotes.file_clef).scaled(wnNewNotes.w_clef, wnNewNotes.h_clef, Qt::KeepAspectRatio));
//                wnNewNotes.lbl_clef[wnNewNotes.lbl_clef.size() - 1]->setGeometry(wnNewNotes.x_clef, wnNewNotes.y_clef, wnNewNotes.w_clef, wnNewNotes.h_clef);
//                wnNewNotes.lbl_clef[wnNewNotes.lbl_clef.size() - 1]->setVisible(true);
//                wnNewNotes.lbl_signs.append(new QLabel(area));//ключевые знаки
//                wnNewNotes.lbl_signs[wnNewNotes.lbl_signs.size() - 1]->setPixmap(QPixmap(wnNewNotes.file_sign).scaled(wnNewNotes.w_sign, wnNewNotes.h_sign, Qt::KeepAspectRatio));
//                wnNewNotes.lbl_signs[wnNewNotes.lbl_signs.size() - 1]->setGeometry(wnNewNotes.x_sign, wnNewNotes.y_sign, wnNewNotes.w_sign, wnNewNotes.h_sign);
//                wnNewNotes.lbl_signs[wnNewNotes.lbl_signs.size() - 1]->setVisible(true);

//                wnNewNotes.y_clef += 140;
//                wnNewNotes.y_sign += 140;
//                wnNewNotes.area->stave_amount += 1;
//    //            lbl_clef[0]->setGeometry(0,0,30,70);
//            }

//            wnNewNotes.note1->setEnabled(true);
//            wnNewNotes.note2->setEnabled(true);
//            wnNewNotes.note4->setEnabled(true);
//            wnNewNotes.note8->setEnabled(true);
//            wnNewNotes.note16->setEnabled(true);

//        }


//    wnNewNotes.area->resize(QSize(1115, 300));
//    wnNewNotes.note_pause_input = 1;
//    wnNewNotes.save_file = false;
//    wnNewNotes.show();
//    wnNewNotes.LoadFile();


}

//StartWindow *w;
//void MainWindow::showNewNotes()//работает
//{
//    wnNewNotes.show();
////    wnNewScore.edtName->setFocus();
//}
