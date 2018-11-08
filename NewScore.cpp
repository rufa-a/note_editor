#include "NewScore.h"
#include <QFile>
NewScore::NewScore()
                 //: QWizard(parent)
{
    QTextCodec *codec=QTextCodec::codecForName("UTF-8");

//    addPage(new pgName);
    setPage(Page_Name, new NewName);
    setPage(Page_Clef, new NewClef);
    setPage(Page_Sign, new NewSign);
    setPage(Page_Rythm, new NewRythm);
//    setFixedSize(600, 400);////////////////////////////////////////////////////////////////////////////////////////////now

    setStartId(Page_Name);
//#ifndef
    setWizardStyle(ModernStyle);
//#endif
    setWindowTitle(RUS("Новая партитура"));
    setOption(HaveHelpButton, true);
    connect(this, &QWizard::helpRequested, this, &NewScore::showHelp);
}

void NewScore::showHelp()
{
    QTextCodec *codec=QTextCodec::codecForName("UTF-8");


    static QString lastHelpMessage;

//    setPixmap(QWizard::LogoPixmap, QPixmap(":/images/treble_clef.jpg"));

    QString message;

    switch (currentId()) {
    case Page_Name:
        message = RUS("Укажите название записываемого произведения и автора.");
        break;
//    ...
    default:
        message = tr("This help is likely not to be of any help.");
    }

    if (lastHelpMessage == message)
        message = tr("Sorry, I already gave what help I could. "
                     "Maybe you should try asking a human?");

    QMessageBox::information(this, tr("License Wizard Help"), message);

    lastHelpMessage = message;
}

