//
// Created by Antonio Costache on 18/01/26.
//

#include "gtest/gtest.h"
#include "../FileLoader.h"

class FileLoaderTest : public ::testing::Test {
protected:
    void SetUp() override {
        testFileName = "testFile.txt";
        std::ofstream myFile(testFileName);
        myFile << "This file has 27 characters";
        myFile.close();
        fileLoader = new FileLoader(testFileName);
    }
    void TearDown() override {
        delete fileLoader;
        std::remove(testFileName.c_str());
    }
    std::string testFileName;
    FileLoader* fileLoader;
};

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