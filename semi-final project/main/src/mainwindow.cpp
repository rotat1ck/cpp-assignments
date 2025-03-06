#include "../header/mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    login = new Login(this);

    layout = new QStackedLayout;
    layout->addWidget(login);
    layout->setCurrentWidget(login);

    loadScreen = new LoadingScreen(this);
    loadScreen->hide();

    connect(login, &Login::S_ChangeForm, this, &MainWindow::ChangeForm);

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
            qDebug() << "Signal to login page\n";
            break;
        // Register page
        } case 1: {
            qDebug() << "Signal to register page\n";
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
    reInitializeLoadingScreen();
    }
}

void MainWindow::reInitializeLoadingScreen() {
    delete loadScreen;
    loadScreen = new LoadingScreen(this);
    loadScreen->hide();
}

// TODO: add a blur effect to screen when called
void MainWindow::showLoadScreen(QWidget* caller) {
    loadScreen->show();

}

void MainWindow::hideLoadScreen(QWidget* caller) {
    loadScreen->hide();

}
