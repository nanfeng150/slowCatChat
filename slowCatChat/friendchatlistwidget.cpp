#include "friendchatlistwidget.h"

friendChatListWidget::friendChatListWidget(QWidget *parent) : QWidget (parent)
{

}

void friendChatListWidget::addChatListItem(friendChatItem *item)
{
    m_friendChatListItem.append(item);
}
