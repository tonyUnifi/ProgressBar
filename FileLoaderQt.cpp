//
// Created by Antonio Costache on 18/01/26.
//

#include "FileLoaderQt.h"

FileLoaderQt::FileLoaderQt(std::string fileName): FileLoader(fileName) {}

void FileLoaderQt::startLoadingFile() {
    loadFile();
}