void NewScore::accept(){
//    QString strName = field("NewName").toString();
//    QString strComposer = field("NewComposer").toString();

//    QFile NoteFile(field("NewName").toString() + "_" + field("NewComposer").toString()); //попытка создать файл
////    NoteFile.setFileName(field("NewName").toString() + '_' + field("NewComposer").toString);
//    QString note_name = "name";
////    note_name += field("NewName").toString();
//    NoteFile.write(note_name);

    QString file_clef;

    wnNewNotes.lblName->setText(field("NewName").toString()); //Ставим название и композитора
    wnNewNotes.lblComp->setText(field("NewComposer").toString());
    wnNewNotes.show();//////////////////////////////окно с нотным листом
//    wnNewNotes.area->setVisible(true);



    int x_clef, y_clef, w_clef, h_clef, x_sign, y_sign, w_sign = 0, h_sign = 0;//габариты ключей
    if (field("treble.btn").toBool()){
        file_clef = "C:/Users/User/qt_projects/try/try2/images/treble-clef.png";
//        QPixmap(file_clef).scaled(70, 70, Qt::KeepAspectRatio);
        x_clef = 20, y_clef = 118, w_clef = 30, h_clef = 70;
        x_sign = 50, y_sign = 111;//координаты ключевых знаков
    }
    if (field("bass.btn").toBool()){//ключевые знаки на 10 ниже при басовом ключе
        file_clef = "C:/Users/User/qt_projects/try/try2/images/Bas_Clef.png";
//        QPixmap(file_clef).scaled(40, 40, Qt::KeepAspectRatio);
        x_clef = 20, y_clef = 122, w_clef = 30, h_clef = 50;
        x_sign = 55, y_sign = 121;
    }
    for (int i = 0; i < 6/*8*/; i++){//расстановка ключей
        wnNewNotes.lbl_clef[i]->setPixmap(QPixmap(file_clef).scaled(w_clef, h_clef, Qt::KeepAspectRatio));
//        wnNewNotes.area->lbl[i]->setPixmap(QPixmap(file_clef).scaled(w, h, Qt::KeepAspectRatio));
        wnNewNotes./*area->*/lbl_clef[i]->setGeometry(x_clef, y_clef, w_clef, h_clef);//px.width(), px.height());///////////
        y_clef += 140;
    }


    if (field("r0").toBool()){//размещение размера при наличии ключевых знаков
        for (int i=0; i<6/*8*/; i++){
//            wnNewNotes.lbl_signs[i]->setGeometry(0,0,0,0);
            wnNewNotes.lbl_signs[i]->setVisible(false);//невидимые лейблы ключевых знаков
        }
    }
    else{//ключевые знаки
        QString file_sign = "C:/Users/User/qt_projects/try/try2/images/";
        if (field("1d").toBool()){
            w_sign = 10, h_sign = 60;
            file_sign += "1d_clef_2.svg.png";
        }
        if (field("2d").toBool()){
            w_sign = 20, h_sign = 60;
            file_sign += "2d_clef_2.svg.png";
        }
        if (field("3d").toBool()){
            w_sign = 30, h_sign = 60;
            file_sign += "3d_clef_2.svg.png";
        }
        if (field("4d").toBool()){
            w_sign = 40, h_sign = 60;
            file_sign += "4d_clef_2.svg.png";
        }
        if (field("5d").toBool()){
            w_sign = 50, h_sign = 60;
            file_sign += "5d_clef_2.svg.png";
        }
        if (field("6d").toBool()){
            w_sign = 60, h_sign = 60;
            file_sign += "6d_clef_2.svg.png";
        }
        if (field("7d").toBool()){
            w_sign = 70, h_sign = 60;
            file_sign += "7d_clef_2.svg.png";
        }
        if (field("1b").toBool()){
//            w_sign = 10, h_sign = 70;
            w_sign = 12, h_sign = 55, y_sign += 6;
            file_sign += "1b_clef_3.svg.png";
        }
        if (field("2b").toBool()){
            w_sign = 20, h_sign = 55, y_sign += 6;
            file_sign += "2b_clef.svg.png";
        }
        if (field("3b").toBool()){
            w_sign = 30, h_sign = 54, y_sign += 6;
            file_sign += "3b_clef.svg.png";
        }
        if (field("4b").toBool()){
            w_sign = 40, h_sign = 54, y_sign += 6;
            file_sign += "4b_clef.svg.png";
        }
        if (field("5b").toBool()){
            w_sign = 50, h_sign = 54, y_sign += 6;
            file_sign += "5b_clef.svg.png";
        }
        if (field("6b").toBool()){
            w_sign = 60, h_sign = 54, y_sign += 6;
            file_sign += "6b_clef.svg.png";
        }
        if (field("7b").toBool()){
            w_sign = 70, h_sign = 55, y_sign += 6;
            file_sign += "7b_clef.svg.png";
        }
        for (int i=0; i<6/*8*/; i++){
            wnNewNotes.lbl_signs[i]->setVisible(true);
            wnNewNotes.lbl_signs[i]->setPixmap(QPixmap(file_sign).scaled(w_sign, h_sign, Qt::KeepAspectRatio));
            wnNewNotes.lbl_signs[i]->setGeometry(x_sign, y_sign, w_sign, h_sign);
            y_sign+=140;
        }

    }
    //размер
    int x_signature = 45, y_signature = 118;
    wnNewNotes.lbl_share->setText(field("share").toString());
    wnNewNotes.lbl_length->setText(field("length").toString());
    wnNewNotes.fr_signature->setGeometry(x_signature+w_sign, y_signature+10, 36, 44);
    wnNewNotes.str_temp = "=" + field("temp").toString();
    wnNewNotes.lbl_tempo->setText(wnNewNotes.str_temp);

    wnNewNotes.area->x_ex = wnNewNotes.area->first_x_ex = x_signature + w_sign + wnNewNotes.fr_signature->width() + 10;

    wnNewNotes.area->y_ex = wnNewNotes.area->first_y_ex = y_signature - 28/*48*/;

    QDialog::accept();

    restart();
}

