#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)//QWidget(parent)
{
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    this->setWindowTitle(RUS("Нотный редактор"));


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



    QWidget *w = new QWidget(this);
    QVBoxLayout *vl = new QVBoxLayout;//////////////

////    w->setBackgroundRole(QPalette::Light);
////    w->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    this->setCentralWidget(w);
    w->setLayout(vl);
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

    QPixmap px("C:/Users/User/qt_projects/try/try2/images/flower.jpg");
    QLabel *lbl_treble = new QLabel(w);
    lbl_treble->setPixmap(px.scaled(100, 100, Qt::KeepAspectRatio));

    vl->addWidget(lbl_treble);///////////////////////

//    lbl_treble->setPixmap(px.scaled(100,100,Qt::KeepAspectRatio,Qt::SmoothTransformation));

    vl->addStretch();//пружина

    QPixmap bckgnd("C:/Users/User/qt_projects/try/try2/images/treble_clef.jpg");////фон
    bckgnd = bckgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
       palette.setBrush(QPalette::Background, bckgnd);
       this->setPalette(palette);

    resize(300, 200);
    connect(btnCreate, SIGNAL(clicked(bool)), this, SLOT(showNewScore()));
//    connect(btnLoad, SIGNAL(clicked(bool)), this, SLOT(showNewNotes()));
    connect(btnExit, SIGNAL(clicked(bool)), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete btnExit;
    delete btnCreate;
    delete btnLoad;
}

void MainWindow::showNewScore()
{
    wnNewScore.show();
//    wnNewScore.edtName->setFocus();
}

//void MainWindow::showNewNotes()//работает
//{
//    wnNewNotes.show();
////    wnNewScore.edtName->setFocus();
//}
