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
}

DessinServeur::~DessinServeur()
{
    delete ui;
}

void DessinServeur::on_btnStartServ_clicked()
{
    QByteArray Image;
    bool test;
    m_ServeurDeDessin = new TcpServeur();
    //COnnection des signaux
    connect(this,SIGNAL(siNouvClient(bool)),m_ServeurDeDessin,SLOT(slNouvClient(bool)));
    if(test = m_ServeurDeDessin->listen(QHostAddress::Any,61500))
    {
        //ServeurDeDessin->waitForNewConnection();


        if(m_MaitreJeu == false)
        {
            emit(siNouvClient(m_MaitreJeu));
            m_MaitreJeu = true;
        }
        else
            emit(siNouvClient(m_MaitreJeu));
    }
}
