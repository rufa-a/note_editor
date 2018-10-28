#ifndef NEWNOTES_H
#define NEWNOTES_H

#include <QtWidgets>
#include <QVector>
#include "NoteArea.h"
#include "MsNote.h"
class NewNotes : public QWidget
{
    Q_OBJECT
public:
    QTextCodec *codec;
    NoteArea * area;         // область отображения рисунка
    QScrollArea *scr;
    QFrame *fr_signature, *fr_tempo;
    QLabel *lblName, *lblComp, *lbl_clef[8], *lbl_share, *lbl_length, *lbl_signs[8], *lbl_note_tempo, *lbl_tempo/*, *lbl_note[10]*/;//*[10];
    QString str_share, str_length, str_temp;
    QPushButton * btn_exit;

//    QVector<QLabel*> lbl_note;
//    QVBoxLayout *v_note[];
    QList<QLabel*> lbl_note;
    QList<MsNote*> new_note;
//    MsNote *new_note[];
    QGraphicsScene *note_scene;
    QGraphicsItemGroup  *group_1;
    int notes_amount = 0;

//    ExLines * extended_lines;


public:
    NewNotes(/*QWidget *parent = 0*/);
    ~NewNotes();

    void draw_note(QPainter *painter);
    void mousePressEvent(QMouseEvent *e);////////////для создания ноты при нажатии ЛКМ
//    void paintEvent(QPaintEvent *);
//    bool eventFilter(QObject *watched, QEvent *event);

public slots:
    void slotFunc();
//    void createNote(QMouseEvent *e);//для создания ноты при нажатии ЛКМ
};
#endif // NEWNOTES_H
