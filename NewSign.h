#ifndef NEWSIGN_H
#define NEWSIGN_H
#include "NewRythm.h"
#include <QtWidgets>
#define RUS(str) codec->toUnicode(str)

class NewSign : public QWizardPage{
    Q_OBJECT

public:

    QButtonGroup *checked_signs;
    QRadioButton *rd_1d, *rd_2d, *rd_3d, *rd_4d, *rd_5d, *rd_6d, *rd_7d;
    QRadioButton *rd_1b, *rd_2b, *rd_3b, *rd_4b, *rd_5b, *rd_6b, *rd_7b;
    QRadioButton *r0;
    QScrollArea *scr;
    QWidget *mainWidget;
    NewSign(QWidget *parent = 0);
//    int nextId() const override;

};
#endif // NEWSIGN_H
