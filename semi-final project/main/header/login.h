#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QTimer>

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "../misc/httplib.h"
#include "../misc/hasher.h"


namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

signals:
    void S_ChangeForm(int formId);
    void S_ShowLoadingScreen(QWidget* caller);
    void S_HideLoadingScreen(QWidget* caller);
    void S_GotoFinalPage(QWidget* caller, std::string infoMessage);
    void S_Infobar(QWidget* caller, std::string infoMessage, bool isFailure);
    void S_ShowRecoveryInfoBar(QWidget* caller, std::string infoMessage);

private slots:
    void ChangeFormToForgot();

    void ChangeFormToRegister();

    void on_LoginButton_clicked();

    int sendRequest(std::string username, std::string password);

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
