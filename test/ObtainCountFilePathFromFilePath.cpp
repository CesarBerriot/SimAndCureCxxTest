//
// Created by César B. on 5/1/2024.
//

#include <gtest/gtest.h>
#include "Logic/Logic.hpp"

TEST(ObtainCountFilePathFromFilePathTest, CorrectCase)
{	std::string filePath = "path/to/file.txt";
	std::string countFilePath = Logic::ObtainCountFilePathFromFilePath(filePath);
	ASSERT_EQ(countFilePath.compare("path/to/file.count.txt"), 0);
}