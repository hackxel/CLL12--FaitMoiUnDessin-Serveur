#include "tcpserveur.h"
#include "thclient.h"

TcpServeur::TcpServeur(QObject *parent) :
    QTcpServer(parent)
{
}
void TcpServeur::incomingConnection(int socketDescriptor)
{
    ThClient *Client = new ThClient(socketDescriptor);
    connect(this,SIGNAL(siCommClient(QByteArray)),Client,SLOT(slCommServ(QByteArray)));
    //Client.start();
}
void TcpServeur::slNouvClient(QByteArray InfoClient)
{
    emit(siCommClient(InfoClient));
}
