#include "thmaitre.h"
//#include "tcpserveur.h"

thMaitre::thMaitre(QObject *parent) :
    QThread(parent)
{

}
thMaitre::thMaitre(int socketDescriptor)
{
    m_Socket = socketDescriptor;
    //m_Serv = Serveur;
}

void thMaitre::run()
{
    QByteArray baReception;
    bool connection = true;
    QTcpSocket socketM;
    //connect(this,SIGNAL(siNouveauPoint(QByteArray)),this,SLOT(slNouvPoint(QByteArray)));
    socketM.setSocketDescriptor(m_Socket);
    socketM.waitForConnected();
    baReception.append("#");
    //Envoi du caractère # au maitre
    socketM.write(baReception);
    socketM.waitForReadyRead();
    do
    {
        connection = socketM.waitForReadyRead(30000);
        if(connection)
        {
            baReception = socketM.read(socketM.bytesAvailable());
            emit(siNouveauPoint(baReception));
        }
        //maitre à quitté la partie
        else
        {
            emit(siEndGame());
        }
        baReception.clear();
    }while(connection);

    //socketM.disconnect();
}
