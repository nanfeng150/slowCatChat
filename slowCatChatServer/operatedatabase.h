#ifndef OPERATEDATABASE_H
#define OPERATEDATABASE_H
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "protocol.h"
class operatedatabase : public QObject
{
    Q_OBJECT //加入宏，使用信号与槽
public:
    explicit  operatedatabase(QObject *parent = nullptr);
    static operatedatabase& getDBoperateInstance();//单例模式节约内存
    bool init();//初始化数据库
    ~operatedatabase();
public: //处理数据入库操作
    bool userinsertToDb(char* account, char* password);//注册用户信息入库
    uint userLoginCheck(char* account, char* password);//检查用户登录
    void userOffline(const char* account);//用户离线改变状态
    uint userSetNameToDb(char* account, char* username);//用户设置用户名
private:
    QSqlDatabase m_databsaeOperate;//数据库驱动
};

#endif // OPERATEDATABASE_H