NewName::NewName(QWidget *parent)
    : QWizardPage(parent)
{

    QTextCodec *codec=QTextCodec::codecForName("UTF-8");
    setTitle(RUS("Новая партитура"));
    setSubTitle(RUS("Введите информацию о партитуре:"));



//    this->nextInFocusChain();

//    this->setFixedSize(900, 300);
//    this->setPixmap(QWizard::WatermarkPixmap, QPixmap("treble_clef.jpg"));

    edtName = new QLineEdit(RUS(""), this);
    edtName->setMaxLength(50);
    lblName = new QLabel(RUS("Название"), this);
    lblName->setFixedWidth(70);
    edtComposer = new QLineEdit(RUS(""), this);
    edtComposer->setMaxLength(60);
    lblComposer = new QLabel(RUS("Композитор"), this);
    lblComposer->setFixedWidth(70);




    registerField("NewName*", edtName);//для перехода на следующую страницу
    registerField("NewComposer*", edtComposer);

    QVBoxLayout *v = new QVBoxLayout(this);
    QHBoxLayout *h1 = new QHBoxLayout();
    QHBoxLayout *h2 = new QHBoxLayout();
    h1->addWidget(lblName);
    h1->addWidget(edtName);
    h2->addWidget(lblComposer);
    h2->addWidget(edtComposer);
    v->addLayout(h1);
    v->addLayout(h2);

//    if (!edtName->text().isEmpty() && !edtComposer->text().isEmpty())
//        this->isComplete();
}

//bool NewName::isComplete()
//{
//    !edtName->text().isEmpty();
//            !edtComposer->text().isEmpty();

//}

//int NewName::nextId() const
//{
////    QTextCodec *codec=QTextCodec::codecForName("UTF-8");
//    if (!edtName->text().isEmpty() && !edtComposer->text().isEmpty()) {
//        return NewScore::Page_Clef;
//    } /*else {
////        return NewScore::Page_Key;
////        QMessageBox::information(this, RUS("Нельзя"), RUS("Заполните пустые строки"));
//        QMessageBox msg(QMessageBox::Critical, RUS("Ошибка"), RUS("Заполните пустые поля!"), QMessageBox::Ok, 0);
//        msg.exec();
//    }*/
//}


NewClef::NewClef(QWidget *parent)
    : QWizardPage(parent)
{
    QTextCodec *codec=QTextCodec::codecForName("UTF-8");
    setTitle(RUS("Новая партитура"));
    setSubTitle(RUS("Выберите ключ:"));
//    this->setFixedSize(900, 300);

//    QLabel *lbl_treble = new QLabel;
//    QPixmap image_clef("C:/Users/User/qt_projects/try/try2/images/treble_clef.jpg");
//    lbl_treble->setPixmap(image_clef.scaled(100, 100, Qt::KeepAspectRatio));

    QHBoxLayout *h1box = new QHBoxLayout;
//    lbl_treb->setPixmap(image_clef);
//    v1box->addWidget(lbl_treb);


    rd_treb = new QRadioButton(RUS("Скрипичный ключ"));
    QIcon r1("C:/Users/User/qt_projects/try/try2/images/treble_clef.png");
    rd_treb->setIcon(r1);
    rd_treb->setIconSize(QSize(100, 100));
    h1box->addWidget(rd_treb);
    rd_bas = new QRadioButton(tr("Басовый ключ"));
    QIcon r2("C:/Users/User/qt_projects/try/try2/images/bass_clef.png");
    rd_bas->setIcon(r2);
    rd_bas->setIconSize(QSize(100, 100));
    h1box->addWidget(rd_bas);

    QHBoxLayout *h2box = new QHBoxLayout;
    rd_alt = new QRadioButton(tr("Альтовый ключ"));
    QIcon r3("C:/Users/User/qt_projects/try/try2/images/alto_clef.png");
    rd_alt->setIcon(r3);
    rd_alt->setIconSize(QSize(100, 100));
    h2box->addWidget(rd_alt);

    rd_ten = new QRadioButton(tr("Теноровый ключ"));
    QIcon r4("C:/Users/User/qt_projects/try/try2/images/tenor_clef.png");
    rd_ten->setIcon(r4);
    rd_ten->setIconSize(QSize(100, 100));
    h2box->addWidget(rd_ten);


    QFrame *fr = new QFrame();
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(fr);


    QVBoxLayout *vbox = new QVBoxLayout(fr);

    vbox->addLayout(h1box);
    vbox->addLayout(h2box);

//    fr->setLayout(vbox);



    fr -> setFrameShadow(QFrame::Raised);
    fr -> setFrameShape(QFrame::Panel);
    fr->setStyleSheet("background-color:lightgrey");
//    vbox->addWidget(fr);

    rd_treb->setChecked(true);

    registerField("treble.btn", rd_treb);
    registerField("bass.btn", rd_bas);

//    hbox->addStretch(1);
}

