#ifndef THCLIENT_H
#define THCLIENT_H

#include <QThread>
#include <QTcpSocket>
class ThClient : public QThread
{
    Q_OBJECT
public:
    explicit ThClient(QObject *parent = 0);
    ThClient(int socketDescriptor);
    QByteArray m_Info;
    int m_Socket;
    QTcpSocket socket;
    void run();

signals:
    
public slots:
    void slTransmiPoint(QByteArray);
    void slTestClient(QByteArray);
    //void slEndGame();
private:
    QByteArray m_Point;
    bool m_Connection;
};

#endif // THCLIENT_H
