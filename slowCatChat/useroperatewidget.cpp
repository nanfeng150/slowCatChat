#include "useroperatewidget.h"

userOperateWidget::userOperateWidget(QWidget *parent) : QWidget(parent)
{
  m_userHeadPixmap = new leftUserOperateItem;
  leftUserOperateItem* m_userHeadPixmap_1 = new leftUserOperateItem;
  leftUserOperateItem* m_userHeadPixmap_2 = new leftUserOperateItem;
  leftUserOperateItem* m_userHeadPixmap_3 = new leftUserOperateItem;
  leftUserOperateItem* m_userHeadPixmap_4 = new leftUserOperateItem;
  leftUserOperateItem* m_userHeadPixmap_5 = new leftUserOperateItem;
  m_hBoxLayout = new QVBoxLayout;
  m_hBoxLayout -> addWidget(m_userHeadPixmap);
  m_hBoxLayout -> addWidget(m_userHeadPixmap_1);
  m_hBoxLayout -> addWidget(m_userHeadPixmap_2);
  m_hBoxLayout -> addWidget(m_userHeadPixmap_3);
  m_hBoxLayout -> addWidget(m_userHeadPixmap_4);
  m_hBoxLayout -> addWidget(m_userHeadPixmap_5);
  setLayout(m_hBoxLayout);
}