//int NewClef::nextId() const
//{
////    QTextCodec *codec=QTextCodec::codecForName("UTF-8");
////    if (!edtName->text().isEmpty() && !edtComposer->text().isEmpty()) {
//        return NewScore::Page_Sign;
//    } /*else {
////        return NewScore::Page_Key;
////        QMessageBox::information(this, RUS("Нельзя"), RUS("Заполните пустые строки"));
//        QMessageBox msg(QMessageBox::Critical, RUS("Ошибка"), RUS("Заполните пустые поля!"), QMessageBox::Ok, 0);
//        msg.exec();
//    }*/
////}

NewSign::NewSign(QWidget *parent)
    : QWizardPage(parent)
{
    QTextCodec *codec=QTextCodec::codecForName("UTF-8");
    setTitle(RUS("Новая партитура"));
    setSubTitle(RUS("Выберите ключевые знаки:"));

    QHBoxLayout *scr_layout = new QHBoxLayout(this);
    scr = new QScrollArea(this);
    scr_layout->addWidget(scr);
    mainWidget = new QWidget(scr);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainWidget->setLayout(mainLayout);


//    scr = new QScrollArea(this);///////////////////////////////
//    mainWidget = new QWidget(scr);
//    QVBoxLayout *mainLayout = new QVBoxLayout;
////    mainWidget->setLayout(mainLayout);

////    QHBoxLayout *h0 = new QHBoxLayout;
//    checked_signs = new QButtonGroup(scr);
////    mainLayout->addWidget(checked_signs);
////    mainLayout->addWidget(checked_signs);

////    checked_signs->setLayout(mainLayout);

//    r0 = new QRadioButton;
//    QIcon r_0("C:/Users/User/qt_projects/try/try2/images/0db.svg.png");
//    r0->setIcon(r_0);
//    r0->setIconSize(QSize(100, 100));
//    r0->setToolTip(RUS("До мажор, ля минор"));
//    r0->setStyleSheet("QToolTip { color: black; background-color: lightblue; border: 1px solid white; }");
//    r0->setChecked(true);
//    checked_signs->addButton(r0);
//    QString str = checked_signs->checkedButton();
////    checked_signs->setLayout(h0);
////    h0->addWidget(r0);/////////////////////////////////////////////




    QHBoxLayout *h0 = new QHBoxLayout;
    r0 = new QRadioButton;
    QIcon r_0("C:/Users/User/qt_projects/try/try2/images/0db.svg.png");
    r0->setIcon(r_0);
    r0->setIconSize(QSize(100, 100));
    r0->setToolTip(RUS("До мажор, ля минор"));
    r0->setStyleSheet("QToolTip { color: black; background-color: lightblue; border: 1px solid white; }");
    r0->setChecked(true);
    h0->addWidget(r0);
    mainLayout->addLayout(h0);

    QHBoxLayout *hd = new QHBoxLayout;
    rd_1d = new QRadioButton;
    QIcon d1("C:/Users/User/qt_projects/try/try2/images/1d.svg.png");
    rd_1d->setIcon(d1);
    rd_1d->setIconSize(QSize(100, 100));
    rd_1d->setToolTip(RUS("Соль мажор, ми минор"));
    rd_1d->setStyleSheet("QToolTip { color: black; background-color: lightblue; border: 1px solid white; }");
    hd->addWidget(rd_1d);
    rd_2d = new QRadioButton;
    QIcon d2("C:/Users/User/qt_projects/try/try2/images/2d.svg.png");
    rd_2d->setIcon(d2);
    rd_2d->setIconSize(QSize(100, 100));
    rd_2d->setToolTip(RUS("Ре мажор, си минор"));
    rd_2d->setStyleSheet("QToolTip { color: black; background-color: lightblue; border: 1px solid white; }");
    hd->addWidget(rd_2d);
    rd_3d = new QRadioButton;
    QIcon d3("C:/Users/User/qt_projects/try/try2/images/3d.svg.png");
    rd_3d->setIcon(d3);
    rd_3d->setIconSize(QSize(100, 100));
    rd_3d->setToolTip(RUS("Ля мажор, фа-диез минор"));
    rd_3d->setStyleSheet("QToolTip { color: black; background-color: lightblue; border: 1px solid white; }");
    hd->addWidget(rd_3d);
    rd_4d = new QRadioButton;
    QIcon d4("C:/Users/User/qt_projects/try/try2/images/4d.svg.png");
    rd_4d->setIcon(d4);
    rd_4d->setIconSize(QSize(100, 100));
    rd_4d->setToolTip(RUS("Ми мажор, до-диез минор"));
    rd_4d->setStyleSheet("QToolTip { color: black; background-color: lightblue; border: 1px solid white; }");
    hd->addWidget(rd_4d);
    rd_5d = new QRadioButton;
    QIcon d5("C:/Users/User/qt_projects/try/try2/images/5d.svg.png");
    rd_5d->setIcon(d5);
    rd_5d->setIconSize(QSize(100, 100));
    rd_5d->setToolTip(RUS("Си мажор, соль-диез минор"));
    rd_5d->setStyleSheet("QToolTip { color: black; background-color: lightblue; border: 1px solid white; }");
    hd->addWidget(rd_5d);
    rd_6d = new QRadioButton;
    QIcon d6("C:/Users/User/qt_projects/try/try2/images/6d.svg.png");
    rd_6d->setIcon(d6);
    rd_6d->setIconSize(QSize(100, 100));
    rd_6d->setToolTip(RUS("Фа-диез мажор, ре-диез минор"));
    rd_6d->setStyleSheet("QToolTip { color: black; background-color: lightblue; border: 1px solid white; }");
    hd->addWidget(rd_6d);
    rd_7d = new QRadioButton;
    QIcon d7("C:/Users/User/qt_projects/try/try2/images/7d.svg.png");
    rd_7d->setIcon(d7);
    rd_7d->setIconSize(QSize(100, 100));
    rd_7d->setToolTip(RUS("До-диез мажор, ля-диез минор"));
    rd_7d->setStyleSheet("QToolTip { color: black; background-color: lightblue; border: 1px solid white; }");
    hd->addWidget(rd_7d);
    mainLayout->addLayout(hd);

    QHBoxLayout *hb = new QHBoxLayout;
    rd_1b = new QRadioButton;
    QIcon b1("C:/Users/User/qt_projects/try/try2/images/1b.svg.png");
    rd_1b->setIcon(b1);
    rd_1b->setIconSize(QSize(100, 100));
    rd_1b->setToolTip(RUS("Фа мажор, ре минор"));
    rd_1b->setStyleSheet("QToolTip { color: black; background-color: lightblue; border: 1px solid white; }");
    hb->addWidget(rd_1b);
    rd_2b = new QRadioButton;
    QIcon b2("C:/Users/User/qt_projects/try/try2/images/2b.svg.png");
    rd_2b->setIcon(b2);
    rd_2b->setIconSize(QSize(100, 100));
    rd_2b->setToolTip(RUS("Си-бемоль мажор, соль минор"));
    rd_2b->setStyleSheet("QToolTip { color: black; background-color: lightblue; border: 1px solid white; }");
    hb->addWidget(rd_2b);
    rd_3b = new QRadioButton;
    QIcon b3("C:/Users/User/qt_projects/try/try2/images/3b.svg.png");
    rd_3b->setIcon(b3);
    rd_3b->setIconSize(QSize(100, 100));
    rd_3b->setToolTip(RUS("Ми-бемоль мажор, до минор"));
    rd_3b->setStyleSheet("QToolTip { color: black; background-color: lightblue; border: 1px solid white; }");
    hb->addWidget(rd_3b);
    rd_4b = new QRadioButton;
    QIcon b4("C:/Users/User/qt_projects/try/try2/images/4b.svg.png");
    rd_4b->setIcon(b4);
    rd_4b->setIconSize(QSize(100, 100));
    rd_4b->setToolTip(RUS("Ля-бемоль мажор, фа минор"));
    rd_4b->setStyleSheet("QToolTip { color: black; background-color: lightblue; border: 1px solid white; }");
    hb->addWidget(rd_4b);
    rd_5b = new QRadioButton;
    QIcon b5("C:/Users/User/qt_projects/try/try2/images/5b.svg.png");
    rd_5b->setIcon(b5);
    rd_5b->setIconSize(QSize(100, 100));
    rd_5b->setToolTip(RUS("Ре-бемоль мажор, си-бемоль минор"));
    rd_5b->setStyleSheet("QToolTip { color: black; background-color: lightblue; border: 1px solid white; }");
    hb->addWidget(rd_5b);
    rd_6b = new QRadioButton;
    QIcon b6("C:/Users/User/qt_projects/try/try2/images/6b.svg.png");
    rd_6b->setIcon(b6);
    rd_6b->setIconSize(QSize(100, 100));
    rd_6b->setToolTip(RUS("Соль-бемоль мажор, ми-бемоль минор"));
    rd_6b->setStyleSheet("QToolTip { color: black; background-color: lightblue; border: 1px solid white; }");
    hb->addWidget(rd_6b);
    rd_7b = new QRadioButton;
    QIcon b7("C:/Users/User/qt_projects/try/try2/images/7b.svg.png");
    rd_7b->setIcon(b7);
    rd_7b->setIconSize(QSize(100, 100));
    rd_7b->setToolTip(RUS("До-бемоль мажор, ля-бемоль минор"));
    rd_7b->setStyleSheet("QToolTip { color: black; background-color: lightblue; border: 1px solid white; }");

    hb->addWidget(rd_7b);
    mainLayout->addLayout(hb);

    scr->setWidget(mainWidget);
    this->resize(600, 300);
    scr->setMinimumSize(600, 250);
    scr->setMaximumSize(1000, 500);
    scr->setAlignment(Qt::AlignTop);

    scr->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

//    checked_signs = new QButtonGroup;
//    checked_signs->addButton(r0, 0);

//    checked_signs->addButton(rd_1d, 1);
//    checked_signs->addButton(rd_2d, 2);
//    checked_signs->addButton(rd_3d, 3);
//    checked_signs->addButton(rd_4d, 4);
//    checked_signs->addButton(rd_5d, 5);
//    checked_signs->addButton(rd_6d, 6);
//    checked_signs->addButton(rd_7d, 7);
//    checked_signs->addButton(rd_1b, 11);
//    checked_signs->addButton(rd_2b, 12);
//    checked_signs->addButton(rd_3b, 13);
//    checked_signs->addButton(rd_4b, 14);
//    checked_signs->addButton(rd_5b, 15);
//    checked_signs->addButton(rd_6b, 16);
//    checked_signs->addButton(rd_7b, 17);

//    r0->setProperty("rd", "r0");
//    r0->setText("asdf");
//    rd_1d->setProperty("rd", "1d_clef_2");
//    rd_2d->setProperty("rd", "2d_clef_2");
//    rd_3d->setProperty("rd", "3d_clef_2");
//    rd_4d->setProperty("rd", "4d_clef_2");
//    rd_5d->setProperty("rd", "5d_clef_2");
//    rd_6d->setProperty("rd", "6d_clef_2");
//    rd_7d->setProperty("rd", "7d_clef_2");
//    rd_1b->setProperty("rd", "1b_clef");
//    rd_2b->setProperty("rd", "2b_clef");
//    rd_3b->setProperty("rd", "3b_clef");
//    rd_4b->setProperty("rd", "4b_clef");
//    rd_5b->setProperty("rd", "5b_clef");
//    rd_6b->setProperty("rd", "6b_clef");
//    rd_7b->setProperty("rd", "7b_clef");

////    QString vr = r0->property("rd").toString();
//    QString str = checked_signs->checkedButton()->property("rd").toString();
////    int asdf = checked_signs->checkedId();
////    registerField("rd_signs", checked_signs->checkedButton()/*, "currentProperty", "currentPropertyChanged"*/);
////    registerField("rd_signs", checked_signs->checkedButton(), checked_signs->checkedButton()->property("rd").toChar());
//    setField("rd_sign", checked_signs->checkedButton()->property("rd"));
////    registerField("length", length, "currentText", "currentTextChanged");
////    QString srt = checked_signs->checkedButton()->toolTip();

    registerField("r0", r0);

    registerField("1d", rd_1d);
    registerField("2d", rd_2d);
    registerField("3d", rd_3d);
    registerField("4d", rd_4d);
    registerField("5d", rd_5d);
    registerField("6d", rd_6d);
    registerField("7d", rd_7d);

    registerField("1b", rd_1b);
    registerField("2b", rd_2b);
    registerField("3b", rd_3b);
    registerField("4b", rd_4b);
    registerField("5b", rd_5b);
    registerField("6b", rd_6b);
    registerField("7b", rd_7b);

}



