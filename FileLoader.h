//
// Created by Antonio Costache on 17/01/26.
//

#include <string>
#include <fstream>

#include "Observer.h"
#include "Subject.h"
#ifndef PROGRESSBAR_FILELOADER_H
#define PROGRESSBAR_FILELOADER_H

class FileLoader: public Subject {
public:
    explicit FileLoader(std::string fileName);

    int getCurrentSteps() const;

    int getTotalSteps() const;

    std::string getFileContent() const;

    void subscribe(Observer* observer) override;

    void unsubscribe(Observer *observer) override;

    void notify() override;

    void loadFile();
private:
    std::string fileName;
    int currentSteps;
    int totalSteps;
    std::string fileContent;
};


#endif //PROGRESSBAR_FILELOADER_H