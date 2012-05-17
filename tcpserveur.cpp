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
        //connecxion du signal et du slot pour transmettre un nouveau point
        connect(Maitre,SIGNAL(sitest(QByteArray)),this,SLOT(sltest(QByteArray)));
        //connecxion du signal et du slot pour transmettre le mot aux client
        connect(Maitre,SIGNAL(siTranMot(QByteArray)),this,SLOT(slTranMot(QByteArray)));
        //connect(Maitre,SIGNAL(siEndGame()),this,SLOT(slEndGame()));
        Maitre->start();
        m_cpt++;
    }
    else
    {
        ThClient *Client = new ThClient(socketDescriptor,m_MotATrouver);
        //connect(this,SIGNAL(siEndGame()),Client,SLOT(slEndGame()));
        //connecxion du signal et du slot permettant de transmettre les points aux clients
        connect(this,SIGNAL(sitestpoint(QByteArray)),Client,SLOT(slTestClient(QByteArray)));    //connect signal transmi nouveau point à un client
        //connecxion du signal et du slot permettant de transmettre le mot aux clients
        connect(this,SIGNAL(siMot(QByteArray)),Client,SLOT(slMot(QByteArray)));
        connect(Client,SIGNAL(siEssais(QByteArray)),this,SLOT(slEssais(QByteArray)));
        Client->start();
        //emit(siMot(m_MotATrouver));     //transmettre le mot a chaque nouveau client

    }
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
void TcpServeur::slTranMot(QByteArray Mot)
{
    m_MotATrouver.clear();
    m_MotATrouver.append(Mot);
}
void TcpServeur::slEssais(QByteArray MotEssais)
{
    if( MotEssais.toBase64() == m_MotATrouver.toBase64())
    {
        bool ilu;
        ilu = true;
    }
}
