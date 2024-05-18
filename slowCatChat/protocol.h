#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <QTimer>
#include <QEventLoop>

typedef unsigned int uint;
//注册结果
#define REGIST_OK "regist succeed"
#define REGIST_NO "regist failed"
#define REGIST_ERROR "account repeat"
//登录结果
#define LOGIN_OK_NAMENULL "login succeed nameIsNull"
#define LOGIN_OK_NAMENONULL "login succeed"
#define LOGIN_USER_NO_EXIST "account no exist"
#define LOGIN_ERROR_PASSWORD "password error"
#define LOGIN_ERROR_REPEAT "repeat login"
//设置用户名结果
#define SETUSERNAME_OK "set userName succeed"
#define SETUSERNAME_ERROR "userName repeat"
//延时函数
#define SYNCED_EXEC_DELAY_TIME(TIME_MS) {QEventLoop eventLoop;\
    QTimer::singleShot(TIME_MS, &eventLoop, &QEventLoop::quit);\
    eventLoop.exec();}

struct PDU               //protocol data unity 协议数据单元
{
    uint uiPDULen;       // 总的协议数据单元大小
    uint uiMsgType;      // 消息类型
    char caData[64];     // 其他数据
    uint uiMsgLen;       // 实际消息长度
    int caMsg[];         // 实际消息，主要通过caMsg访问消息数据
};

PDU *mkPDU(uint uiMsgLen);

enum ENUM_MSG_TYPE{
    ENUM_MSG_TYPE_MIN = 0,

    ENUM_MSG_TYPE_REGIST_REQUEST,//注册请求
    ENUM_MSG_TYPE_REGIST_RESPOND,//注册回复

    ENUM_MSG_TYPE_LOGIN_REQUEST,//登录请求
    ENUM_MSG_TYPE_LOGIN_RESPOND,//登录回复

    ENUM_MSG_TYPE_SETUSERNAME_REQUEST,//设置用户名请求
    ENUM_MSG_TYPE_SETUSERNAME_RESPOND,//设置用户名回复
};

enum CHECK_USER_LOGIN{
    ENUM_CHECK_USER_LOGIN = 0,
    ENUM_USER_NO_EXIST,       // 用户不存在
    ENUM_USER_PASSWORD_ERROR, // 用户密码错误
    ENUM_USER_REPEAT_LOGIN,   //用户重复登录
    ENUM_USER_EXIST_NAMENULL,    //用户存在用户为空
    ENUM_USER_EXIST_NAMENONULL,    //用户存在用户名不为空
};
#endif // PROTOCOL_H
