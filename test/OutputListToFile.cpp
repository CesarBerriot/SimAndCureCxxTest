//
// Created by César B. on 5/1/2024.
//

#include <gtest/gtest.h>
#include <fstream>
#include "DataTypes/DataTypes.hpp"
#include "Logic/Logic.hpp"
#include "Macros/Macros.hpp"

TEST(OutputListToFileTest, InvalidPath)
{	ASSERT_EXIT(Logic::OutputListToFile("/invalid/file/path.txt", {}), testing::ExitedWithCode(EXIT_FAILURE), "");
}

TEST(OutputListToFileTest, CorrectCase)
{	// constants
	std::string filePath = "OutputListToFileTestFile.txt";
	DataTypes::EvaluatedWords_t words = { { L"chien", 23 }, { L"pelouse", 42 }, { L"voiture", 158 } };
	std::wstring expectedOutput = L"chien, 23\npelouse, 42\nvoiture, 158\n";

	// call OutputListToFile()
	Logic::OutputListToFile(filePath, words);

	// open the output file for reading
	std::wifstream stream(filePath);
	ASSERT_TRUE(stream.is_open()) << "failed to open the output file for reading";

	// read its contents into a wstring
	std::wstring fileContents = MAKE_WSTRING(stream.rdbuf());

	// compare to the expected output
	ASSERT_EQ(fileContents.compare(expectedOutput), 0) << "the output file's contents didn't match the expected output";
}

