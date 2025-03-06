#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedLayout>
#include <QWidget>

#include "login.h"
#include "loadingscreen.h"
#include "registerr.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void ChangeForm(int formId);
    void reInitializeLoadingScreen();
    void showLoadScreen(QWidget* caller);
    void hideLoadScreen(QWidget* caller);

private:
    QStackedLayout* layout;
    Login* login;
    Registerr* registerr; // оказывается "register" зарезервированное слово
    LoadingScreen* loadScreen;
};
#endif // MAINWINDOW_H
