#include "StartWindow.h"

StartWindow::StartWindow()/*(QWidget *parent): QMainWindow(parent)*///QWidget(parent)
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

    QPixmap px("C:/Users/User/qt_projects/try/try2/images/flower.jpg");
    QLabel *lbl_treble = new QLabel(/*w*/);
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
    connect(btnLoad, SIGNAL(clicked(bool)), this, SLOT(openDir()));
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
    wnNewScore.show();
    this->setVisible(false);
//    wnNewScore.edtName->setFocus();
}

void StartWindow::openDir(){
//    QString dirname = QFileDialog::getExistingDirectory(
//                       this,
//                       tr("Select a Directory"),
//                       QDir::currentPath() );
//    if( !dirname.isNull() )
//    {
//       qDebug(dirname.toUtf8());
//    }


    QString filename = QFileDialog::getSaveFileName(
                        this,
                        tr("Save Document"),
                        QDir::currentPath(),
                        tr("Documents (*.txt)") );
            if( !filename.isNull() )
    {
        qDebug(filename.toUtf8() );
    }
}

//void MainWindow::showNewNotes()//работает
//{
//    wnNewNotes.show();
////    wnNewScore.edtName->setFocus();
//}
