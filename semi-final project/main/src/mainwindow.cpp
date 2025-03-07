#include "../header/mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    login = new Login(this);
    registerr = new Registerr(this);

    layout = new QStackedLayout;
    layout->addWidget(login);
    layout->addWidget(registerr);
    layout->setCurrentWidget(login);

    loadScreen = new LoadingScreen(this);
    infobar = new InfoBar(this, "");
    registerr->hide();
    loadScreen->hide();
    infobar->hide();

    connect(login, &Login::S_ChangeForm, this, &MainWindow::ChangeForm);
    connect(registerr, &Registerr::S_ChangeForm, this, &MainWindow::ChangeForm);

    connect(login, &Login::S_HideLoadingScreen, this, &MainWindow::hideLoadScreen);
    connect(login, &Login::S_ShowLoadingScreen, this, &MainWindow::showLoadScreen);
    connect(login, &Login::S_Infobar, this, &MainWindow::InfoBarDisplay);


    connect(registerr, &Registerr::S_HideLoadingScreen, this, &MainWindow::hideLoadScreen);
    connect(registerr, &Registerr::S_ShowLoadingScreen, this, &MainWindow::showLoadScreen);
    connect(registerr, &Registerr::S_Infobar, this, &MainWindow::InfoBarDisplay);
    connect(registerr, &Registerr::S_ReturnToLogin, this, &MainWindow::returnFromRegister);
}

MainWindow::~MainWindow() {
    delete layout;
    delete login;
    delete loadScreen;
    delete registerr;
    delete infobar;
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
    reInitializePopUps();
}

void MainWindow::reInitializePopUps() {
    delete loadScreen;
    delete infobar;
    loadScreen = new LoadingScreen(this);
    infobar = new InfoBar(this, "");
    loadScreen->hide();
    infobar->hide();
}

void MainWindow::showLoadScreen(QWidget* caller) {
    loadScreen->show();
    caller->setEnabled(false);
}

void MainWindow::hideLoadScreen(QWidget* caller) {
    loadScreen->hide();
    caller->setEnabled(true);
}

void MainWindow::InfoBarDisplay(QWidget* caller, std::string infoMessage, bool isFailure) {
    qDebug() << "Called";
    infobar->show();
    infobar->displayMessage(infoMessage, isFailure);
    QTimer::singleShot(3000, this, [this]() {
        infobar->hide();
    });
}

void MainWindow::returnFromRegister(QWidget *parent, std::string infoMessage) {
    ChangeForm(0);
    infobar->show();
    infobar->displayMessage(infoMessage, false);
    QTimer::singleShot(3000, this, [this]() {
        infobar->hide();
    });
}
