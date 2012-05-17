#include "thclient.h"
#include "tcpserveur.h"

ThClient::ThClient(QObject *parent) :
    QThread(parent)
{
}
ThClient::ThClient(int socketDescriptor, QByteArray mot)
{
    m_Socket = socketDescriptor;
    m_Mot.append(mot);
}
void ThClient::run()
{
    QByteArray baReception;
    m_Connection = true;
    //initialisation du socket
    socket.setSocketDescriptor(m_Socket);
    //attente de connection
    socket.waitForConnected();
    //Envoi du caractère C au client
    baReception.append("C");
    socket.write(baReception);
    socket.waitForReadyRead();
    int i = 0;
    do
    {
          //vérification si le client a fait un essais
          if(socket.bytesAvailable() > 0)
          {
              baReception = socket.read(socket.bytesAvailable());
              emit(siEssais(baReception));
              /*while(baReception[i] == m_Mot[i] )
              {
                  i++;
              }
              if(i == m_Mot.length())
              {
                  bool chat =true;
              }*/
          }
    }while(m_Connection);
    socket.write("F");

}
/*void ThClient::slEndGame()
{
    m_Connection = false;
}*/
void ThClient::slTestClient(QByteArray Point)
{
    m_Point = Point;
    socket.write(m_Point);
    socket.waitForBytesWritten();
    m_Point.clear();
}
void ThClient::slMot(QByteArray Mot)
{
    m_Mot.append(Mot);

}
