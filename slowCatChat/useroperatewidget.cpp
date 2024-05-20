#include "useroperatewidget.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QPushButton>
#include <QScrollArea>

userOperateWidget::userOperateWidget(QWidget *parent) : QWidget(parent)
{
    QPixmap pixmap(":/icons/appIcon.png");
    m_userHeadIcon = new leftUserOperateItem;
    m_userHeadIcon -> setToolIcon(pixmap);
    m_userHeadIcon -> setFixedSize(50,52);

    m_userChatIcon = new leftUserOperateItem;
    setToolIcon(m_userChatIcon, ":/icons/chatIcon_gray.png", ":/icons/chatIcon_blue.png", "消息");

    m_userContactIcon = new leftUserOperateItem;
    setToolIcon(m_userContactIcon, ":/icons/contactIcon_gray.png", ":/icons/contactIcon_blue.png", "好友");

    m_photoIcon = new leftUserOperateItem;
    setToolIcon(m_photoIcon, ":/icons/photoIcon_gray.png", ":/icons/photoIcon_blue.png", "照片");

    m_videoIcon = new leftUserOperateItem;
    setToolIcon(m_videoIcon, ":/icons/videoIcon_gray.png", ":/icons/videoIcon_blue.png", "视频");

    m_musicIcon = new leftUserOperateItem;
    setToolIcon(m_musicIcon, ":/icons/musicIcon_gray.png", ":/icons/musicIcon_blue.png", "音乐");

    m_fileIcon = new leftUserOperateItem;
    setToolIcon(m_fileIcon, ":/icons/fileIcon_gray.png", ":/icons/fileIcon_blue.png", "文件");

    m_space = new QSpacerItem(0, 350);

    m_vBoxLayout = new QVBoxLayout;
    m_vBoxLayout -> addWidget(m_userHeadIcon);
    m_vBoxLayout -> addWidget(m_userChatIcon);
    m_vBoxLayout -> addWidget(m_userContactIcon);
    m_vBoxLayout -> addWidget(m_photoIcon);
    m_vBoxLayout -> addWidget(m_videoIcon);
    m_vBoxLayout -> addWidget(m_musicIcon);
    m_vBoxLayout -> addWidget(m_fileIcon);
    m_vBoxLayout -> addItem(m_space);

    m_menuIcon = new leftUserOperateItem;
    setToolIcon(m_menuIcon, ":/icons/menuIcon_gray.png", ":/icons/menuIcon_blue.png", "文件");
    m_vBoxLayout -> addWidget(m_menuIcon);

    m_middleWidget = new QFrame;//存放聊天列表;
    m_chatListWidget = new friendChatListWidget;

    m_middleFrameScroll = new QScrollArea;
    m_middleFrameScroll -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//屏蔽水平滚动条
    m_middleFrameScroll -> setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);


    m_middleFrameLayout = new QVBoxLayout(m_middleWidget);//
    m_middleFrameLayout -> setContentsMargins(0, 0, 0, 0);//设置与父组件间的间距为0
    m_middleFrameLayout -> addWidget(m_chatListWidget);
    m_middleFrameScroll -> setWidget(m_middleWidget);//加入滚动条


    //测试
    m_testWidget = new QWidget;
    m_testWidget -> setFixedSize(800, 900);
    QPalette palette = this -> palette();
    palette.setColor(QPalette::Background, Qt::white);
    m_testWidget -> setPalette(palette);
    m_testWidget -> setAutoFillBackground(true);//确保背景颜色被自动填充
    //测试

    m_overallLayout= new QHBoxLayout;
    m_overallLayout -> setContentsMargins(0, 0, 0, 0);
    m_overallLayout -> addLayout(m_vBoxLayout);
    m_overallLayout -> addWidget(m_middleFrameScroll);
    m_overallLayout -> addWidget(m_testWidget);

    setLayout(m_overallLayout);

    setMouseTracking(true);//设置鼠标追踪
}

userOperateWidget::~userOperateWidget()
{
    delete m_userHeadIcon;
    delete m_userChatIcon;
    delete m_userContactIcon;
    delete m_space;
    delete m_menuIcon;
    delete m_vBoxLayout;
    delete m_photoIcon;
    delete m_videoIcon;
    delete m_musicIcon;
    delete m_fileIcon;
    delete m_middleWidget;
    delete m_chatListWidget;
    delete m_testWidget;
    delete m_middleFrameLayout;
    delete m_middleFrameScroll;
    delete m_overallLayout;

}

void userOperateWidget::setToolIcon(leftUserOperateItem *item, QString pixmap_gray_path, QString pixmap_blue_path, QString toolText)
{
    QPixmap pixmap_gray(pixmap_gray_path);
    item ->setToolIcon(pixmap_gray);
    item -> setFixedSize(50,52);
    item -> setToolTip(toolText);
    connect(item, &leftUserOperateItem::mouseMoveToToolIcon, this, [=](){//连接信号。改变图标颜色
        QPixmap pixmap_blue(pixmap_blue_path);
        item ->setToolIcon(pixmap_blue);
    });
    connect(item, &leftUserOperateItem::mouseLeaveToToolIcon, this, [=](){
        QPixmap pixmap_gray(pixmap_gray_path);
        item ->setToolIcon(pixmap_gray);
    });
}

void userOperateWidget::paintEvent(QPaintEvent *)
{
    //QPainter painter(this);
    //painter.setPen(QPen(Qt::white, 2));
    //painter.drawLine(QPoint(60, 0), QPoint(60, this -> height()));
    //painter.drawLine(QPoint(433, 0), QPoint(433, this -> height()));
    m_testWidget -> setFixedSize(this -> width() - 450, this -> height());
    QPalette palette = this -> palette();
    palette.setColor(QPalette::Background, Qt::white);
    m_testWidget -> setPalette(palette);
    m_testWidget -> setAutoFillBackground(true);//确保背景颜色被自动填充
}
