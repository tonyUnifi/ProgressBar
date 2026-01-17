//
// Created by Antonio Costache on 17/01/26.
//

#include <string>
#include <fstream>
#ifndef PROGRESSBAR_FILELOADER_H
#define PROGRESSBAR_FILELOADER_H


class FileLoader {
public:
    explicit FileLoader(std::string fileName);

    int getCurrentSteps() const;

    int getTotalSteps() const;

    void loadFile();

    std::string getFileContent() const;
private:
    std::string fileName;
    int currentSteps;
    int totalSteps;
    std::string fileContent;
};


#endif //PROGRESSBAR_FILELOADER_H