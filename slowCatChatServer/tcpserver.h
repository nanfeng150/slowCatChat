#ifndef TCPSERVER_H
#define TCPSERVER_H
#include <QTcpServer>
#include <QMap>
#include <QPair>
#include "tcpsocket.h"
class tcpServer : public QTcpServer
{
    Q_OBJECT
public:
    tcpServer();
    static tcpServer& getServerInstance();
    void incomingConnection(qintptr socketDescriptor) override;


public:
    void deleteOfflineSocket(tcpSocket*);

private:
    QMap<qintptr, tcpSocket*> m_connectSocketHash;//存储连接的socket
};

#endif // TCPSERVER_H
