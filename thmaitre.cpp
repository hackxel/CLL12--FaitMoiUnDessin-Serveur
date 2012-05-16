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
    socketM.write(baReception); //Envoi du caractère # au maitre
    socketM.waitForReadyRead();
    QByteArray Transmission;
    do
    {
        connection = socketM.waitForReadyRead();
        if(connection)
        {

            baReception = socketM.read(socketM.bytesAvailable());
            while(baReception.size() >= 4)
            {
                Transmission = baReception.left(4); //obtenir les coordonnées x,y
                emit(sitest(Transmission)); //transmettre le point
                baReception.remove(0,4); //enlever le point de la liste
            }
            //baReception.clear();
            //emit(siNouveauPoint(baReception));
        }
        //maitre à quitté la partie
        else
        {
           //emit(siEndGame());
        }
        //baReception.clear();
    }while(connection);

    //socketM.disconnect();
}
