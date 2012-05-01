#ifndef DESSINSERVEUR_H
#define DESSINSERVEUR_H

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
signals:
    void siNouvClient(QByteArray);

private:
    Ui::DessinServeur *ui;
};

#endif // DESSINSERVEUR_H
