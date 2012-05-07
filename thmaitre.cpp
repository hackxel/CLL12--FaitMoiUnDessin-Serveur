#include "thmaitre.h"
#include "tcpserveur.h"

thMaitre::thMaitre(QObject *parent) :
    QThread(parent)
{

}
thMaitre::thMaitre(int socketDescriptor)
{
    m_Socket = socketDescriptor;
}

void thMaitre::run()
{
    QByteArray baReception;

    QTcpSocket socketM;
    socketM.setSocketDescriptor(m_Socket);
    socketM.waitForConnected();
    baReception.append("#");
    //Envoi du caractère # au maitre
    socketM.write(baReception);
    socketM.waitForReadyRead();
    //socketM.disconnect();
}
void thMaitre::slMaitre()
{

}
