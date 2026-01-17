//
// Created by Antonio Costache on 17/01/26.
//

#include "ProgressBar.h"

ProgressBar::ProgressBar(int length, QWidget* window) {
    progressBar = new QProgressBar(window);
    progressBar -> setRange(0, length);
    progressBar -> setValue(0);
}

QProgressBar* ProgressBar::getQProgressBar() {
    return progressBar;
}