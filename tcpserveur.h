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
    int m_cpt;
protected:
    void incomingConnection(int socketDescriptor);
signals:
    void siCommClient();
    //signal a émettre à la connection du maitre
    void siCommMaitre();
    //émettre à la réception d'un nouveau point
    void siTransmiPoint(QByteArray);
    //émettre à la fin de partie
    void siEndGame();
public slots:
    //void slNouvClient();
    void slNouvPoint(QByteArray);
    //émettre quand le maitre se déconnecte
    void slEndGame();
};

#endif // TCPSERVEUR_H
