#include "../header/finalpage.h"
#include "ui_finalpage.h"

FinalPage::FinalPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FinalPage)
{
    ui->setupUi(this);
    QPixmap pix(":/img/goidazvon-logo.png");
    int w = ui->Logo->width();
    int h = ui->Logo->height();

    ui->Logo->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

FinalPage::~FinalPage()
{
    delete ui;
}

void FinalPage::on_BackButton_clicked() {
    emit S_ChangeForm(0);
}
