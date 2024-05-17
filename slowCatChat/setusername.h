#ifndef SETUSERNAME_H
#define SETUSERNAME_H
//登录成功后需要设置用户名
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QString>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPainter>
#include <QImage>
#include <QPoint>
#include <QPaintEvent>
#include <QMessageBox>
#include <QByteArray>
#include "protocol.h"
class setUserName : public QWidget
{
    Q_OBJECT
public:
    explicit setUserName(QWidget *parent = nullptr);
    QString getUserName(){return m_userName;}

public slots:
    void on_userNameAffirmBtn_clicked();//按钮响应

signals:
    void userSetName();

protected:
    void paintEvent(QPaintEvent*) override;

private:
    QLabel* m_promptLab = nullptr;
    QLineEdit* m_userNameText = nullptr;
    QPushButton* m_userNameAffirmBtn = nullptr;
    QString m_userName; //存储用户名
    QHBoxLayout* m_HBoxLayout = nullptr;
    QVBoxLayout* m_VBoxLayout = nullptr;
    QLabel* m_userNameLab = nullptr;
};

#endif // SETUSERNAME_H
