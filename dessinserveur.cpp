#include "dessinserveur.h"
#include "ui_dessinserveur.h"

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
