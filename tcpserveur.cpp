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
        connect(Maitre,SIGNAL(siNouveauPoint(QByteArray)),this,SLOT(slNouvPoint(QByteArray)));
        connect(Maitre,SIGNAL(sitest(QByteArray)),this,SLOT(sltest(QByteArray)));   //signal nouveau point
        //connect(Maitre,SIGNAL(siEndGame()),this,SLOT(slEndGame()));
        Maitre->start();
        m_cpt++;
    }
    else
    {
        ThClient *Client = new ThClient(socketDescriptor);
        connect(this,SIGNAL(siTransmiPoint(QByteArray)),Client,SLOT(slTransmiPoint(QByteArray)));
        //connect(this,SIGNAL(siEndGame()),Client,SLOT(slEndGame()));
        connect(this,SIGNAL(sitestpoint(QByteArray)),Client,SLOT(slTestClient(QByteArray)));    //connect signal transmi nouveau point à un client
        Client->start();
    }
}

void TcpServeur::slNouvPoint(QByteArray Point)
{
    m_cpt++;
    emit(siTransmiPoint(Point));    //transmettre aux clients le nouveau point
}
/*void TcpServeur::slEndGame()
{
    emit(siEndGame());
}*/
void TcpServeur::sltest(QByteArray Image)
{
    QByteArray Im = Image;
    emit(sitestpoint(Im));
    Im.clear();
}
