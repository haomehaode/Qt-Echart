#include "EchartDome.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EchartDome w;
    w.show();
    return a.exec();
}
