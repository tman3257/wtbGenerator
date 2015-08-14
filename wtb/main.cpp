#include "wtb.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    wtb w;
    w.show();
    return a.exec();
}
