#include "../header/Registerr.h"
#include "ui_registerr.h"

Registerr::Registerr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registerr)
{
    ui->setupUi(this);

    QPixmap pix(":/img/goidazvon-logo.png");
    int w = ui->Logo->width();
    int h = ui->Logo->height();

    ui->Logo->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    ui->PasswordInput->setEchoMode(QLineEdit::Password);
    ui->RepeatPasswordInput->setEchoMode(QLineEdit::Password);
    ui->PasswordCheckLabel->hide();
    ui->RegisterButton->setEnabled(false);
    ui->RegisterButton->setStyleSheet(disabledRegisterButtonStyleSheet);
}

Registerr::~Registerr() {
    delete ui;
}

void Registerr::on_BackButton_clicked() {
    emit S_ChangeForm(0);
}


void Registerr::on_EmailInput_textEdited(const QString &arg1) {
    checkAllParams();
}

void Registerr::on_UsernameInput_textEdited(const QString &arg1) {
    checkAllParams();
}

void Registerr::on_PasswordInput_textEdited(const QString &arg1) {
    checkAllParams();
}

void Registerr::on_RepeatPasswordInput_textEdited(const QString &arg1) {
    checkAllParams();
}

void Registerr::checkAllParams() {
    email = ui->EmailInput->text();
    username = ui->UsernameInput->text();
    pass1 = ui->PasswordInput->text();
    pass2 = ui->RepeatPasswordInput->text();

    if (pass1 != pass2) {
        ui->PasswordCheckLabel->show();
    } else {
        ui->PasswordCheckLabel->hide();
    }

    if (pass1 == pass2 && email != "" && username != "" && pass1 != "" && pass2 != "") {
        ui->RegisterButton->setEnabled(true);
        ui->RegisterButton->setStyleSheet(enabledRegisterButtonStyleSheet);
    } else {
        ui->RegisterButton->setEnabled(false);
        ui->RegisterButton->setStyleSheet(disabledRegisterButtonStyleSheet);
    }
}

void Registerr::on_RegisterButton_clicked() {
    emit S_ShowLoadingScreen(this);
    QTimer::singleShot(400, this, [this]() {
        std::string email = "email=" + ui->EmailInput->text().toUtf8().toStdString();
        std::string username = "username=" + ui->UsernameInput->text().toUtf8().toStdString();
        std::string passHash = toHash::hash(ui->PasswordInput->text().toUtf8().toStdString());
        std::string password = "pass=" + passHash;

        int res = sendRequest(username, password, email);
        qDebug() << res;
        emit S_HideLoadingScreen(this);
    });
}

int Registerr::sendRequest(std::string username, std::string password, std::string email) {
    try {
        httplib::Client cl("https://77.37.246.6:7777");
        cl.enable_server_certificate_verification(false);
        std::string endpoint = "/register?" + username + "&" + password + "&" + email;

        auto res = cl.Post(endpoint);
        return res->status;
    } catch (const std::exception& ex) {
        qDebug() << "Exception: " << ex.what();
        return -1;
    }
}
