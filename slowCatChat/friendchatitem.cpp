#include "friendchatitem.h"
#include <QDebug>
friendChatItem::friendChatItem(QWidget* parent) : QWidget(parent)
{
    //设置白色背景
    QPalette palette = this -> palette();
    palette.setColor(QPalette::Background, Qt::white);
    this -> setPalette(palette);
    this -> setAutoFillBackground(true);//确保背景颜色被自动填充

    m_friendHeadSculpture = new QLabel;
    //m_friendHeadSculpture -> setStyleSheet("QLabel {border : 2px solid red; }");
    setFriendHeadSculpture(m_friendHeadSculpture, ":/icons/appIcon.png");

    m_friendName = new QLabel;
    //m_friendName -> setStyleSheet("QLabel {border : 2px solid red; }");
    setFriendName(m_friendName, "zhengchendong");

    m_lastTimeChatMsg = new QLabel;
    //m_lastTimeChatMsg -> setStyleSheet("QLabel {border : 2px solid black; }");
    setLastTimeChatMsg(m_lastTimeChatMsg, "hello, I am zhengchendong");

    m_vBoxlayout = new QVBoxLayout;
    m_vBoxlayout -> addWidget(m_friendName);
    m_vBoxlayout -> addWidget(m_lastTimeChatMsg);

    m_space = new QSpacerItem(10, 0, QSizePolicy::Expanding);

    m_hBoxlayout = new QHBoxLayout;
    m_hBoxlayout -> addWidget(m_friendHeadSculpture);
    m_hBoxlayout -> addItem(m_space);
    m_hBoxlayout -> addLayout(m_vBoxlayout);

    setLayout(m_hBoxlayout);

    //鼠标移入好友项时变灰色
    connect(this, &friendChatItem::mouseEnterFriendItem, this, [&](){
        if(m_flagMouseLeftButtonIdPress)
            return;
        QPalette palette = this -> palette();
        palette.setColor(QPalette::Background, QColor(245,245,245));
        this -> setPalette(palette);
        this -> setAutoFillBackground(true);//确保背景颜色被自动填充
    });
    //鼠标移出时好友项变白色
    connect(this, &friendChatItem::mouseLeaveFriendItem, this, [&](){
        if(m_flagMouseLeftButtonIdPress)
            return;
        QPalette palette = this -> palette();
        palette.setColor(QPalette::Background, Qt::white);
        this -> setPalette(palette);
        this -> setAutoFillBackground(true);//确保背景颜色被自动填充
    });
    //点击鼠标左键时选中变为蓝色
    connect(this, &friendChatItem::mousePressFriendItem, this, [&](){
        QPalette palette = this -> palette();
        palette.setColor(QPalette::Background, QColor(0,153,255));
        this -> setPalette(palette);
        this -> setAutoFillBackground(true);//确保背景颜色被自动填充
    });
}

friendChatItem::~friendChatItem()
{
    delete m_friendHeadSculpture;
    delete m_friendName;
    delete m_lastTimeChatMsg;
    delete m_vBoxlayout;
    delete m_space;
    delete m_hBoxlayout;
}

void friendChatItem::setFriendHeadSculpture(QLabel *headSculptuer, QString headSculpturePath)
{
    QPixmap pixMap(headSculpturePath);
    headSculptuer -> setPixmap(pixMap);
    headSculptuer -> setScaledContents(true);//根据label大小自动缩放图片
    headSculptuer -> setFixedSize(80, 80);
}

void friendChatItem::setFriendName(QLabel *headSculptuer, QString friendName)
{
    headSculptuer -> setText(friendName);
    QFont font("weiruanyahei", 16, 5, false);
    font.setBold(true);
    headSculptuer -> setFont(font);
    headSculptuer -> setFixedSize(230, 50);
}


void friendChatItem::setLastTimeChatMsg(QLabel *headSculptuer, QString chatMsg)
{
    headSculptuer -> setText(chatMsg);
    headSculptuer -> setFixedSize(230, 30);
}

void friendChatItem::setFriendItem(QString headSculpturePath, QString friendName, QString chatMsg)
{
    setFriendHeadSculpture(m_friendHeadSculpture, headSculpturePath);
    setFriendName(m_friendName, friendName);
    setLastTimeChatMsg(m_lastTimeChatMsg, chatMsg);
}

void friendChatItem::mousePressEvent(QMouseEvent *event)
{
    if(event -> buttons() == Qt::LeftButton){
        emit mousePressFriendItem();
        m_flagMouseLeftButtonIdPress = true;
    }
}

void friendChatItem::enterEvent(QEvent *)
{
    emit mouseEnterFriendItem();
    //qDebug() << "鼠标移入";
}

void friendChatItem::leaveEvent(QEvent *)
{
    emit mouseLeaveFriendItem();
    //qDebug() << "鼠标移出";
}
