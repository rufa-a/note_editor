#ifndef NEWNAME_H
#define NEWNAME_H
#include <QtWidgets>
#include "NewClef.h"
#define RUS(str) codec->toUnicode(str)

class NewName : public QWizardPage{
    Q_OBJECT

public:
    QLineEdit *edtName, *edtComposer;
    QLabel *lblName, *lblComposer;
    NewName(QWidget *parent = 0);
//    int nextId() const override;
};

#endif // NEWNAME_H
