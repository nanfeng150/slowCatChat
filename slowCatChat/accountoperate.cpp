#include "accountoperate.h"
#include "ui_accountoperate.h"
#include <QRegularExpression>
accountOperate::accountOperate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::accountOperate)
{
    ui->setupUi(this);
    ui->pwd_lineEdit->setContextMenuPolicy(Qt::NoContextMenu);//设置无右键菜单
    ui->pwd_lineEdit->setPlaceholderText(QStringLiteral("请输入密码"));//提示
    ui->pwd_lineEdit->setEchoMode(QLineEdit::Password);//设置密码模式
    ui->pwd_lineEdit->setMaxLength(16);//设置最大长度
    ui->account_lineEdit->setPlaceholderText(QStringLiteral("请输入账户"));
    connect(ui->regist_btn, &QPushButton::clicked, this, &accountOperate::on_registBtn_clicked);
    connect(ui->login_btn, &QPushButton::clicked, this, &accountOperate::on_loginBtn_clicked);
}

accountOperate::~accountOperate()
{
    delete ui;
}

QString accountOperate::getAccount()
{
    return m_strAccount;
}

QString accountOperate::getPassword()
{
    return m_strPassword;
}

void accountOperate::on_loginBtn_clicked()
{
    m_strAccount.clear();
    m_strPassword.clear();
    m_strAccount = ui->account_lineEdit->text();
    m_strPassword = ui->pwd_lineEdit->text();
    if(!m_strAccount.isEmpty() && !m_strAccount.isEmpty()){
        QRegularExpression account_expression(QString("^1[3-9]\\d{9}$"));
        if(!account_expression.match(m_strAccount).hasMatch()){
            QMessageBox::critical(this, "登录", "登录失败：用户名不存在！");
            return;
        }
        QRegularExpression pwd_expression(QString("^[0-9]{5,10}$"));
        if(!pwd_expression.match(m_strPassword).hasMatch()){
            QMessageBox::critical(this, "登录", "登录失败：密码错误！");
            return;
        }
        emit userLogin();
    }
    else
        QMessageBox::critical(this, "登录", "登录失败:账户或密码为空!");
}

void accountOperate::on_registBtn_clicked()
{
   m_strAccount.clear();
   m_strPassword.clear();
   m_strAccount = ui->account_lineEdit->text();
   m_strPassword = ui->pwd_lineEdit->text();
   if(!m_strAccount.isEmpty() && !m_strAccount.isEmpty()){
       QRegularExpression account_expression(QString("^1[3-9]\\d{9}$"));
       if(!account_expression.match(m_strAccount).hasMatch()){
           QMessageBox::critical(this, "注册", "注册失败：用户名不合法！");
           return;
       }
       QRegularExpression pwd_expression(QString("^[0-9]{5,10}$"));
       if(!pwd_expression.match(m_strPassword).hasMatch()){
           QMessageBox::critical(this, "注册", "注册失败：密码不合法！");
           return;
       }
       emit userRegist();
   }
   else
       QMessageBox::critical(this, "注册", "注册失败:账户或密码为空!");
}
