#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedLayout>
#include <QWidget>

#include "login.h"
#include "loadingscreen.h"
#include "registerr.h"
#include "infobar.h"
#include "finalpage.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void ChangeForm(int formId);
    void reInitializePopUps();
    void showLoadScreen(QWidget* caller);
    void hideLoadScreen(QWidget* caller);
    void InfoBarDisplay(QWidget *caller, std::string infoMessage, bool isFailure);
    void returnFromRegister(QWidget *caller, std::string infoMessage);
    void gotoFinalPage(QWidget *caller, std::string infoMessage);
    void showRecoveryInfoBar(QWidget *caller, std::string infoMessage);

private:
    QStackedLayout* layout;
    Login* login;
    Registerr* registerr; // оказывается "register" зарезервированное слово
    LoadingScreen* loadScreen;
    InfoBar* infobar;
    FinalPage* finalpage;
};
#endif // MAINWINDOW_H
