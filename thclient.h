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
    
signals:
    
public slots:
    void slCommServ(QByteArray);
    
};

#endif // THCLIENT_H
