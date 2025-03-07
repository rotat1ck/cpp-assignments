#ifndef INFOBAR_H
#define INFOBAR_H

#include <QWidget>

namespace Ui {
class InfoBar;
}

class InfoBar : public QWidget
{
    Q_OBJECT

public:
    explicit InfoBar(QWidget *parent = nullptr, std::string infoMessage = "");
    ~InfoBar();

public slots:
    void displayMessage(std::string message, bool isFailure);

private:
    Ui::InfoBar *ui;
    QString successInfoBarStyleSheet =
        "background: #CCDAB9;"
        "border-radius: 10px;"
        "font-family: 'gg sans semibold';"
        "font-size: 12px;"
        "line-height: 19px;"
        "color: #323232;"
    ;
    QString failureInfoBarStyleSheet =
        "background: #FFD9D9;"
        "border-radius: 10px;"
        "font-family: 'gg sans semibold';"
        "font-size: 12px;"
        "line-height: 19px;"
        "color: #323232;"
    ;
};

#endif // INFOBAR_H
