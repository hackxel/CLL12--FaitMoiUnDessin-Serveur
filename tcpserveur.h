#ifndef TCPSERVEUR_H
#define TCPSERVEUR_H
#include <QTcpServer>

class TcpServeur : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServeur(QObject *parent = 0);

protected:
    void incomingConnection(int socketDescriptor);
signals:
    void siCommClient(QByteArray);
public slots:
    void slNouvClient(QByteArray);
    
};

#endif // TCPSERVEUR_H
