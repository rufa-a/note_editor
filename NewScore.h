#ifndef NEWSCORE_H
#define NEWSCORE_H
#include "NewName.h"
#include <QtWidgets>
#include "NewNotes.h"
#include "StartWindow.h"
//#include "main.cpp"
class NewNotes;
class StartWindow;
//extern StartWindow *w;
class NewScore : public QWizard
{
    Q_OBJECT
//protected:
//    QLineEdit *edtName, *edtComposer;
//    QLabel *lblName, *lblComposer;
//    QPushButton *btnCancel, *btnNext, *btnBack, *btnFinish;
public:
    friend class StartWindow;
    friend class NewNotes;
    enum {Page_Name, Page_Clef, Page_Sign, Page_Rythm

    };


    NewNotes *note_parent = 0;
//    addPage(new IntroPage);
//        addPage(new ClassInfoPage);



    NewScore();
//    void accept();

    NewNotes *wnNewNotes;

    void accept() override;
    void showHelp();

//public slots:
//    void showNewNotes();

};

#endif // NEWSCORE_H
