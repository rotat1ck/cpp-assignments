#include "header/mainwindow.h"

#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFontDatabase::addApplicationFont(":/fonts/ggsans-Normal.ttf");
    QFontDatabase::addApplicationFont(":/fonts/ggsans-Semibold.ttf");

    // QStringList fontFamilies = QFontDatabase::families();
    // for (auto it : fontFamilies) {
    //     qDebug() << it << "\n";
    // }

    MainWindow w;
    w.setFixedSize(QSize(900, 650));;
    w.show();
    return a.exec();
}
