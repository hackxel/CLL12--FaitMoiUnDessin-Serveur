#ifndef THCLIENT_H
#define THCLIENT_H

#include <QThread>

class ThClient : public QThread
{
    Q_OBJECT
public:
    explicit ThClient(QObject *parent = 0);
    ThClient(int socketDescriptor);
    QByteArray m_Info;
    int m_Socket;
    void run();
signals:
    
public slots:
    void slCommServ();
    
};

#endif // THCLIENT_H
