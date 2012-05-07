#ifndef DESSINSERVEUR_H
#define DESSINSERVEUR_H
#include "tcpserveur.h"
#include <QMainWindow>

namespace Ui {
class DessinServeur;
}

class DessinServeur : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit DessinServeur(QWidget *parent = 0);
    ~DessinServeur();

    bool m_MaitreJeu;
private slots:
    void on_btnStartServ_clicked();
signals:
    //Signal client
    void siNouvClient(bool);

private:
    TcpServeur *m_ServeurDeDessin;
    Ui::DessinServeur *ui;
};

#endif // DESSINSERVEUR_H
