#ifndef THMAITRE_H
#define THMAITRE_H

#include <QThread>
#include <tcpserveur.h>
class thMaitre : public QThread
{
    Q_OBJECT
public:
    explicit thMaitre(QObject *parent = 0);
    thMaitre(int socketDescriptor);
    void run();
    QByteArray m_Dessin;
    int m_Socket;

signals:
    void siNouveauPoint(QByteArray);
    void siEndGame();
    void sitest(QByteArray);
public slots:
private:
    
};

#endif // THMAITRE_H
