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
    m_Connection = true;
    QTcpSocket socket;
    socket.setSocketDescriptor(m_Socket);
    socket.waitForConnected();
    baReception.append("C");
    //Envoi du caractère C au maitre
    socket.write(baReception);
    socket.waitForReadyRead();
    do
    {
      socket.write(m_Point);
      socket.waitForBytesWritten();
    }while(m_Connection);
}
void ThClient::slTransmiPoint(QByteArray Point)
{
    m_Point = Point;
}
void ThClient::slEndGame()
{
    m_Connection = false;
}
