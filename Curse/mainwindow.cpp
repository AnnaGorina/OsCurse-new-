#include "mainwindow.h"
#include "ui_mainwindow.h"

#define WidthOfDesk   600
#define HeightOfDesk 400

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //установить размер окна
    setFixedSize(QSize(WidthOfDesk, HeightOfDesk));

    ui->Desk->setFixedSize(QSize(WidthOfDesk, HeightOfDesk));

    ui->Desk->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff);
    ui->Desk->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff);

    image.load(":/image/image.jpeg");
    image = image.scaled(ui->Desk->geometry().width(), ui->Desk->geometry().height());
    Scena.addPixmap(image);

    //отобразить сцену
    ui->Desk->setScene(&Scena);
    ui->Desk->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Connection_clicked()
{
    //Получаем IP адрес хоста, к которому подключаемся
       QString IPaddress = ui->IPadress->text();

        if(IPaddress == NULL)
        {
            qDebug() << "No string";
        }

        QByteArray tmp = IPaddress.toLatin1();
        const char* IP = tmp.data();

        ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  //Создаём сокет для общения с сервером.

        if(ClientSocket < 0)
        {
            qDebug() << "Error with socket()";
        }

        //информация о сервере
        struct sockaddr_in s_addr;

        s_addr.sin_family = AF_INET;
        s_addr.sin_port = htons(2048);
        inet_pton(AF_INET, IP, &(s_addr.sin_addr));
        
        int16_t StateOfClient;

        //подключаемся к серверу
        if(::connect(ClientSocket, (struct sockaddr*) (&s_addr), sizeof(s_addr)) != -1)
        {
      //      connect(MyTimer, &QTimer::timeout, this, &MainWindow::ReadFromServer);
    //        fcntl(ClientSocket, F_SETFL, O_NONBLOCK);

        //    MyTimer->start(); //Запускаем таймер.
        }

        else
        {
      //      QMessageBox::information(this, "Ошибка", "Введён неправильный адрес или сервер не запущен");
        }
        
        //recv(ClientSocket, StateOfClient, sizeof(int16_t), MSG_NOSIGNAL);
        
        
}

/*void MainWindow::ReadFromServer()
{
    int16_t buff;
    recv(ClientSocket, buff, sizeof(int16_t), MSG_NOSIGNAL);
}*/
