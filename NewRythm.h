#ifndef NEWRYTHM_H
#define NEWRYTHM_H
#include <QtWidgets>
#include "NewNotes.h"
#define RUS(str) codec->toUnicode(str)

class NewRythm : public QWizardPage{
    Q_OBJECT

public:
    QSpinBox *share_number, *tempo;
    QFrame *fr1, *fr2;
    QLabel *lbl1, *lbl_tempo, *lbl_signature;
    QComboBox *length;

    NewRythm(QWidget *parent = 0);
//    int nextId() const override;


//    NewNotesWindow *wnNewNotesWindow;

//public slots:
//    void showNewNotesWindow();
};
#endif // NEWRYTHM_H
