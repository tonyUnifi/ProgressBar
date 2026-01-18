//
// Created by Antonio Costache on 17/01/26.
//

#ifndef PROGRESSBAR_PROGRESSBAR_H
#define PROGRESSBAR_PROGRESSBAR_H
#include <QProgressBar>
#include "Observer.h"
#include "FileLoader.h"

class ProgressBar: public QObject, public Observer {
    Q_OBJECT
public:
    explicit ProgressBar(QWidget* window, FileLoader* subjectLoader);

    ~ProgressBar();

    QProgressBar* getQProgressBar();

    void update() override;
private:
    QProgressBar* progressBar;
    Subject* subjectLoader;
};


#endif //PROGRESSBAR_PROGRESSBAR_H