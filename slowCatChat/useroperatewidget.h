#ifndef USEROPERATEWIDGET_H
#define USEROPERATEWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include "leftuseroperateitem.h"
class userOperateWidget : public QWidget
{
    Q_OBJECT
public:
    explicit userOperateWidget(QWidget *parent = nullptr);

signals:

public slots:

private:
    leftUserOperateItem* m_userHeadPixmap = nullptr;
    QVBoxLayout* m_hBoxLayout = nullptr;
};

#endif // USEROPERATEWIDGET_H
