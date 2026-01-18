//
// Created by Antonio Costache on 17/01/26.
//

#include <string>
#include <fstream>
#include <QObject>

#include "Observer.h"
#include "Subject.h"
#ifndef PROGRESSBAR_FILELOADER_H
#define PROGRESSBAR_FILELOADER_H


class FileLoader: public QObject, public Subject {
    Q_OBJECT
public:
    explicit FileLoader(std::string fileName);

    int getCurrentSteps() const;

    int getTotalSteps() const;

    std::string getFileContent() const;

    void subscribe(Observer* observer) override;

    void unsubscribe(Observer *observer) override;

    void notify() override;
public slots:
    void loadFile();
private:
    std::string fileName;
    int currentSteps;
    int totalSteps;
    std::string fileContent;
};


#endif //PROGRESSBAR_FILELOADER_H