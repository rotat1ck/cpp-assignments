#include "../header/login.h"
#include "ui_login.h"
#include "../misc/clickQLabel.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    QPixmap pix(":/img/goidazvon-logo.png");
    int w = ui->Logo->width();
    int h = ui->Logo->height();

    ui->Logo->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

    ClickQLabel* ForgotPasswordLabel = new ClickQLabel(ui->LoginWidget);
    ForgotPasswordLabel->setText("Forgot password?");
    ForgotPasswordLabel->setGeometry(10, 200, 110, 20);

    connect(ForgotPasswordLabel, &ClickQLabel::clicked, this, &Login::ChangeFormToForgot);
}

Login::~Login() {
    delete ui;
}

void Login::ChangeFormToForgot() {
    emit S_ChangeForm(1);
}

void Login::on_LoginButton_clicked() {
    emit S_ChangeForm(2);
}

