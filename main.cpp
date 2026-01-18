#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include "FileLoader.h"
#include "ProgressBar.h"

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    //window config
    QWidget window;
    window.setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    window.setWindowTitle("ProgressBar");

    //layout
    QVBoxLayout* layout = new QVBoxLayout(&window);

    //fileloader
    FileLoader* fileLoader = nullptr;
    try {
        fileLoader = new FileLoader("myFile.txt");
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    //progress bar
    ProgressBar progressBar(&window, fileLoader, fileLoader -> getTotalSteps());
    layout -> addWidget(progressBar.getQProgressBar());

    //button config
    QPushButton* button = new QPushButton("Start");
    button->setFixedSize(100, 50);
    layout -> addWidget(button, 0, Qt::AlignHCenter);

    //connection between start button and loadFile()
    QObject::connect(button, &QPushButton::clicked,
                 fileLoader, &FileLoader::loadFile);

    window.show();

    return QApplication::exec();
}