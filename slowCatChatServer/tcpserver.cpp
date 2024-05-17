#include "tcpserver.h"
#include <QDebug>
tcpServer::tcpServer()
{

}

tcpServer &tcpServer::getServerInstance()
{
    static tcpServer instance;
    return instance;
}

void tcpServer::incomingConnection(qintptr socketDescriptor)
{
    tcpSocket *socket = new tcpSocket;
    socket -> setSocketDescriptor(socketDescriptor);
    m_connectSocketHash[socketDescriptor] = socket;

    //下线时需要删除scoket
    connect(socket, &tcpSocket::offline, this, &tcpServer::deleteOfflineSocket);
}

void tcpServer::deleteOfflineSocket(tcpSocket *waitSocket)
{
    QMap<qintptr, tcpSocket*>::iterator it;
    for(it = m_connectSocketHash.begin(); it != m_connectSocketHash.end(); it++){
        if(waitSocket == it.value()){
            m_connectSocketHash.remove(it.key());
            break;
        }
    }
}
