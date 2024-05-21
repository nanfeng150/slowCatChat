#ifndef USEROPERATEWIDGET_H
#define USEROPERATEWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QColor>
#include <QPoint>
#include <QFrame>
#include <QScrollArea>
#include "leftuseroperateitem.h"
#include "friendchatlistwidget.h"
class userOperateWidget : public QWidget
{
    Q_OBJECT
public:
    explicit userOperateWidget(QWidget *parent = nullptr);
    ~userOperateWidget() override;

    void setToolIcon(leftUserOperateItem* item, QString pixmap_gray_path, QString pixmap_blue_path, QString toolText);
    void queryDBGetLastTimeChatMSg();


signals:

public slots:

protected:
    void paintEvent(QPaintEvent*) override; //绘画事件

private:
    leftUserOperateItem* m_userHeadIcon = nullptr;//头像
    leftUserOperateItem* m_userChatIcon = nullptr;//聊天
    leftUserOperateItem* m_userContactIcon = nullptr;//联系人
    leftUserOperateItem* m_photoIcon = nullptr;//照片
    leftUserOperateItem* m_videoIcon = nullptr;//视频
    leftUserOperateItem* m_musicIcon = nullptr;//音乐
    leftUserOperateItem* m_fileIcon = nullptr;//文件
    QSpacerItem* m_space = nullptr;//留白

    leftUserOperateItem* m_menuIcon = nullptr;//联系人
    QVBoxLayout* m_vBoxLayout = nullptr;

    //中间件
    QFrame* m_middleWidget = nullptr;
    friendChatListWidget* m_chatListWidget = nullptr;
    QWidget *m_testWidget = nullptr; //测试使用 最右侧
    QVBoxLayout* m_middleFrameLayout = nullptr;
    QScrollArea* m_middleFrameScroll = nullptr;

    QHBoxLayout* m_overallLayout = nullptr;
};

#endif // USEROPERATEWIDGET_H