//int NewSign::nextId() const
//{
//    return NewScore::Page_Rythm;
//}

NewRythm::NewRythm(QWidget *parent)
    : QWizardPage(parent)
{
    QTextCodec *codec=QTextCodec::codecForName("UTF-8");
    setTitle(RUS("Новая партитура"));
    setSubTitle(RUS("Выберите размер и темп:"));
    lbl_signature = new QLabel;
    lbl_signature->setText(RUS("Размер:"));
    share_number = new QSpinBox;
    share_number->setMinimum(1);
    share_number->setValue(2);
    share_number->setStyleSheet("background-color:white");
    share_number->setFixedWidth(50);
    share_number->setToolTip(RUS("Количество долей в такте"));
    share_number->setStyleSheet("QToolTip { color: black; background-color: lightblue; border: 1px solid white; }");
    registerField("share", share_number);

    lbl1 = new QLabel;
    lbl1->setText("/");
    length = new QComboBox;
    length->addItem("2", 0);
    length->addItem("4", 1);
    length->addItem("8", 2);
    length->addItem("16", 3);
    length->addItem("32", 4);
    length->addItem("64", 5);
    length->setCurrentIndex(1);
    length->setStyleSheet("background-color:white");
    length->setFixedWidth(50);
    length->setToolTip(RUS("Длительность долей"));
    length->setStyleSheet("QToolTip { color: black; background-color: lightblue; border: 1px solid white; }");
    registerField("length", length, "currentText", "currentTextChanged");//чтобы отображать значение, а не индекс

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    fr1 = new QFrame();
    fr2 = new QFrame();
    fr1 -> setFrameShadow(QFrame::Raised);
    fr1 -> setFrameShape(QFrame::Panel);
//    fr1->setStyleSheet("background-color:lightgrey");
    fr2 -> setFrameShadow(QFrame::Raised);
    fr2 -> setFrameShape(QFrame::Panel);
//    fr2->setStyleSheet("background-color:lightgrey");
    fr2->setToolTip(RUS("Количество ударов четвертных нот в минуту"));
    fr2->setStyleSheet("QToolTip { color: black; background-color: lightblue; border: 1px solid white; }");
    mainLayout->addWidget(fr1);
    mainLayout->addWidget(fr2);

    QHBoxLayout *h1 = new QHBoxLayout(fr1);
    h1->addWidget(lbl_signature);
    h1->addWidget(share_number);
    h1->addWidget(lbl1);
    h1->addWidget(length);
    h1->addStretch();

    QHBoxLayout *h2 = new QHBoxLayout(fr2);
    lbl_tempo = new QLabel;
    lbl_tempo->setText("Темп: ");
    tempo = new QSpinBox;
    tempo->setMinimum(20);
    tempo->setMaximum(400);
    tempo->setValue(120);
    tempo->setStyleSheet("background-color:white");
    registerField("temp", tempo);
    h2->addWidget(lbl_tempo);
    h2->addWidget(tempo);
    h2->addStretch();


//    connect(this->button(QWizard::FinishButton), SIGNAL(clicked(bool)), this, SLOT(showNewNotes()));

}



//void NewRythm::on
//int NewRythm::nextId() const
//{
////    return NewNotes;
////    wnNewNotes->show();
////    return NewScore::Page_Clef;
//    wnNewNotes->show();
//}



