#include "thclient.h"
#include "tcpserveur.h"

ThClient::ThClient(QObject *parent) :
    QThread(parent)
{
}
ThClient::ThClient(int socketDescriptor)
{
    m_Socket = socketDescriptor;
}
void ThClient::run()
{
    QByteArray baReception;

    QTcpSocket socket;
    socket.setSocketDescriptor(m_Socket);
    socket.waitForConnected();
    baReception.append("C");
    //Envoi du caractère C au maitre
    socket.write(baReception);
    socket.waitForReadyRead();
}

void ThClient::slCommServ()
{

}
