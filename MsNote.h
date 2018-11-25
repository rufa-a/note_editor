#ifndef MSNOTE_H
#define MSNOTE_H
#include <QtWidgets>
//#include <dialogadddevice>
//class NewNotes;
//static int note_sign;
extern int note_sign;
static int sign_hover = 0;
class MsNote : public QWidget
{
    Q_OBJECT
public:
//    friend NewNotes;
    int x, y, w, h,//геометрия и координаты ноты самого виджета
    end_x, end_y,//конец хвоста ноты
    NoteSign = 0, NoteSignHover = 10,//по умолчанию 3 - нет знака альтерации
    NotePauseTakt, TaktType,
    x_pos, y_pos,//координаты лэйбла на самом NoteArea
    MsNumber = 0,//длительность(целая)
    NoteNumber;// номер
    bool UpDown, LongTail;
    float NoteValue;

    bool enter_sign = false, leave_sign = false;

//    QMenu *mmmenu;
//    QAction *editDevice, *deleteDevice;
//public slots:
////    void slotCustomMenuRequested(QPoint p);
//    void slotEditNote();
//    void slotRemoveNote();

public:

    void draw_note(QPainter *painter/*, int x, int y, int w, int h*/);
    MsNote(int note_pause, int takt_type,  float note_value = 0, int X = 0, int Y = 0, int W = 0, int H = 0, bool up_down = false,
           bool long_tail = false) :
        NotePauseTakt(note_pause), TaktType(takt_type), NoteValue(note_value), x(X), y(Y), w(W), h(H),
        UpDown(up_down), LongTail(long_tail)/*, NoteSign(note_sign)*/ {
//        setContextMenuPolicy(Qt::CustomContextMenu);
////        connect(this, SIGNAL(rightClicked()), this, SLOT(slotCustomMenuRequested(QPoint)));
//        mmmenu = new QMenu(this);
//        /*QAction * */editDevice = new QAction(trUtf8("Поменять положение"), this);
//        editDevice->setVisible(true);
////        /*QAction * */deleteDevice = new QAction(trUtf8("Удалить"), this);
////        deleteDevice->setVisible(true);
//        connect(this, SIGNAL(clicked()), this, SLOT(slotEditNote()));     // Обработчик вызова диалога редактирования
////        connect(deleteDevice, SIGNAL(clicked(bool)), this, SLOT(slotRemoveNote()));
//        mmmenu->addAction("editDevice", this, SLOT(slotRemoveNote()));
//        mmmenu->addAction(deleteDevice);
    }
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
    void enterEvent(QEvent *e);
    void leaveEvent(QEvent *e);

//public slots:
////    void slotCustomMenuRequested(QPoint p);
//    void slotEditNote();
//    void slotRemoveNote();

signals:
//    void RightClick(QMouseEvent *e);
    Q_SIGNAL
    void RightClickNote(QMouseEvent *e, MsNote *thees);
};

#endif // MSNOTE_H
