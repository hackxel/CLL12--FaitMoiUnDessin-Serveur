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


private slots:
    void on_btnStartServ_clicked();
    void slNouvConnection();
signals:
    //Signal client
    //void siNouvClient();

private:
    TcpServeur *m_ServeurDeDessin;
    Ui::DessinServeur *ui;
    bool m_MaitreJeu;
};

#endif // DESSINSERVEUR_H
