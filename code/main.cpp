#include "code.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    code w;
    w.show();
    return a.exec();
}
