#include <QApplication>
#include "slowcatchat.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    slowCatChat instance(nullptr);
    return a.exec();
}
