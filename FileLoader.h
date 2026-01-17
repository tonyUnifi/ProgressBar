//
// Created by Antonio Costache on 17/01/26.
//

#include <string>
#include <fstream>
#ifndef PROGRESSBAR_FILELOADER_H
#define PROGRESSBAR_FILELOADER_H


class FileLoader {
public:
    FileLoader(std::string fileName);

    int getCurrentSteps() const;

    int getTotalSteps() const;

private:
    std::string fileName;
    int currentSteps;
    int totalSteps;
};


#endif //PROGRESSBAR_FILELOADER_H