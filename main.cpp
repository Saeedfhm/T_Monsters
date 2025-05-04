#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}


//std::vector<std::vector<QString>> parseGridFile(const QString& filePath) {
//    std::vector<std::vector<QString>> grid;
//    QFile file(filePath);

////    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
////        QDebug << "Cannot open file:" << filePath;
////        return grid;
////    }


