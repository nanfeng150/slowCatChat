#ifndef SLOWCHAT_H
#define SLOWCHAT_H
#include <QObject>
#include <QMainWindow>
#include <QTcpSocket>
#include <QByteArray>
#include <QMessageBox>
#include "accountoperate.h"
#include "protocol.h"
class slowCatChat : public QObject
{
    Q_OBJECT
public:
    explicit slowCatChat(QObject* parent = nullptr);
    static slowCatChat& getSlowcatChatInstance();
    QTcpSocket* getTcpSocket();
    ~slowCatChat();

public slots:
    void recvMsg();
    void userWantLogin();
    void userWantRegist();
private:
    QTcpSocket* m_tcpSocket = nullptr;//套接字
    accountOperate* m_accountOperateWidget = nullptr;//账户操作界面
};

#endif // SLOWCHAT_H
