#include "leftuseroperateitem.h"
#include <QDebug>
leftUserOperateItem::leftUserOperateItem(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    m_toolIcon = new QLabel;
    m_toolIcon -> setFixedSize(30, 30);//设置显示大小
    m_hBoxLayout = new QVBoxLayout;
    m_hBoxLayout -> addWidget(m_toolIcon);
    setLayout(m_hBoxLayout);
}

leftUserOperateItem::~leftUserOperateItem()
{
    delete m_toolIcon;
    delete m_hBoxLayout;
}

void leftUserOperateItem::setToolIcon(QPixmap pixmap)
{
    m_toolIcon -> setPixmap(pixmap);
    m_toolIcon -> setScaledContents(true);//根据label大小自动缩放图片
}


void leftUserOperateItem::mousePressEvent(QMouseEvent *event)
{

    if(event -> button() == Qt::LeftButton)//只处理鼠标左键点击事件
        emit mouseLeftClicked();
    //qDebug() << "鼠标左按键被点击";
}

void leftUserOperateItem::mouseMoveEvent(QMouseEvent *event)
{
    //qDebug() << "鼠标移入工具控件上";
    emit mouseMoveToToolIcon();
}

void leftUserOperateItem::leaveEvent(QEvent *event)
{
    //qDebug() << "鼠标离开工具控件上";
    emit mouseLeaveToToolIcon();
}

