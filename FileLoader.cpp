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
        notify();
    }
    file.close();
}

std::string FileLoader::getFileContent() const {
    return fileContent;
}

void FileLoader::subscribe(Observer* observer) {
    observers.push_back(observer);
}

void FileLoader::unsubscribe(Observer *observer) {
    observers.remove(observer);
}

void FileLoader::notify() {
    for (auto observer : observers) {
        observer -> update();
    }
}