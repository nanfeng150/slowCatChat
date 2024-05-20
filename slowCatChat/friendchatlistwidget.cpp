#include "friendchatlistwidget.h"

friendChatListWidget::friendChatListWidget(QWidget *parent) : QWidget (parent)
{
    m_vHboxLayout = new QVBoxLayout;

    friendChatItem *item1 = new friendChatItem;
    item1 -> setFixedSize(370, 100);
    m_friendChatListItem.append(item1);
    friendChatItem *item2 = new friendChatItem;
    item2 -> setFixedSize(370, 100);
    m_friendChatListItem.append(item2);
    friendChatItem *item3 = new friendChatItem;
    item3 -> setFixedSize(370, 100);
    m_friendChatListItem.append(item3);
    friendChatItem *item4 = new friendChatItem;
    item4 -> setFixedSize(370, 100);
    m_friendChatListItem.append(item4);
    friendChatItem *item5 = new friendChatItem;
    item5 -> setFixedSize(370, 100);
    m_friendChatListItem.append(item5);
    friendChatItem *item6 = new friendChatItem;
    item6 -> setFixedSize(370, 100);
    m_friendChatListItem.append(item6);
    friendChatItem *item7 = new friendChatItem;
    item7 -> setFixedSize(370, 100);
    m_friendChatListItem.append(item7);
    friendChatItem *item8 = new friendChatItem;
    item8 -> setFixedSize(370, 100);
    m_friendChatListItem.append(item8);
    friendChatItem *item9 = new friendChatItem;
    item9 -> setFixedSize(370, 100);
    m_friendChatListItem.append(item9);
    friendChatItem *item10 = new friendChatItem;
    item10 -> setFixedSize(370, 100);
    m_friendChatListItem.append(item10);


    showChatLListItm();
}

friendChatListWidget::~friendChatListWidget()
{
    delete m_vHboxLayout;
}

void friendChatListWidget::addChatListItem(friendChatItem *item)
{
    m_friendChatListItem.append(item);
    updateChatList();
}

void friendChatListWidget::showChatLListItm()
{
    //QList<friendChatItem *>::iterator it;
    for(uint i = 0; i < m_friendChatListItem.size(); i++)
        m_vHboxLayout -> addWidget(m_friendChatListItem[i]);
    m_vHboxLayout -> setContentsMargins(0, 0, 0, 0);//设置列表的边距
    m_vHboxLayout -> setSpacing(0);//设置组件间间距
    this -> setLayout(m_vHboxLayout);
}

void friendChatListWidget::updateChatList()
{
    //先清空布局类的控件
    delete this -> layout();
    delete m_vHboxLayout;
    m_vHboxLayout = nullptr;
    m_vHboxLayout = new QVBoxLayout;
    for(uint i = 0; i < m_friendChatListItem.size(); i++)
        m_vHboxLayout -> addWidget(m_friendChatListItem[i]);
    this -> setLayout(m_vHboxLayout);
}
