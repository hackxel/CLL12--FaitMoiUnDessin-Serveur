#ifndef THMAITRE_H
#define THMAITRE_H

#include <QThread>

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

public slots:
    void slMaitre();
    
};

#endif // THMAITRE_H
