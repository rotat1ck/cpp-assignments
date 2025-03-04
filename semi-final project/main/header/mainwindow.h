#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedLayout>
#include <QWidget>

#include "login.h"
#include "loadingscreen.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void ChangeForm(int formId);

private:
    QStackedLayout* layout;
    Login* login;
    LoadingScreen* loadScreen;
};
#endif // MAINWINDOW_H
