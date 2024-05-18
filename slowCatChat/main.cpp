#include <QApplication>
#include "slowcatchat.h"
//test
#include "leftuseroperateitem.h"
#include "useroperatewidget.h"
//
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    slowCatChat instance(nullptr);

    //test
    userOperateWidget test;
    test.show();
    //test

    return a.exec();
}
