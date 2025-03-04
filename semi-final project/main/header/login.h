#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>


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

private slots:
    void ChangeFormToForgot();

    void on_LoginButton_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
