#ifndef THCLIENT_H
#define THCLIENT_H

#include <QThread>
#include <QTcpSocket>
class ThClient : public QThread
{
    Q_OBJECT
public:
    explicit ThClient(QObject *parent = 0);
    ThClient(int socketDescriptor, QByteArray mot);
    QByteArray m_Info;
    int m_Socket;
    QTcpSocket socket;
    void run();

signals:
    void siEssais(QByteArray);
public slots:
    void slTransmiPoint(QByteArray);
    void slTestClient(QByteArray);
    void slMot(QByteArray);
    //void slEndGame();
    bool slResolution();
private:
    QByteArray m_Point;
    bool m_Connection;
    QByteArray m_Mot;
};

#endif // THCLIENT_H
