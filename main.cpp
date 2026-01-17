#include <QApplication>
#include <QPushButton>
#include "FileLoader.h"

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    //window setup
    QWidget window;
    window.setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    window.setWindowTitle("ProgressBar");
    window.show();

    return QApplication::exec();
}