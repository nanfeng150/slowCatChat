#ifndef ACCOUNTOPERATE_H
#define ACCOUNTOPERATE_H

#include <QWidget>
#include <QString>
#include <QMessageBox>
namespace Ui {
class accountOperate;
}

class accountOperate : public QWidget
{
    Q_OBJECT

public:
    explicit accountOperate(QWidget *parent = nullptr);
    ~accountOperate();
    QString getAccount();
    QString getPassword();

public slots:
    void on_loginBtn_clicked();//登录按钮槽函数
    void on_registBtn_clicked();//注册按钮槽函数

signals:
    void userRegist();//用户注册
    void userLogin();//用户登录

private:
    Ui::accountOperate *ui;
    QString m_strAccount;
    QString m_strPassword;
};

#endif // ACCOUNTOPERATE_H
