#ifndef REGISTERR_H
#define REGISTERR_H

#include <QWidget>
#include <QTimer>

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "../misc/httplib.h"
#include "../misc/hasher.h"

namespace Ui {
class Registerr;
}

class Registerr : public QWidget
{
    Q_OBJECT

public:
    explicit Registerr(QWidget *parent = nullptr);
    ~Registerr();

signals:
    void S_ChangeForm(int formId);

    void S_ShowLoadingScreen(QWidget* caller);

    void S_HideLoadingScreen(QWidget* caller);

private slots:
    void on_RegisterButton_clicked();

    void on_BackButton_clicked();

    void on_EmailInput_textEdited(const QString &arg1);

    void on_UsernameInput_textEdited(const QString &arg1);

    void on_PasswordInput_textEdited(const QString &arg1);

    void on_RepeatPasswordInput_textEdited(const QString &arg1);

    void checkAllParams();

    int sendRequest(std::string username, std::string password, std::string email);

private:
    Ui::Registerr *ui;
    QString email;
    QString username;
    QString pass1;
    QString pass2;
    QString enabledRegisterButtonStyleSheet =
        "background: rgba(72, 127, 198, 1);"
        "border-radius: 10px;"
        "font-family: 'gg sans semibold';"
        "font-size: 18px;"
        "line-height: 19px;"
        "color: rgba(255, 255, 255, 1);"
    ;
    QString disabledRegisterButtonStyleSheet =
        "background: rgba(72, 127, 198, 180);"
        "border-radius: 10px;"
        "font-family: 'gg sans semibold';"
        "font-size: 18px;"
        "line-height: 19px;"
        "color: rgba(255, 255, 255, 180);"
    ;
};

#endif // REGISTERR_H
