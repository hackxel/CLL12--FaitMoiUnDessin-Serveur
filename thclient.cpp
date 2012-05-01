#include "thclient.h"

ThClient::ThClient(QObject *parent) :
    QThread(parent)
{
}
ThClient::ThClient(int socketDescriptor)
{
    m_Socket = socketDescriptor;
}
void ThClient::slCommServ(QByteArray InfoClient)
{
    m_Info = InfoClient;
}
