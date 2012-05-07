#ifndef TCPSERVEUR_H
#define TCPSERVEUR_H
#include <QTcpServer>
#include <QTcpSocket>

class TcpServeur : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServeur(QObject *parent = 0);
    bool m_Etat;
protected:
    void incomingConnection(int socketDescriptor);
signals:
    void siCommClient();
    //signal a émettre à la connection du maitre
    void siCommMaitre();
public slots:
    void slNouvClient(bool);
    
};

#endif // TCPSERVEUR_H
