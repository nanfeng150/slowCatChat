#include "slowcatchat.h"

slowCatChat::slowCatChat(QObject *parent) : QObject(parent)
{
    //初始化登录界面
    m_accountOperateWidget = new accountOperate;
    //m_accountOperateWidget -> show();

    //套接字
    m_tcpSocket = new QTcpSocket;
    m_tcpSocket -> connectToHost("10.4.80.105", 8888);//连接到服务器
    connect(m_tcpSocket, &QTcpSocket::readyRead, this, &slowCatChat::recvMsg);

    //账户登录界面连接信号
    connect(m_accountOperateWidget, &accountOperate::userRegist, this, &slowCatChat::userWantRegist);
    connect(m_accountOperateWidget, &accountOperate::userLogin, this, &slowCatChat::userWantLogin);

    //设置用户名界面
    m_setUserNameWidget = new setUserName;
    m_setUserNameWidget -> setWindowTitle(QStringLiteral("设置用户名"));
    m_setUserNameWidget -> setWindowIcon(QIcon(":/icons/appIcon.png"));
    m_setUserNameWidget -> resize(420, 280);
    connect(m_setUserNameWidget, &setUserName::userSetName, this, &slowCatChat::userWantSetName);
}

slowCatChat::~slowCatChat()
{
   delete m_accountOperateWidget;
   delete m_tcpSocket;
   delete m_setUserNameWidget;
}

void slowCatChat::recvMsg()
{
    uint uiPDULen = 0;
    m_tcpSocket -> read((char*)&uiPDULen, sizeof(uint));
    uint uiMsgLen = uiPDULen - sizeof(PDU);
    PDU *pdu = mkPDU(uiMsgLen);
    m_tcpSocket -> read((char*)pdu + sizeof(uint), uiPDULen - sizeof(uint));

    switch(pdu -> uiMsgType){
    case ENUM_MSG_TYPE_REGIST_RESPOND : {
        if(0 == strcmp(REGIST_OK, pdu -> caData))//注册成功
            QMessageBox::information(m_accountOperateWidget, "注册", "注册成功");
        else if(0 == strcmp(REGIST_ERROR, pdu -> caData))
            QMessageBox::critical(m_accountOperateWidget, "注册", "注册失败，请稍后重试");
        break;
    }
    case ENUM_MSG_TYPE_LOGIN_RESPOND : {
        if(0 == strcmp(LOGIN_OK_NAMENULL, pdu -> caData)){//登录成功设置用户名
            m_accountOperateWidget -> hide();
            //m_setUserNameWidget -> show();
        }
        else if(0 == strcmp(LOGIN_OK_NAMENONULL, pdu -> caData)){//登录成功跳转到用户界面
            m_accountOperateWidget -> hide();
        }
        else if(0 == strcmp(LOGIN_USER_NO_EXIST, pdu -> caData))
            QMessageBox::critical(m_accountOperateWidget, "登录", "用户不存在");
        else if(0 == strcmp(LOGIN_ERROR_PASSWORD, pdu -> caData))
            QMessageBox::warning(m_accountOperateWidget, "登录", "密码错误");
        else if(0 == strcmp(LOGIN_ERROR_REPEAT, pdu -> caData))
            QMessageBox::warning(m_accountOperateWidget, "登录", "用户已登录");
        break;
    }
    case ENUM_MSG_TYPE_SETUSERNAME_RESPOND : {//设置用户名请求
        if(0 == strcmp(SETUSERNAME_OK, pdu -> caData)){
            m_setUserNameWidget -> hide();
            //用户主操作界面
        }
        else if(0 == strcmp(SETUSERNAME_ERROR, pdu -> caData)){
            QMessageBox::information(m_setUserNameWidget, "设置用户名", "用户名重复");
        }
        break;
    }
    default:break;
    }
}


slowCatChat &slowCatChat::getSlowcatChatInstance()
{
    static slowCatChat instance;
    return instance;
}

QTcpSocket *slowCatChat::getTcpSocket()
{
    return m_tcpSocket;
}

void slowCatChat::userWantLogin()
{
    QByteArray account = m_accountOperateWidget->getAccount().toUtf8();
    QByteArray password = m_accountOperateWidget->getPassword().toUtf8();//将账户密码转成qbytearray

    PDU *pdu = mkPDU(0);
    pdu -> uiMsgType = ENUM_MSG_TYPE_LOGIN_REQUEST;//注册请求

    memcpy(pdu -> caData, account.data(), 32);
    memcpy(pdu -> caData + 32, password.data(), 32);

    m_tcpSocket->write((char*)pdu, pdu -> uiPDULen);

    free(pdu);
    pdu = nullptr;
}

void slowCatChat::userWantRegist()
{
    QByteArray account = m_accountOperateWidget->getAccount().toUtf8();
    QByteArray password = m_accountOperateWidget->getPassword().toUtf8();//将账户密码转成qbytearray

    PDU *pdu = mkPDU(0);
    pdu -> uiMsgType = ENUM_MSG_TYPE_REGIST_REQUEST;//注册请求

    memcpy(pdu -> caData, account.data(), 32);
    memcpy(pdu -> caData + 32, password.data(), 32);
    m_tcpSocket->write((char*)pdu, pdu -> uiPDULen);

    free(pdu);
    pdu = nullptr;
}

void slowCatChat::userWantSetName()
{
     QByteArray account = m_accountOperateWidget->getAccount().toUtf8();
     QByteArray userName = m_setUserNameWidget -> getUserName().toUtf8();
     PDU *pdu = mkPDU(0);
     pdu -> uiMsgType = ENUM_MSG_TYPE_SETUSERNAME_REQUEST;//设置用户名

     memcpy(pdu -> caData, account.data(), 32);
     memcpy(pdu -> caData + 32, userName.data(), 32);
     m_tcpSocket->write((char*)pdu, pdu -> uiPDULen);

     free(pdu);
     pdu = nullptr;
}
