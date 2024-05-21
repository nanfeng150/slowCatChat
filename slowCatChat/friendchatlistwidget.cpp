#include "friendchatlistwidget.h"

friendChatListWidget::friendChatListWidget(QWidget *parent) : QWidget (parent)
{
    m_vHboxLayout = new QVBoxLayout;

    showChatLListItm();
}

friendChatListWidget::~friendChatListWidget()
{
    delete m_vHboxLayout;
    clearList();
}

void friendChatListWidget::addChatListItem(friendChatItem *item)
{
    item -> setFixedSize(370, 100);
    m_friendChatListItem.append(item);

    connect(item, &friendChatItem::mouseEnterFriendItem, item, &friendChatItem::setGrayBack);
    connect(item, &friendChatItem::mouseLeaveFriendItem, item, &friendChatItem::setWhiteBack);
    connect(item, &friendChatItem::mousePressFriendItem, [=](){
        for(uint i = 0; i < m_friendChatListItem.size(); i++){
            m_friendChatListItem[i] -> setAllWhiteBack();
            m_friendChatListItem[i] -> setBackIsBlue(false);
        }
        item -> setBlueBack();
        item -> setBackIsBlue(true);
    });

    updateChatList();
}

void friendChatListWidget::moveChatListItem(friendChatItem *item)
{
    if(m_friendChatListItem.isEmpty() || nullptr == item)
        return;
    QList<friendChatItem*>::iterator it;
    for(it = m_friendChatListItem.begin(); it != m_friendChatListItem.end(); it++){//删除列表项
        if(*it == item){
           m_friendChatListItem.erase(it);
           break;
        }
    }
    updateChatList();
}

void friendChatListWidget::showChatLListItm()
{
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
    //delete m_vHboxLayout;
    m_vHboxLayout = nullptr;
    m_vHboxLayout = new QVBoxLayout;
    showChatLListItm();
}

void friendChatListWidget::clearList()
{
    QList<friendChatItem*>::iterator it;
    for(it = m_friendChatListItem.begin(); it != m_friendChatListItem.end(); ){
        QList<friendChatItem*>::iterator it_1 = it;
        it++;
        m_friendChatListItem.erase(it_1);//删除前一个列表项
    }
}
