#include "thmaitre.h"
//#include "tcpserveur.h"

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
    bool connection = true;
    QTcpSocket socketM;
    socketM.setSocketDescriptor(m_Socket);
    socketM.waitForConnected();
    baReception.append("M");
    socketM.write(baReception); //Envoi du caractère M au maitre
    socketM.waitForReadyRead();
    QByteArray Transmission;
   baReception = socketM.read(socketM.bytesAvailable());
   emit(siTranMot(baReception)); //envoyer le mot à trouver
   baReception.clear();
    do
    {
        connection = socketM.waitForReadyRead();
        if(connection)
        {
            baReception = socketM.read(socketM.bytesAvailable());
            while(baReception.size() >= 4)
            {
                //obtenir les coordonnées x,y
                Transmission = baReception.left(4);
                //transmettre le point
                emit(sitest(Transmission));
                //enlever le point de la liste
                baReception.remove(0,4);
            }
        }
    }while(connection);
}
