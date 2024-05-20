#ifndef FRIENDCHATLISTWIDGET_H
#define FRIENDCHATLISTWIDGET_H

#include <QWidget>
#include <QList>
#include "friendchatitem.h"
class friendChatListWidget : public QWidget
{
public:
    friendChatListWidget(QWidget* parent = nullptr);

public:
    void addChatListItem(friendChatItem*);


private:
    QList<friendChatItem*> m_friendChatListItem;
};

#endif // FRIENDCHATLISTWIDGET_H
