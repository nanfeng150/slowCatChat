#ifndef FRIENDCHATLISTWIDGET_H
#define FRIENDCHATLISTWIDGET_H

#include <QWidget>
#include <QList>
#include <QVBoxLayout>
#include <QLayout>
#include "friendchatitem.h"
class friendChatListWidget : public QWidget
{
public:
    friendChatListWidget(QWidget* parent = nullptr);
    ~friendChatListWidget();
public:
    void addChatListItem(friendChatItem*); //添加聊天列表项
    void moveChatListItem(friendChatItem*);//移出好友列表项
    void showChatLListItm();//显示好友列表项
    void updateChatList();//刷新好友列表项
    void clearList();//清理内存

private:
    QList<friendChatItem*> m_friendChatListItem;//存储聊天列表项
    QVBoxLayout* m_vHboxLayout = nullptr;//好友列表项垂直布局
};

#endif // FRIENDCHATLISTWIDGET_H
