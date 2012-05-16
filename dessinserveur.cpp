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
    bool test = true;
    m_ServeurDeDessin = new TcpServeur();
    //COnnection des signaux
    //connect(this,SIGNAL(siNouvClient(bool)),m_ServeurDeDessin,SLOT(slNouvClient(bool)));
    //connect(m_ServeurDeDessin,SIGNAL(newConnection()),this,SLOT(slNouvConnection()));
   m_ServeurDeDessin->listen(QHostAddress::Any,61500);
}
