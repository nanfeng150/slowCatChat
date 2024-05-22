#include "operatedatabase.h"
#include <QDebug>
operatedatabase::operatedatabase(QObject *parent) : QObject (parent)
{
    m_databsaeOperate = QSqlDatabase::addDatabase("QMYSQL");
}

operatedatabase &operatedatabase::getDBoperateInstance()
{
    static operatedatabase instance;
    return instance;
}

bool operatedatabase::init()
{
    m_databsaeOperate.setHostName("127.0.0.1");
    m_databsaeOperate.setPort(3306);
    m_databsaeOperate.setUserName("root");
    m_databsaeOperate.setPassword("zcd15599210255");
    m_databsaeOperate.setDatabaseName("slowcatchat");
    if(!m_databsaeOperate.open())
       return false;
    m_databsaeOperate.close();
    return true;
}

operatedatabase::~operatedatabase()
{
    //m_databsaeOperate.close();关闭数据库
}

bool operatedatabase::userinsertToDb(char *account, char *password)
{
    if(nullptr == account || nullptr == password || !m_databsaeOperate.open())
        return false;
    QSqlQuery sqlQuery;
    //检测账户合法性,账户名唯一不让重复
    QString strSelectAccount = QString("select account_name from user where account_name = \'%1\'").arg(account);
    bool accountIsLegal = true;
    sqlQuery.exec(strSelectAccount);
    while(sqlQuery.next()){
        if(QString(account) == sqlQuery.value("account_name").toString()){
            accountIsLegal = false;
            break;
        }
    }
    if(accountIsLegal){
        QString query = QString("insert into user(account_name, password) values(\'%1\', \'%2\')")
                               .arg(account).arg(password);
        if(sqlQuery.exec(query)){
            m_databsaeOperate.close();
            return true;
        }
    }
    m_databsaeOperate.close();
    return accountIsLegal;
}

uint operatedatabase::userLoginCheck(char *account, char *password)
{
    if(nullptr == account || nullptr == password || !m_databsaeOperate.open())
        return ENUM_CHECK_USER_LOGIN;
    QSqlQuery sqlQuery;
    //检查用户账户
    bool accountIsExist = false;
    QString checkAccount = QString("select account_name from user where account_name = \'%1\'").arg(account);
    sqlQuery.exec(checkAccount);
    while(sqlQuery.next()){
        if(QString(account) == sqlQuery.value("account_name").toString()){//用户存在
            accountIsExist = true;
            sqlQuery.clear();
            break;
        }
    }
    //检查用户密码
    bool passwordIsRight = false;
    QString checkPassword = QString("select password from user where password = \'%1\'").arg(password);
    sqlQuery.exec(checkPassword);
    while(sqlQuery.next()){
        if(QString(password) == sqlQuery.value("password").toString()){//密码正确
            passwordIsRight = true;
            break;
        }
    }
    if(!accountIsExist){//用户不存在
        m_databsaeOperate.close();
        return ENUM_USER_NO_EXIST;
    }
    else if(!passwordIsRight){//密码错误
        m_databsaeOperate.close();
        return ENUM_USER_PASSWORD_ERROR;
    }
    //当账户名与密码都正确时，检查用户是否重复登录
    sqlQuery.clear();
    QString userIsRepeatLogin = QString("select online_status from user where account_name = \'%1\'").arg(account);
    sqlQuery.exec(userIsRepeatLogin);
    while(sqlQuery.next()){
        if(QString::number(1) == sqlQuery.value("online_status").toString()){
            m_databsaeOperate.close();
            return ENUM_USER_REPEAT_LOGIN;
        }
    }
    //如果都没问题，设置登录状态
    sqlQuery.clear();
    QString updateUserStatus = QString("update user set online_status = 1 where account_name = \'" \
                                       "%1\' and password = \'%2\'").arg(account).arg(password);
    sqlQuery.exec(updateUserStatus);
    //查询用户名
    sqlQuery.clear();
    QString queryUserName = QString("select username from user where account_name = \'%1\'").arg(account);
    sqlQuery.exec(queryUserName);
    while(sqlQuery.next()){
        if(sqlQuery.value("username").toString().isEmpty()){
            m_databsaeOperate.close();
            return ENUM_USER_EXIST_NAMENULL;
        }
    }
    m_databsaeOperate.close();
    return ENUM_USER_EXIST_NAMENONULL;
}

void operatedatabase::userOffline(const char *account)
{
    if(nullptr == account || !m_databsaeOperate.open())
        return;
    QSqlQuery sqlQuery;
    QString userOffline = QString("update user set online_status = 0 where account_name = \'%1\'").arg(account);
    sqlQuery.exec(userOffline);//用户离线，状态设为0
    m_databsaeOperate.close();
}

uint operatedatabase::userSetNameToDb(char *account, char *username)
{
    if(nullptr == account || nullptr == username || !m_databsaeOperate.open())
        return ENUM_CHECK_USER_NAME;
    QSqlQuery sqlQuery;
    QString userNameIsExist = QString("select username from user");
    sqlQuery.exec(userNameIsExist);
    while(sqlQuery.next()){
        if(sqlQuery.value("username").toString() == QString(username)){
            m_databsaeOperate.close();
            return ENUM_CHECK_USER_NAME_EXIST;
        }
    }
    QString userSetName = QString("update user set username = \'%1\' where account_name = \'%2\'")
                                 .arg(username).arg(account);
    sqlQuery.exec(userSetName);
    m_databsaeOperate.close();
    return ENUM_CHECK_USER_NAME_OK;
}
