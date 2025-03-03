#include "../header/mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    login = new Login(this);

    layout = new QStackedLayout;
    layout->addWidget(login);

    layout->setCurrentWidget(login);
    loadScreen = new LoadingScreen(this);
    loadScreen->hide();
}

MainWindow::~MainWindow() {
    delete layout;
    delete login;
    delete loadScreen;
}
