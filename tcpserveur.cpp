#include "tcpserveur.h"
#include "thclient.h"
#include "thmaitre.h"

TcpServeur::TcpServeur(QObject *parent) :
    QTcpServer(parent)
{
    m_cpt = 0;
    m_Etat = false;
}
void TcpServeur::incomingConnection(int socketDescriptor)
{
  //thread maitre
    if(m_Etat == false)
    {
        m_Etat = true;
        thMaitre *Maitre = new thMaitre(socketDescriptor);
        connect(Maitre,SIGNAL(siNouveauPoint(QByteArray)),SLOT(slNouvPoint(QByteArray)));
        connect(Maitre,SIGNAL(siEndGame()),SLOT(slEndGame()));
        Maitre->start();
        m_cpt++;
    }
    else
    {
        ThClient *Client = new ThClient(socketDescriptor);
        //connect(this,SIGNAL(siCommClient()),Client,SLOT(slCommServ()));
        connect(this,SIGNAL(siTransmiPoint(QByteArray)),Client,SLOT(slTransmiPoint(QByteArray)));
        connect(this,SIGNAL(siEndGame()),Client,SLOT(slEndGame()));
        Client->start();
    }
}
/*void TcpServeur::slNouvClient()
{
    //émettre signal de client
    if (m_cpt == 2)
        int i = 0;
    if(m_Etat == false)
    {
        //emit(siCommMaitre());
    }
    else
    {
        //emit(siCommClient());
    }
}*/
void TcpServeur::slNouvPoint(QByteArray Point)
{
    //transmettre aux clients le nouveau point
    emit(siTransmiPoint(Point));
}
void TcpServeur::slEndGame()
{
    emit(siEndGame());
}
