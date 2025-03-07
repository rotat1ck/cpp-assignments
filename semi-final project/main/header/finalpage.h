#ifndef FINALPAGE_H
#define FINALPAGE_H

#include <QWidget>

namespace Ui {
class FinalPage;
}

class FinalPage : public QWidget
{
    Q_OBJECT

public:
    explicit FinalPage(QWidget *parent = nullptr);
    ~FinalPage();

signals:
    void S_ChangeForm(int formId);
private slots:
    void on_BackButton_clicked();

private:
    Ui::FinalPage *ui;
};

#endif // FINALPAGE_H
