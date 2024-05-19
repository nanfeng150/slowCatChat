#include "useroperatewidget.h"
#include <QDebug>
#include <QHBoxLayout>

userOperateWidget::userOperateWidget(QWidget *parent) : QWidget(parent)
{
  QPixmap pixmap_1(":/icons/appIcon.png");
  m_userHeadIcon = new leftUserOperateItem;
  m_userHeadIcon -> setToolIcon(pixmap_1);
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

  m_space = new QSpacerItem(10, 350, QSizePolicy::Expanding);

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

  //test

  //test
  setLayout(m_vBoxLayout);

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
}

void userOperateWidget::setToolIcon(leftUserOperateItem *item, QString pixmap_gray_path, QString pixmap_blue_path, QString toolText)
{
    QPixmap pixmap_gray(pixmap_gray_path);
    item ->setToolIcon(pixmap_gray);
    item -> setFixedSize(50,52);
    item -> setToolTip(toolText);
    connect(item, &leftUserOperateItem::mouseMoveToToolIcon, this, [=](){
        QPixmap pixmap_blue(pixmap_blue_path);
        item ->setToolIcon(pixmap_blue);
    });
    connect(item, &leftUserOperateItem::mouseLeaveToToolIcon, this, [=](){
        QPixmap pixmap_gray(pixmap_gray_path);
        item ->setToolIcon(pixmap_gray);
    });
}

void userOperateWidget::mouseMoveEvent(QMouseEvent *)
{
    //qDebug() << "鼠标移入";

}

void userOperateWidget::leaveEvent(QEvent *)
{
    qDebug() << "鼠标移出";
    qDebug() << this ->height() << this -> width();
    qDebug() << m_menuIcon -> height() << m_menuIcon -> width();
    qDebug() << m_userHeadIcon -> height() << m_userHeadIcon -> width();
}

void userOperateWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::white, 2));
    painter.drawLine(QPoint(80, 0), QPoint(80, this -> height()));
}
