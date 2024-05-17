#ifndef TCPSOCKET_H
#define TCPSOCKET_H
#include <QTcpSocket>
#include "protocol.h"
#include "operatedatabase.h"
class tcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    tcpSocket();
    static tcpSocket &getSocketInstance();

public slots:
    void recvMsg();//接收消息
    void handleUserOffline();//用户下线

signals:
    void offline(tcpSocket*);

public: //处理请求的函数
    PDU* handleRegistRequest(PDU* msg);//注册
    PDU* handleLoginRequest(PDU* msg);//登录
    PDU* handleSetUserNameRequest(PDU* msg);//设置用户名

private:
    QString m_strAccount;
};

#endif // TCPSOCKET_H
