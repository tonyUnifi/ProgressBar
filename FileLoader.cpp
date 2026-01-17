//
// Created by Antonio Costache on 17/01/26.
//

#include "FileLoader.h"

FileLoader::FileLoader(std::string fileName): fileName(fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        throw std::runtime_error("Can't open the file!");
    }
    file.seekg(0, file.end);
    totalSteps = file.tellg();
    currentSteps = 0;
    file.close();
}

int FileLoader::getCurrentSteps() const {
    return currentSteps;
}

int FileLoader::getTotalSteps() const {
    return totalSteps;
}

void FileLoader::loadFile() {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        throw std::runtime_error("Can't open the file!");
    }
    char c;
    while (file.get(c)) {
        fileContent += c;
        currentSteps++;
    }
    file.close();
}

std::string FileLoader::getFileContent() const {
    return fileContent;
}