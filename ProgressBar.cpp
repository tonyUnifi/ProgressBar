//
// Created by Antonio Costache on 17/01/26.
//

#include "ProgressBar.h"
#include <QApplication>

ProgressBar::ProgressBar(QWidget* window, FileLoader* fileLoader) {
    subjectLoader = fileLoader;
    subjectLoader -> subscribe(this);
    progressBar = new QProgressBar(window);
    progressBar -> setRange(0, fileLoader -> getTotalSteps());
    progressBar -> setValue(0);
}

ProgressBar::~ProgressBar() {
    subjectLoader -> unsubscribe(this);
}

QProgressBar* ProgressBar::getQProgressBar() {
    return progressBar;
}

void ProgressBar::update() {
    int currentValue = progressBar -> value();
    progressBar -> setValue(currentValue + 1);
    QApplication::processEvents();
}