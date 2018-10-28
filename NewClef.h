#ifndef NEWCLEF_H
#define NEWCLEF_H
#include"NewSign.h"
#include <QtWidgets>
#define RUS(str) codec->toUnicode(str)

class NewClef : public QWizardPage{
    Q_OBJECT

public:
//    QPixmap *px_treble, *px_base, *px_alto, *px_tenor;
    QRadioButton *rd_treb, *rd_bas, *rd_alt, *rd_ten;
//    QLabel *lbl_treble, *lbl_base, *lbl_alto, *lbl_tenor;
    NewClef(QWidget *parent = 0);
//    int nextId() const override;
};
#endif // NEWCLEF_H
