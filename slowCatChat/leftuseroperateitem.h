#ifndef LEFTUSEROPERATEITEM_H
#define LEFTUSEROPERATEITEM_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QMouseEvent>

class leftUserOperateItem : public QWidget //用户左侧工具条
{
    Q_OBJECT
public:
    explicit leftUserOperateItem(QWidget *parent = nullptr);
    ~leftUserOperateItem() override;

public:
    void setToolIcon(QPixmap);//给左侧项设置图标
signals:
/*
     * @mouseLeftClicked() : 发送鼠标点击信号
     * @mouseMoveToToolIcon() : 发送鼠标移入图标信号
     * @mouseLeaveToToolIcon() : 发送鼠标离开图标项信号
*/
    void mouseLeftClicked();//鼠标进行图表项且点击左键
    void mouseMoveToToolIcon();//鼠标移入图标上
    void mouseLeaveToToolIcon();//鼠标离开图标
protected:
    void mousePressEvent(QMouseEvent*) override;//鼠标点击事件
    void mouseMoveEvent(QMouseEvent*) override;//鼠标移入事件
    void leaveEvent(QEvent*) override;//鼠标离开事件
private:
    QLabel* m_toolIcon = nullptr;
    QVBoxLayout* m_hBoxLayout = nullptr;
};

#endif // LEFTUSEROPERATEITEM_H
