#include "../header/mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    login = new Login(this);

    layout = new QStackedLayout;
    layout->addWidget(login);

    layout->setCurrentWidget(login);
    loadScreen = new LoadingScreen(this);
    loadScreen->hide();

    connect(login, &Login::S_ChangeForm, this, &MainWindow::ChangeForm);
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
    }
}
