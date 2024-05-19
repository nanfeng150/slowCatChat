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
#include "leftuseroperateitem.h"
class userOperateWidget : public QWidget
{
    Q_OBJECT
public:
    explicit userOperateWidget(QWidget *parent = nullptr);
    ~userOperateWidget() override;

    void setToolIcon(leftUserOperateItem* item, QString pixmap_gray_path, QString pixmap_blue_path, QString toolText);

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
};

#endif // USEROPERATEWIDGET_H
