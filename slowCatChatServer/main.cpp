#include "server.h"
#include <QApplication>
#include <QIcon>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    server w;
    w.setWindowTitle("SlowCatChat");
    w.setWindowIcon(QIcon(":/icons/appIcon.png"));
    //w.show();

    return a.exec();
}
