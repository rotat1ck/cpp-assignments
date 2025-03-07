#include "../header/infobar.h"
#include "ui_infobar.h"

InfoBar::InfoBar(QWidget *parent, std::string infoMessage) :
    QWidget(parent),
    ui(new Ui::InfoBar)
{
    ui->setupUi(this);
}

InfoBar::~InfoBar()
{
    delete ui;
}

void InfoBar::displayMessage(std::string message, bool isFailure) {
    QString infoMessage = QString::fromStdString(message);
    ui->InfoBarLabel->setText(QString(infoMessage));
    if (isFailure) {
        ui->InfoBarLabel->setStyleSheet(failureInfoBarStyleSheet);
    } else {
        ui->InfoBarLabel->setStyleSheet(successInfoBarStyleSheet);
    }
}
