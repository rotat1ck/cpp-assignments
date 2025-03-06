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

    ClickQLabel* Register = new ClickQLabel(ui->LoginWidget);
    Register->setText("Register");
    Register->setGeometry(150, 260, 110, 20);

    connect(ForgotPasswordLabel, &ClickQLabel::clicked, this, &Login::ChangeFormToForgot);
    connect(Register, &ClickQLabel::clicked, this, &Login::ChangeFormToRegister);
}

Login::~Login() {
    delete ui;
}

void Login::ChangeFormToRegister() {
    emit S_ChangeForm(1);
}

void Login::ChangeFormToForgot() {
    emit S_ChangeForm(2);
}

void Login::on_LoginButton_clicked() {
    emit S_ShowLoadingScreen(this);
    QTimer::singleShot(400, this, [this]() {
        std::string username = "username=" + ui->UsernameInput->text().toUtf8().toStdString();
        std::string password = "pass=" + ui->PasswordInput->text().toUtf8().toStdString();

        sendRequest(username, password);

        emit S_HideLoadingScreen(this);
    });
}

void Login::sendRequest(std::string username, std::string password) {
    try {
        httplib::Client cl("https://77.37.246.6:7777");
        cl.enable_server_certificate_verification(false);
        std::string endpoint = "/login?" + username + "&" + password;

        auto res = cl.Get(endpoint);
        qDebug() << "Response status: " << res->status;
    } catch (const std::exception& ex) {
        qDebug() << "Exception: " << ex.what();
    }
}
