#include "setusername.h"
setUserName::setUserName(QWidget *parent) : QWidget(parent)
{
    m_promptLab = new QLabel;
    m_userNameText = new QLineEdit;
    m_userNameAffirmBtn = new QPushButton;
    m_HBoxLayout = new QHBoxLayout;

    //设置样式
    m_promptLab -> setText(QStringLiteral("用户名:"));
    m_userNameAffirmBtn ->setText(QStringLiteral("确认"));
    m_HBoxLayout -> addWidget(m_promptLab);
    m_HBoxLayout -> addWidget(m_userNameText);
    m_HBoxLayout -> addWidget(m_userNameAffirmBtn);
    //使用空白文本控件控制输入框在底部
    m_userNameLab = new QLabel;
    m_userNameLab -> setText(QStringLiteral(""));
    m_userNameLab -> setAlignment(Qt::AlignCenter);

    m_VBoxLayout = new QVBoxLayout;
    m_VBoxLayout -> addWidget(m_userNameLab);
    m_VBoxLayout -> addLayout(m_HBoxLayout);
    this -> setLayout(m_VBoxLayout);
    connect(m_userNameAffirmBtn, &QPushButton::clicked, this, &setUserName::on_userNameAffirmBtn_clicked);
}

void setUserName::on_userNameAffirmBtn_clicked()
{
    m_userName = m_userNameText -> text();
    if(m_userName.isEmpty()){
        QMessageBox::warning(this, "设置用户名", "用户名为空");
        m_userName.clear();
        return;
    }
    else if(32 <= m_userName.size()){
        QMessageBox::warning(this, "设置用户名", "用户名太长");
        m_userName.clear();
        return;
    }
    emit userSetName();
}

void setUserName::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.drawImage(QPoint(100, 20), QImage(":/icons/appIcon.png"));
}
