#include "StartWindow.h"
#include <QApplication>
//w->show;
//StartWindow *w;
/*extern */StartWindow *w;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    w = new StartWindow();

    QTranslator qtTranslator;//для перевода Далее, Отмена ...
        if (qtTranslator.load(QLocale::system(),
                    "qt", "_",
                    QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
        {
//            qDebug() << "qtTranslator ok";
            a.installTranslator(&qtTranslator);
        }

    QTranslator qtBaseTranslator;
    if (qtBaseTranslator.load("qtbase_" + QLocale::system().name(),
                QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
    {
//        qDebug() << "qtBaseTranslator ok";
        a.installTranslator(&qtBaseTranslator);
    }
//    NewNotes w;
//    w.area->setVisible(false);
    w->show();

//    NewScore w_sc;
//    w_sc.show();
//    w.area->setVisible(true);

    return a.exec();
}
