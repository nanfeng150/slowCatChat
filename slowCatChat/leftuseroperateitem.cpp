#include "leftuseroperateitem.h"
#include <QDebug>
leftUserOperateItem::leftUserOperateItem(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    m_toolIcon = new QLabel;
    m_toolIcon -> setFixedSize(60, 60);//设置显示大小

    m_toolIcon -> setStyleSheet("QLabel{border : 1px solid black; }");
    QPixmap pixmap(":/icons/appIcon.png");
    setToolIcon(pixmap);

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


void leftUserOperateItem::mousePressEvent(QMouseEvent *)
{
    qDebug() << "鼠标按键被点击";
    emit mouseLeftClicked();
}

void leftUserOperateItem::mouseMoveEvent(QMouseEvent *)//
{
    this -> setStyleSheet("leftUserOperateItem {background-color : gray;}");
}

void leftUserOperateItem::leaveEvent(QEvent *)
{
    this -> setStyleSheet("leftUserOperateItem {background-color : white;}");
}
