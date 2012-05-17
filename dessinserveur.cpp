 /* *** Fait moi un dessin *** */
/* *** Projet Final Linux *** */
/* *** Jérémie Tremblay et Axel Gauthier-Bélanger *** */
/* *** Mai 2012 *** */
/* *** Cégep Lévis-Lauzon *** */

#include "dessinserveur.h"
#include "ui_dessinserveur.h"

#include "QTcpSocket"

DessinServeur::DessinServeur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DessinServeur)
{
    ui->setupUi(this);
    m_MaitreJeu = false;

    ui->lblBackground->setPixmap(QPixmap("christalis.png"));
   // lbl->setPixmap(QPixmap("christalis.png"));
}

DessinServeur::~DessinServeur()
{
    delete ui;
}

void DessinServeur::on_btnStartServ_clicked()
{
    m_ServeurDeDessin = new TcpServeur();
   m_ServeurDeDessin->listen(QHostAddress::Any,61500);
}
