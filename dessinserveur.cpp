#include "dessinserveur.h"
#include "ui_dessinserveur.h"
#include "tcpserveur.h"

DessinServeur::DessinServeur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DessinServeur)
{
    ui->setupUi(this);

}

DessinServeur::~DessinServeur()
{
    delete ui;
}

void DessinServeur::on_btnStartServ_clicked()
{
    TcpServeur *ServeurDeDessin = new TcpServeur();
    connect(this,SIGNAL(siNouvClient(QByteArray)),ServeurDeDessin,SLOT(slNouvClient(QByteArray)));
    ServeurDeDessin->listen(QHostAddress::Any,61500);
    QByteArray Image;
    emit(siNouvClient(Image));
}
