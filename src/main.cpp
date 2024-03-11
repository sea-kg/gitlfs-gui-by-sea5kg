#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QDir>

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    // init work directory
    QDir dir(QDir::homePath());
    {
        if (!dir.exists(".GitLfsGuiBySea5kg")) {
            if (dir.mkdir(".GitLfsGuiBySea5kg")) {
                dir.cd(".GitLfsGuiBySea5kg");
                // TODO windows/linux
                std::cout << "created work directory ~/.GitLfsGuiBySea5kg\n";
            } else {
                std::cout << "could not create ~/.GitLfsGuiBySea5kg\n";
                return -1;
            }
        } else {
            dir.cd(".GitLfsGuiBySea5kg");
        }
    }
    std::cout << "Work directory: " << dir.canonicalPath().toStdString() <<" \n";

    MainWindow w(dir.canonicalPath());
    w.show();
    return app.exec();
}
