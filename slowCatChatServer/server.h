#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QMessageBox>
#include "operatedatabase.h"
#include "tcpserver.h"
namespace Ui {
class server;
}

class server : public QWidget
{
    Q_OBJECT

public:
    explicit server(QWidget *parent = nullptr);
    ~server();

private:
    Ui::server *ui;

};

#endif // SERVER_H
