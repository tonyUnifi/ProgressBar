//
// Created by Antonio Costache on 18/01/26.
//

#ifndef PROGRESSBAR_FILELOADERQT_H
#define PROGRESSBAR_FILELOADERQT_H
#include <QObject>
#include "FileLoader.h"

class FileLoaderQt: public QObject, public FileLoader {
    Q_OBJECT
public:
    explicit FileLoaderQt(std::string fileName);

public slots:
    void startLoadingFile();
};


#endif //PROGRESSBAR_FILELOADERQT_H