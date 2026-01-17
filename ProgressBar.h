//
// Created by Antonio Costache on 17/01/26.
//

#ifndef PROGRESSBAR_PROGRESSBAR_H
#define PROGRESSBAR_PROGRESSBAR_H
#include <QProgressBar>

class ProgressBar: public QObject {
    Q_OBJECT
public:
    explicit ProgressBar(int length, QWidget* window);

    QProgressBar* getQProgressBar();

private:
    QProgressBar* progressBar;


};


#endif //PROGRESSBAR_PROGRESSBAR_H