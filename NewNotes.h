#ifndef NEWNOTES_H
#define NEWNOTES_H

#include <QtWidgets>
#include <QVector>
#include "NewScore.h"
//#include "StartWindow.h"
#include "NoteArea.h"
#include "MsNote.h"
class NewScore;//forward declaration
//class StartWindow;

//class MsNote;
//int note_sign;
class NewNotes : public QMainWindow/*QWidget*/
{
    Q_OBJECT
public:
//    friend MsNote;

    friend class NewScore;
    NewScore *winNewScore;
//    friend StartWindow;
//    int note_sign;
    QTextCodec *codec;
    NoteArea * area;         // область отображения рисунка
//    NewScore wnNewScore;
//    QMdiArea */*note_window*/scr;//for trying to make MDI
    QScrollArea *scr;

    QFrame *fr_signature, *fr_tempo;

    QLineEdit *lblName, *lblComp;
    QLabel /**lblName, *lblComp,*/ /**lbl_clef[8],*/ *lbl_share, *lbl_length, /**lbl_signs[8],*/ *lbl_note_tempo, *lbl_tempo/*, *lbl_note[10]*/;//*[10];
    QString str_share, str_length, str_temp,
    file_sign, file_clef;//картинка знаков и ключа
    int x_sign, y_sign, w_sign, h_sign,//геометрия лэйбла ключевых знаков
    x_clef, y_clef, w_clef, h_clef,//геометрия лэйбла ключа
    x_signature = 45, y_signature = 118; // для размера
//    save_file_name/* = "null"*/;

    QToolBar *ms_values,  *note_pause, *note_signs;
//    QMenu *ms_values;
//    QMenuBar *ms_values;
    QToolButton *note1, *note2, *note4, *note8, *note16, *note_pause_n, *note_pause_p, *sh1, *sh2, *nat, *f1, *f2, *no;
//    QAction *note1, *note2, *note4, *note8, *note16;

    QList<QLabel*> lbl_ms, lbl_note,//вектор лэйблов, на которых ноты
    lbl_clef, lbl_signs;//ключи и ключевые знаки
    QList<MsNote*> new_note;//вектор нот
//    MsNote *new_note[];
//    QGraphicsScene *note_scene;
//    QGraphicsItemGroup  *group_1;
    int ms_amount = 0, notes_amount = 0, //для вектора
    note_value = 16,//для типа ноты (1, 2, 4, 8, 16, 32...)
    note_pause_input = 1;
//    /*friend */int note_sign = 3;//случайные знаки, по умолчанию 3 - нет знака

    float notes_value = 0.0625, takt_value = 0, share_length;//для длительности ноты
    bool up_down, //для хвостика
    long_tail,
//    note_pause_input = true,
    draw_takt =false;
//    int note_value = 1;
//    QString string_note_file;
//    QList<QPixmap*> notes_value_image;

    QPoint ex_coordinates; //
//    ExLines * extended_lines;

//    QSignalMapper *signalMapper;

    bool repaint_note = false;//для "Редактировать"
    int repaint_note_number, last_x_ex, last_y_ex;

    QString save_file_name, save_temp_file;//Для файла
    bool save_file = false, from_start = false;
    bool opened_win = false;//если открылся новый нотный лист
    bool return_exit = false, load_from_main = false, has_changed = true, exit = true;


public:
    NewNotes(QWidget *parent = 0);
    ~NewNotes();

    void draw_note(QPainter *painter);
    void mousePressEvent(QMouseEvent *e);////////////для создания ноты при нажатии ЛКМ
    void closeEvent(/*bool change_flag*/QCloseEvent *e);
//    void paintEvent(QPaintEvent *);
//    bool eventFilter(QObject *watched, QEvent *event);
    void DeleteWidgets();

    void save_file_func(QString file_name);
    void load_file_func(/*QFile load_file*/QString file_name);

//    void slotCustomMenuRequested(QPoint p);
//    void EditMenu(QMouseEvent *, MsNote *);

public slots:
    void slotFunc();

    void NoteInput();
    void PauseInput();

    void set1Value();
    void set2Value();
    void set4Value();
    void set8Value();
    void set16Value();

    void Add2Sharp();
    void AddSharp();
    void AddNatural();
    void AddFlat();
    void Add2Flat();
    void DeleteSign();

    void CreateNote();
    void SaveFile();
    void LoadFile();
//    void createNote(QMouseEvent *e);//для создания ноты при нажатии ЛКМ

    void slotCustomMenuRequested(QPoint p);
    void EditMenu(QMouseEvent *ev, MsNote *note);
//    void slotEditNote();
//    void slotRemoveNote();
};
#endif // NEWNOTES_H
