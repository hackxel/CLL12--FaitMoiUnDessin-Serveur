#include "tcpserveur.h"
#include "thclient.h"
#include "thmaitre.h"

TcpServeur::TcpServeur(QObject *parent) :
    QTcpServer(parent)
{
}
void TcpServeur::incomingConnection(int socketDescriptor)
{
    //thread maitre
    if(m_Etat == false)
    {
        thMaitre *Maitre = new thMaitre(socketDescriptor);
        connect(this,SIGNAL(siCommMaitre()),Maitre, SLOT(slMaitre()));
        Maitre->start();
    }
    else
    {
        ThClient *Client = new ThClient(socketDescriptor);
        connect(this,SIGNAL(siCommClient(bool)),Client,SLOT(slCommServ(QByteArray)));
        Client->start();
    }





}
void TcpServeur::slNouvClient(bool Etat)
{
    //émettre signal de client
    m_Etat = Etat;
    if(m_Etat)
    {
        emit(siCommMaitre());
    }
    else
    {
        emit(siCommClient());
    }
}
