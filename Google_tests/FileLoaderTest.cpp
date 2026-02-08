//
// Created by Antonio Costache on 18/01/26.
//

#include "gtest/gtest.h"
#include "../FileLoader.h"
#include "../Observer.h"

class MockProgressBar : public Observer {
public:
    explicit MockProgressBar(int totalSteps): value(0), maximum(totalSteps) {}

    void update() override {
        value++;
    }

    int getValue() const {
        return value;
    }

    int getMaximum() const {
        return maximum;
    }
private:
    int value;
    int maximum;
};

class FileLoaderTest : public ::testing::Test {
protected:
    void SetUp() override {
        testFileName = "testFile.txt";
        std::ofstream myFile(testFileName);
        myFile << "This file has 27 characters";
        myFile.close();
        fileLoader = new FileLoader(testFileName);
        progressBar = new MockProgressBar(fileLoader -> getTotalSteps());
    }
    void TearDown() override {
        delete fileLoader;
        std::remove(testFileName.c_str());
        delete progressBar;
    }
    std::string testFileName;
    FileLoader* fileLoader;
    MockProgressBar* progressBar;
};

//FileLoader test
TEST_F(FileLoaderTest, correctInit) {
    ASSERT_EQ(0, fileLoader->getCurrentSteps());
}

TEST_F(FileLoaderTest, correctCurrentStepsValue) {
    fileLoader -> loadFile();
    ASSERT_EQ(27, fileLoader->getCurrentSteps());
}

TEST_F(FileLoaderTest, correctFileSize) {
    ASSERT_EQ(27, fileLoader->getTotalSteps());
}

TEST_F(FileLoaderTest, correctLoading) {
    fileLoader -> loadFile();
    ASSERT_EQ("This file has 27 characters", fileLoader->getFileContent());
}

//Pattern observer test
TEST_F(FileLoaderTest, correctUpdateAfterSubscribe) {
    fileLoader -> subscribe(progressBar);
    fileLoader -> loadFile();
    ASSERT_EQ(progressBar -> getValue(), fileLoader->getTotalSteps());
}

TEST_F(FileLoaderTest, correctUnsubscribe) {
    fileLoader -> subscribe(progressBar);
    fileLoader -> unsubscribe(progressBar);
    fileLoader -> loadFile();
    ASSERT_EQ(progressBar -> getValue(), 0);
}