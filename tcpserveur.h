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
    //émettre à la fin de partie
    //void siEndGame();
    void sitestpoint(QByteArray);
    //émettre au client pour comparer les essais
    void siMot(QByteArray);
public slots:
    //void slNouvClient();
    void slNouvPoint(QByteArray);
    //émettre quand le maitre se déconnecte
    //void slEndGame();
    void sltest(QByteArray);
    void slTranMot(QByteArray);
    //slot pour tester l'essais
    void slEssais(QByteArray);
private:
    QByteArray m_MotATrouver;
};

#endif // TCPSERVEUR_H
