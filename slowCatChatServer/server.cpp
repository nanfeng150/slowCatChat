#include "server.h"
#include "ui_server.h"
#include <QDebug> //打印调试
server::server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::server)
{
    ui->setupUi(this);
    //初始化数据库
    if(!operatedatabase::getDBoperateInstance().init())
        QMessageBox::critical(this, "打开数据库", "打开失败!!!");
    //监听连接
    tcpServer::getServerInstance().listen(QHostAddress::Any, 8888);
}

server::~server()
{
    delete ui;
}
