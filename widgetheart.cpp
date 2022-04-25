#include "widgetheart.h"
#include "ui_widgetheart.h"
#include "duscene.h"
#include<QGraphicsView>

Widgetheart::Widgetheart(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widgetheart)
{
    ui->setupUi(this);
    mScene = new Duscene(this);
    ui->graphicsView->setScene(mScene);

}

Widgetheart::~Widgetheart()
{
    delete ui;
}

