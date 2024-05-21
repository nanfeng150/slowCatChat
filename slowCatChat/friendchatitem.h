#ifndef FRIENDCHATITEM_H
#define FRIENDCHATITEM_H
/*
 * @用于用户操作主界面显示聊天列表项
 * @继承于QListWidgetItem
 * @显示好友头像与名字
 * @显示最近的一条聊天信息
*/
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QFont>
#include <QSpacerItem>
#include <QFont>
#include <QPalette> //填充背景颜色
#include <QMouseEvent>
#include <QEvent>
#include <QColor>
class friendChatItem : public QWidget
{
    Q_OBJECT //使用信号与槽

public:
    friendChatItem(QWidget* parent = nullptr);
    friendChatItem(QString userName, QString chatMsg, QWidget* parent = nullptr);//重载
    ~friendChatItem() override;

    void setFriendHeadSculpture(QLabel*, QString);
    void setFriendName(QLabel*, QString);
    void setLastTimeChatMsg(QLabel*, QString);
    void setFriendItem(QString, QString, QString); //设置朋友项消息

    void setBackIsBlue(bool isBlue){m_flagMouseLeftButtonIdPress = isBlue;}

protected:
    void mousePressEvent(QMouseEvent*) override;//鼠标点击事件
    void enterEvent(QEvent*) override;//鼠标移入事件
    void leaveEvent(QEvent*) override;//鼠标离开事件

signals:
    void mouseEnterFriendItem();
    void mouseLeaveFriendItem();
    void mousePressFriendItem();

public slots:
    void setWhiteBack();//设置白色背景
    void setAllWhiteBack();//设置全部背景为白色
    void setBlueBack(); //设置绿色背景
    void setGrayBack(); //设置灰色背景

private:
    QLabel* m_friendHeadSculpture = nullptr; // 存放好友头像
    QLabel* m_friendName = nullptr;          // 存放好友用户名
    QLabel* m_lastTimeChatMsg = nullptr;     // 存放最后一次聊天信息

    QVBoxLayout* m_vBoxlayout = nullptr;

    QSpacerItem* m_space = nullptr;

    QHBoxLayout* m_hBoxlayout = nullptr;

    bool m_flagMouseLeftButtonIdPress = false;

};

#endif // FRIENDCHATITEM_H
