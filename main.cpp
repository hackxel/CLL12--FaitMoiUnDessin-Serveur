#include <QtGui/QApplication>
#include "dessinserveur.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DessinServeur w;
    w.show();
    
    return a.exec();
}
