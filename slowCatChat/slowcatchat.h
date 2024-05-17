#ifndef SLOWCHAT_H
#define SLOWCHAT_H
#include <QObject>
#include <QMainWindow>
#include <QTcpSocket>
#include <QByteArray>
#include <QMessageBox>
#include <QIcon>
#include "protocol.h"
#include "accountoperate.h"
#include "setusername.h"
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
    void userWantSetName();
private:
    QTcpSocket* m_tcpSocket = nullptr;//套接字
    accountOperate* m_accountOperateWidget = nullptr;//账户操作界面
    setUserName* m_setUserNameWidget = nullptr;//设置用户名界面
};

#endif // SLOWCHAT_H
