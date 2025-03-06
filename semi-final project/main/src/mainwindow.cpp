#include "../header/mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    login = new Login(this);
    registerr = new Registerr(this);

    layout = new QStackedLayout;
    layout->addWidget(login);
    layout->addWidget(registerr);
    layout->setCurrentWidget(login);

    loadScreen = new LoadingScreen(this);
    registerr->hide();
    loadScreen->hide();

    connect(login, &Login::S_ChangeForm, this, &MainWindow::ChangeForm);
    connect(registerr, &Registerr::S_ChangeForm, this, &MainWindow::ChangeForm);

    connect(login, &Login::S_HideLoadingScreen, this, &MainWindow::hideLoadScreen);
    connect(login, &Login::S_ShowLoadingScreen, this, &MainWindow::showLoadScreen);
}

MainWindow::~MainWindow() {
    delete layout;
    delete login;
    delete loadScreen;
}

void MainWindow::ChangeForm(int formId) {
    switch(formId) {
        // Login page
        case 0: {
            layout->setCurrentWidget(login);
            registerr->hide();
            login->show();
            break;
        // Register page
        } case 1: {
            layout->setCurrentWidget(registerr);
            registerr->show();
            login->hide();
            break;
        // Recovery page
        } case 2: {
            qDebug() << "Signal to recovery page\n";
            break;
        // Final page
        } case 3: {
            qDebug() << "Signal to final page\n";
            break;
        }
    }
    reInitializeLoadingScreen();
}

void MainWindow::reInitializeLoadingScreen() {
    delete loadScreen;
    loadScreen = new LoadingScreen(this);
    loadScreen->hide();
}

void MainWindow::showLoadScreen(QWidget* caller) {
    loadScreen->show();
    caller->setEnabled(false);
}

void MainWindow::hideLoadScreen(QWidget* caller) {
    loadScreen->hide();
    caller->setEnabled(true);
    reInitializeLoadingScreen();
}
