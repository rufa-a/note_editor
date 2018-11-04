#include "StartWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartWindow w;
//    NewNotes w;
//    w.area->setVisible(false);
    w.show();

//    NewScore w_sc;
//    w_sc.show();
//    w.area->setVisible(true);

    return a.exec();
}
