/*
 * @time:2024.5.17
 * @author:zhengchendong
*/
#include <QApplication>
#include "slowcatchat.h"
//test
#include "leftuseroperateitem.h"
#include "useroperatewidget.h"
#include "friendchatitem.h"
//
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    slowCatChat instance(nullptr);

    //test
    userOperateWidget test;
    test.setWindowTitle("slowcat");
    test.setWindowIcon(QIcon(":/icons/appIcon.png"));
    test.resize(1250, 880);
    test.setMinimumSize(400, 900);
    test.show();
    //test

    return a.exec();
}
