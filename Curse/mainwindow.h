#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include <QDebug>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Connection_clicked();
    void ReadFromServer();

private:
    Ui::MainWindow *ui;
    QGraphicsScene Scena;
    QPixmap image;
    int ClientSocket;
    
};

struct message
{ 
    int16_t type = static_cast<int16_t>(state_for_client);
    int16_t state;
};

enum state{WaitConnectPlayer, Win, Lose, Combat};

#endif // MAINWINDOW_H
