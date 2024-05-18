#ifndef LEFTUSEROPERATEITEM_H
#define LEFTUSEROPERATEITEM_H
//用户左侧工具条
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
class leftUserOperateItem : public QWidget
{
    Q_OBJECT
public:
    explicit leftUserOperateItem(QWidget *parent = nullptr);
    ~leftUserOperateItem() override;

public:
    void setToolIcon(QPixmap);//给左侧项设置图标

signals:
    void mouseLeftClicked();

protected:
    void mousePressEvent(QMouseEvent*) override;//鼠标点击事件
    void mouseMoveEvent(QMouseEvent*) override;//鼠标移入事件
    void leaveEvent(QEvent*) override; //鼠标离开事件
private:
    QLabel* m_toolIcon = nullptr;
    QVBoxLayout* m_hBoxLayout = nullptr;
};

#endif // LEFTUSEROPERATEITEM_H
