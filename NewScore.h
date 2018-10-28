#ifndef NEWSCORE_H
#define NEWSCORE_H
#include "NewName.h"
#include <QtWidgets>
#include "NewNotes.h"

class NewScore : public QWizard
{
    Q_OBJECT
//protected:
//    QLineEdit *edtName, *edtComposer;
//    QLabel *lblName, *lblComposer;
//    QPushButton *btnCancel, *btnNext, *btnBack, *btnFinish;
public:
    enum {Page_Name, Page_Clef, Page_Sign, Page_Rythm

    };

//    addPage(new IntroPage);
//        addPage(new ClassInfoPage);



    NewScore();
//    void accept();

    NewNotes wnNewNotes;

    void accept() override;
    void showHelp();

//public slots:
//    void showNewNotes();

};

#endif // NEWSCORE_H
